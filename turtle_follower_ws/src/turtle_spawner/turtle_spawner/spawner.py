import rclpy
from rclpy.node import Node
from random import randint

from turtle_interfaces.msg import TurtlesAlive
from turtle_interfaces.msg import TurtlePosition
from turtle_interfaces.srv import Catch

from turtlesim.srv import Spawn
from turtlesim.srv import Kill

class SpawnerNode(Node):
    def __init__(self):
        super().__init__('spawner_node')

        # Kill Client
        self.kill_client = self.create_client(Kill, 'kill')
        while not self.kill_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('kill service not available, waiting again...')
        self.get_logger().info('Kill service available')

        # Spawn Client
        self.spawn_client = self.create_client(Spawn, 'spawn')
        while not self.spawn_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Spawn service not available, waiting again...')
        self.get_logger().info('Spawn service available')
        self.spawn_watchdog = self.create_timer(0.5, self.spawn_turtle)

        # Turtles Alive Publisher
        self.turtles_alive_publisher = self.create_publisher(TurtlesAlive, 'turtles_alive', 10)
        self.turtles_alive = TurtlesAlive()

        # Catch Service
        self.catch_service = self.create_service(Catch, 'catch', self.catch_callback)

        self.get_logger().info('Spawner Node has been started')

    def spawn_turtle(self):

        while len(self.turtles_alive.turtles) <= 10:
            turtle = TurtlePosition()
            turtle.x = float(randint(1, 10))
            turtle.y = float(randint(1, 10))
            turtle.theta = 0.0
            turtle.name = 'turtle' + str(len(self.turtles_alive.turtles)+1)
            self.turtles_alive.turtles.append(turtle)
            request = Spawn.Request()
            request.x = turtle.x
            request.y = turtle.y
            request.theta = turtle.theta
            request.name = turtle.name
            future = self.spawn_client.call_async(request)
            future.add_done_callback(self.spawn_callback)
        
        self.turtles_alive_publisher.publish(self.turtles_alive)

    def spawn_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f'Turtle Spawned: {response}')
        except Exception as e:
            self.get_logger().info(f'Service call failed {e}')

    def catch_callback(self, request, response):
        # When the own position is not the same as the catch turtle position
        if not(request.own_turtle.x == request.catch_turtle.x and \
        request.own_turtle.y == request.catch_turtle.y):
            self.get_logger().debug(f'{request.catch_turtle.name} was not caught :( !')
            response.result = False
            return response
        
        # When the own position is the same as the catch turtle position
        for turtle in self.turtles_alive.turtles:
            if turtle.name == request.catch_turtle.name:
                self.turtles_alive.turtles.remove(turtle)
                self.get_logger().debug(f'{request.catch_turtle.name} has been caught')
                response.result = True
                request = Kill.Request()
                request.name = request.catch_turtle.name
                future = self.kill_client.call_async(request)
                future.add_done_callback(self.kill_callback)
                break
            else:
                response.result = False
        return response

    def kill_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f'Turtle Killed: {response.name}')
        except Exception as e:
            self.get_logger().info(f'Service call failed {e}')

def main(args=None):
    rclpy.init(args=args)
    node = SpawnerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()