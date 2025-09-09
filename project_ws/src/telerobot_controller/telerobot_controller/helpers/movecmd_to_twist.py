from telerobot_controller.types.move_cmd_enum import MoveCmdEnum
from telerobot_interfaces.msg import MoveCmd

from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3 as Vec

def move_cmd_to_twist(move_cmd: MoveCmd) -> Twist:
    """Generates a Twist message based on the MoveCmd input.

    Args:
        move_cmd (MoveCmd): The MoveCmd message to convert.

    Returns:
        Twist: The corresponding Twist message.
"""
    twist = Twist()
    if move_cmd.cmd == MoveCmdEnum.STOP.value:
        twist.linear = Vec(x=0.0, y=0.0, z=0.0)
        twist.angular = Vec(x=0.0, y=0.0, z=0.0)
    elif move_cmd.cmd == MoveCmdEnum.FORWARD.value:
        twist.linear = Vec(x=1.0, y=0.0, z=0.0)
        twist.angular = Vec(x=0.0, y=0.0, z=0.0)
    elif move_cmd.cmd == MoveCmdEnum.BACKWARD.value:
        twist.linear = Vec(x=-1.0, y=0.0, z=0.0)
        twist.angular = Vec(x=0.0, y=0.0, z=0.0)
    elif move_cmd.cmd == MoveCmdEnum.TURN_LEFT.value:
        twist.linear = Vec(x=0.0, y=0.0, z=0.0)
        twist.angular = Vec(x=0.0, y=0.0, z=1.0)
    elif move_cmd.cmd == MoveCmdEnum.TURN_RIGHT.value:
        twist.linear = Vec(x=0.0, y=0.0, z=0.0)
        twist.angular = Vec(x=0.0, y=0.0, z=-1.0)
    print(f"Converted MoveCmd {move_cmd.cmd} to Twist: linear=({twist.linear.x}, {twist.linear.y}, {twist.linear.z}), angular=({twist.angular.x}, {twist.angular.y}, {twist.angular.z})")
    return twist