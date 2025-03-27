import rclpy
from rclpy.node import Node

from my_robot_interfaces.srv import ComputeRectangleArea

class ComputeRectangleService(Node):
    def __init__(self):
        super().__init__('compute_rectangle_service')
        self.srv = self.create_service(ComputeRectangleArea, 'compute_rectangle_area', self.callback_compute_rectangle_area)
        self.get_logger().info('Compute Rectangle Area Service has been started.')

    def callback_compute_rectangle_area(self, request, response):
        response.area = request.lenght * request.width
        self.get_logger().info('Incoming request\nwidth: %f height: %f' % (request.lenght, request.width))
        self.get_logger().info('Sending back response: [%f]' % response.area)
        return response
    
def main(args=None):
    rclpy.init(args=args)
    node = ComputeRectangleService()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()