# TeleNav
Repository for the seminar project 'TeleNav': Advanced navigation software for telepresence robots, enabling seamless remote participation and control.

# Create a new Package

To create a new python ros2 package you can type:
```bash
ros2 pkg create --build-type ament_python first_package
```

# Setup
Run ``setup_packages.sh`` for setting up the environment

Before running source the setup.bash.
```bash
source ./install/setup.bash
```

To build the program run:
```bash
colcon build
```

# Run
When running the first time it recommended to check for dependencies.
For this run following command:
```bash
rosdep install -i --from-path src  --rosdistro iron -y
```

Now you can run your new package
Run:
```bash
colcon build --packages-select first_package
```

# Notes

## Topics

To see all the topics that are currently running you can run:
```bash
ros2 topic list
```

To see the messages that are being published on a topic you can run:
```bash
ros2 topic echo /topic_name
```

To send messages to a topic you can run:
The topictype is ussauly std_msgs/msg/String
```bash
ros2 topic pub /topic_name topic_type "message"
```

To get more information about a topic you can run:
```bash
ros2 topic info /topic_name --verbose
```

## Create a package with urdf files
This explaines how to create a package with urdf files.
urdf is used to describe the geometry of the robot model.
```bash
mkdir launch urdf
```

* Add you urdf model to urdf_test/urdf/model.urdf
* create a launch file in launch folder with following content:
```python
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
```
* To launch build the repository and run:
```bash
ros2 launch urdf_test display.launch.py
```