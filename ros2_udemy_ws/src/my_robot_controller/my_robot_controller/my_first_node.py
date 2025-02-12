#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        # Calling the init function for the node
        super().__init__("my_node")
        self.counter_ = 0
        period_between_call = 0.5
        self.create_timer(period_between_call, callback=self.time_callback)

    def time_callback(self):
        self.get_logger().info("Hello " + str(self.counter_))
        self.counter_ += 1

def main(args=None):
    
    # Starts the ROS 2 node and communicatio
    # Whitout this line, the node will not be able to communicate with the ROS 2 ecosystem
    # and the program will fail
    rclpy.init(args=args)


    # Create a ROS 2 node
    node = MyNode()

    # This will keep the node running until 
    # it is manually stopped
    # These callback will be executed in a loop
    # trough the spin function
    rclpy.spin(node)

    # Shuts down the ROS 2 node
    rclpy.shutdown()

if __name__ == 'main':
    main()