import rclpy
from rclpy.node import Node

from example_interfaces.srv import SetBool
from example_interfaces.msg import Int64

class NumberCounterNode(Node):
    def __init__(self):
        super().__init__('number_counter')
        self.publisher = self.create_publisher(Int64, 'number_count', 10)
        self.server = self.create_service(SetBool, 'reset_counter', self.callback_reset_counter)
        self.get_logger().info('Set Bool Server has been started.')
        self.timers_ = self.create_timer(1, self.callback_number_counter)
        self.counter = 0
        self.bool_value = False

    def callback_number_counter(self):
        
        if self.bool_value:
            self.counter = 0

        self.counter += 1
        msg = Int64()
        msg.data = self.counter
        self.publisher.publish(msg)
        self.get_logger().info(f'Counter: {self.counter}')

    def callback_reset_counter(self, request, response):
        self.bool_value = request.data
        response.success = True
        return response
    
def main(args=None):
    rclpy.init(args=args)
    node = NumberCounterNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    