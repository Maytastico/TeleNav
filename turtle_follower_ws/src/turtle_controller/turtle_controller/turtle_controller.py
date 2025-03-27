import math
import rclpy
from rclpy.node import Node
from transitions import Machine

from turtle_interfaces.msg import TurtlesAlive
from turtle_interfaces.msg import TurtlePosition

from turtlesim.msg import Pose


class TurtleControllerNode(Node):
    def __init__(self):
        super().__init__("turtle_controller")

        # Own Turtle Data
        self.own_turtle_name = "turtle1"
        self.pose_subscriber = self.create_subscription(Pose, f"{self.own_turtle_name}/pose", self.pose_callback, 10)
        self.pose = Pose()

        # Active Turtle Data
        self.active_turtle_subscriber = self.create_subscription(TurtlesAlive, "turtles_alive", self.active_turtle_callback, 10)
        self.turtles_alive = TurtlesAlive()
        self.next_target = TurtlePosition()

        # State Machine
        self.states = ["idle", "driving", "catching"]
        self.transitions = [
            {"trigger": "drive", "source": "idle", "dest": "driving"},
            {"trigger": "catch", "source": "driving", "dest": "catching"},
            {"trigger": "drive", "source": "catching", "dest": "driving"}
        ]
        self.machine = Machine(model=self, states=self.states, transitions=self.transitions, initial="idle")

        self.get_logger().info("Turtle Controller Node has been started")

        # Driving
        self.drive_timer = self.create_timer(0.1, self.loop)


    def pose_callback(self, msg):
        self.pose = msg
        #self.get_logger().info(f"Received Pose: {self.pose.x}, {self.pose.y}, {self.pose.theta}")

    def active_turtle_callback(self, msg):
        self.turtles_alive = msg
        self.get_logger().debug(f"Received Active Turtle")

    def calculate_distance(self, turtle1: Pose, turtle2: TurtlePosition):
        return math.sqrt((turtle1.x - turtle2.x)**2 + (turtle1.y - turtle2.y)**2)

    def calculate_next_turtle(self):
        least_distance_turtle = TurtlePosition()
        least_distance = None
        for turtle in self.turtles_alive.turtles:
            calculated_distance = self.calculate_distance(self.pose, turtle)
            if least_distance == None:
                if least_distance < calculated_distance:
                    least_distance_turtle = turtle
                    least_distance = calculated_distance
        return least_distance_turtle
    
    def loop(self):
        self.next_target = self.calculate_next_turtle()
        if len(self.turtles_alive.turtles) > 0:
            self.next_target = self.calculate_next_turtle()
            if self.machine.get_state == "idle":
                self.drive()
                self.get_logger().info(f"Driving to {self.next_target.name}")

        if self.machine.get_state == "driving":
            if self.calculate_distance(self.pose, self.next_target) < 0.1:
                self.catch()
                self.get_logger().info(f"Catching {self.next_target.name}")
            self.get_logger().info(f"Driving to {self.next_target.name}")
    
def main():
    rclpy.init()
    node = TurtleControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()