from rclpy.node import Node
from telerobot_controller.types.move_cmd_enum import MoveCmdEnum
from telerobot_interfaces.msg import MoveCmd

class MoveCmdPublisher(Node):
    def __init__(self):
        super().__init__('move_cmd_publisher')
        self.publisher_ = self.create_publisher(MoveCmd, 'move_cmd', 10)

    def publish_move_cmd(self, joy_x: int, joy_y: int, cmd: MoveCmdEnum):
        msg = MoveCmd()
        msg.joy_x = joy_x
        msg.joy_y = joy_y
        msg.cmd = cmd.value
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: joy_x={joy_x}, joy_y={joy_y}, cmd={cmd}')