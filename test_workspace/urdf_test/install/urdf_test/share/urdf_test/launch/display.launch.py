import launch
from launch.substitutions import Command, LaunchConfiguration
import launch_ros
import os

def generate_launch_description():
    # This automatically finds the path to the urdf package
    pkgPath = launch_ros.substitutions.FindPackageShare(package='urdf_test').find('urdf_test')

    # This is the path to the urdf model
    urdfModelPath = os.path.join(pkgPath, 'urdf', 'robot.urdf')

    with open(urdfModelPath, 'r') as infp:
        robotDescription = infp.read()

    params = {'robot_description': robotDescription}

    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params]
    )
    
    joint_state_publisher_node = launch_ros.actions.Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        output='screen',
        parameters=[params],
        condition=launch.conditions.UnlessCondition(LaunchConfiguration('gui'))
    )

    joint_state_publisher_gui_node = launch_ros.actions.Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        condition=launch.conditions.IfCondition(LaunchConfiguration('gui'))
    )

    rviz_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
    )

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'gui',
            default_value='True',
            description='This is a flag for the joint_state_publisher_gui'
        ),
        launch.actions.DeclareLaunchArgument(
            name='model',
            default_value=urdfModelPath,
            description='Path to the urdf model file'
        ),
        robot_state_publisher_node,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node
    ])