import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class ParameterPublisherNode(Node):
    def __init__(self):
        super().__init__('parameter_publisher_node')
        self.declare_parameter("number", 2)
        self.declare_parameter("timer_period", 1.0)
        self.number_ = self.get_parameter("number").value
        self.timer_period_ = self.get_parameter("timer_period").value
        self.publisher = self.create_publisher(Int64, "number", 10)
        self.timer = self.create_timer(self.timer_period_, self.publish_number)
        self.get_logger().info("Parameter Publisher Node has been started")

    def publish_number(self):
        msg = Int64()
        msg.data = self.number_
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = ParameterPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()