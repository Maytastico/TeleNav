from rclpy.node import Node
from telerobot_controller.types.move_cmd_enum import MoveCmdEnum
from telerobot_interfaces.msg import MoveCmd

class MoveCmdPublisher(Node):
    def __init__(self):
        super().__init__('move_cmd_publisher')
        self.publisher_ = self.create_publisher(MoveCmd, 'move_cmd', 10)

    def publish_move_cmd(self, move_cmd: MoveCmd):
        msg = MoveCmd()
        msg.joy_x = move_cmd.joy_x
        msg.joy_y = move_cmd.joy_y
        msg.cmd = move_cmd.cmd
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: joy_x={move_cmd.joy_x}, joy_y={move_cmd.joy_y}, cmd={move_cmd.cmd}')