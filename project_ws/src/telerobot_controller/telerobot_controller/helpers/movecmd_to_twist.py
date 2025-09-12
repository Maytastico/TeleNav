from telerobot_controller.types.move_cmd_enum import MoveCmdEnum
from telerobot_interfaces.msg import MoveCmd

from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3 as Vec

def move_cmd_to_twist(move_cmd: MoveCmd) -> Twist:
    """Generates a Twist message based on the MoveCmd input.

    Args:
        move_cmd (MoveCmd): The MoveCmd message to convert. Expects move_cmd.x and move_cmd.y in [-100, 100].

    Returns:
        Twist: The corresponding Twist message.
    """
    twist = Twist()

    # Normalize input values to [-1, 1]
    x_norm = move_cmd.joy_x / 200.0
    y_norm = move_cmd.joy_y / 100.0
    print(f"Normalized joy_x: {x_norm}, joy_y: {y_norm}")
    # Linear speed: proportional to x (forward/backward)
    twist.linear = Vec(x=y_norm, y=0.0, z=0.0)

    # Angular speed: proportional to y (left/right), but reduce angular speed as x increases
    # At x=0 (standing), full turn; at x=1 (full speed), less turn
    # Example: angular = y_norm * (1 - abs(x_norm))
    twist.angular = Vec(x=0.0, y=0.0, z=-1.0 * x_norm)

    print(f"Converted MoveCmd joy_x={move_cmd.joy_x}, joy_y={move_cmd.joy_y} to Twist: linear=({twist.linear.x}, {twist.linear.y}, {twist.linear.z}), angular=({twist.angular.x}, {twist.angular.y}, {twist.angular.z})")
    return twist
