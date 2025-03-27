import rclpy
from rclpy.node import Node
from random import randint

from my_robot_interfaces.srv import SetLed

class BatteryNode(Node):
    def __init__(self):
        super().__init__('battery_node')
        self.timer = self.create_timer(1, self.timer_callback)

    def timer_callback(self):
        client = self.create_client(SetLed, "set_led")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server to start...")

        request = SetLed.Request()
        request.led_number = randint(0, 3)
        request.led_state = randint(0, 1)
        future = client.call_async(request)
        future.add_done_callback(self.callback_call_set_led)

    def callback_call_set_led(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"Service call for LED Node returned {response.success}")
        except Exception as e:
            self.get_logger().error(f"Service call failed {e}")
            
def main(args=None):
    rclpy.init(args=args)
    node = BatteryNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()