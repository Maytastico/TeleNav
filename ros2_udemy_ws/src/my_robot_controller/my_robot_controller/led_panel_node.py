import rclpy 
from rclpy.node import Node

from my_robot_interfaces.srv import SetLed
from my_robot_interfaces.msg import LedState

class LedPanelNode(Node):
    def __init__(self):
        super().__init__('led_panel_node')
        self.service = self.create_service(SetLed, "set_led", self.callback_set_led)
        self.publisher = self.create_publisher(LedState, "led_panel_state", 10)
        self.leds = [0, 0, 0]
        self.timer = self.create_timer(1, self.publish_led_state)
        self.get_logger().info("LED Panel Node has been started")

    def callback_set_led(self, request, response):
        if request.led_number == 0:
            self.leds = [0,0,0]
        elif request.led_number == 1:
            self.leds = [0,0,1]
        elif request.led_number == 2:
            self.leds = [0,1,1]
        elif request.led_number == 3:
            self.leds = [1,1,1]
        else:
            response.success = False
            return response

        self.get_logger().info(f"Set LED {request.led_number} to {request.led_state}")
        response.success = True
        return response
    
    def publish_led_state(self):
        msg = LedState()
        msg.leds = self.leds
        sum = 0
        for x in self.leds:
            sum += x

        if sum > 0:
            msg.led_state = True
        else:   
            msg.led_state = False

        self.publisher.publish(msg)
     
def main(args=None):
    rclpy.init(args=args)
    node = LedPanelNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()