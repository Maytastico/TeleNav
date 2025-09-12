import rclpy, math
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from telerobot_interfaces.msg import MoveCmd
from telerobot_controller.types.messurement import Measurements
from telerobot_controller.helpers.movecmd_to_twist import move_cmd_to_twist

class DistanceReader(Node):
    """
    Ein ROS2-Node, der Distanzmessungen von Lidar-Sensoren abonniert und ausgibt.
    """
    def __init__(self):
        super().__init__('distance_reader')

        self.measurements = Measurements()

        self.front_subscription = self.create_subscription(
            LaserScan,
            '/distance_front/out',
            self.front_callback,
            10
        )
        # self.lower_subscription = self.create_subscription(
        #     LaserScan,
        #     '/distance_lower/out',
        #     self.lower_callback,
        #     10
        # )
        # self.back_subscription = self.create_subscription(
        #     LaserScan,
        #     '/distance_back/out',
        #     self.back_callback,
        #     10
        # )


        self.get_logger().info('New DistanceReader-Node gestartet.')

    def front_callback(self, msg: LaserScan):
            """
            Callback-Funktion für den vorderen Lidar-Sensor.
            Hier wird geprüft, ob die gelesene Distanz gültig ist.
            """
            # Check for NaN or infinite values before processing
            self.get_logger().warn(f'Vordere Distanz aktualisiert: {self.measurements.front_distance} m')
            if not math.isnan(msg.ranges[0]) and not math.isinf(msg.ranges[0]):
                # self.get_logger().info(f'Vordere Distanz: {msg.range} m') # Uncomment if you want to log valid distances
                self.measurements.front_distance = msg.ranges[0]
            else:
                self.get_logger().warn(f'Ungültiger Distanzwert empfangen: {msg.ranges[0]}. Nachricht wird ignoriert.')

    # def lower_callback(self,  msg: LaserScan):
    #     """
    #     Callback-Funktion für den unteren Lidar-Sensor.
    #     """
    #     self.get_logger().info(f'Untere Distanz: {msg.ranges[0]} m')
    #     #self.measurements.lower_distance = msg.ranges[0]

    # def back_callback(self,  msg: LaserScan):
    #     """
    #     Callback-Funktion für den hinteren Lidar-Sensor.
    #     """
    #     self.get_logger().info(f'Hintere Distanz: {msg.ranges[0]} m')
    #     #self.measurements.back_distance = msg.ranges[0]


class MoveCoordinator(Node):

    def __init__(self):
        super().__init__('move_coordinator')

        self.move_cmd_subscription = self.create_subscription(
            MoveCmd,
            'move_cmd',
            self.move_cmd_callback,
            10
        )

        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10)

        self.get_logger().info('New MoveCoordinator-Node gestartet.')

    def move_cmd_callback(self, msg: MoveCmd):
        """
        Callback-Funktion für empfangene MoveCmd-Nachrichten.
        """
        self.get_logger().info(f'MoveCmd empfangen: {msg}')
        self.cmd_vel_publisher.publish(move_cmd_to_twist(msg))

def main(args=None):
    rclpy.init(args=args)
    distance_reader = DistanceReader()
    move_coordinator = MoveCoordinator()
    executor = MultiThreadedExecutor()
    executor.add_node(distance_reader)
    executor.add_node(move_coordinator)
    try:
        executor.spin()
    finally:
        distance_reader.destroy_node()
        move_coordinator.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()