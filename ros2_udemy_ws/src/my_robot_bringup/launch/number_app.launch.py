from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    battery_node = Node(
        package='my_robot_controller',
        executable="battery_node",
    )

    led_panel = Node(
        package='my_robot_controller',
        executable="led_panel_node",
    )

    ld.add_action(battery_node)
    ld.add_action(led_panel)    
    
    return ld