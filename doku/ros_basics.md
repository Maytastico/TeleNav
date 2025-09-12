# ros basics
Repository for the seminar project 'TeleNav': Advanced navigation software for telepresence robots, enabling seamless remote participation and control.



# Setup

1. Run ``setup_packages.sh`` for setting up the environment

2. Add ``source /opt/ros/humble/setup.bash`` to **~/.bashrc**

3. To enable autocompletion add ``source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash`` to **~/.bashrc**

Before running source the setup.bash.
```bash
source ./install/setup.bash
```

To build the program run:
```bash
colcon build
```

To install the symlink so you can modify your files.
When adding new files the installed symlink will not work.
```bash
colcon build --symlink-install
```

For setting up cpp for vs code you need
to edit **c/c++: Edit Configuration**
Add 
```JSON
"includePath": [
    "${workspaceFolder}/**",
    "/opt/ros/humble/include/**"
],
```

Change this so that it works with your project and add it to your cmakelist.txt
```cmake
find_package(rclcpp REQUIRED)
add_executable(<node_name> src/<node_file_name>.cpp)
ament_target_dependencies(<node_file_name> rclcpp)
install(TARGETS
  <node_file_name>
  DESTINATION lib/${PROJECT_NAME}
)
```
## Create a new Package
After setting up your workspace you are able to create a new package.
For that go into your **/src** folder and run:

* rclpy is a library used almost everywhere in ros so adding as dependency is completly fine

```bash
ros2 pkg create --build-type ament_python first_package --dependencies rclpy
```

## Adding a new script

To run a script trough the ros2 ecosystem you need
to add the script to the **setup.py** file.

An entry can look like this:
The first name is the name registered when initializing the Node.

```python
entry_points={
    'console_scripts': [
        "py_node = my_robot_controller.my_first_node:main",
    ],
},
```

## Python node template

```python
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        # Calling the init function for the node
        super().__init__("my_node")
        self.get_logger().info("Hello ROS 2")

def main(args=None):
    
    # Starts the ROS 2 node and communicatio
    # Whitout this line, the node will not be able to communicate with the ROS 2 ecosystem
    # and the program will fail
    rclpy.init(args=args)


    # Create a ROS 2 node
    node = MyNode()

    # This will keep the node running until 
    # it is manually stopped
    # These callback will be executed in a loop
    # trough the spin function
    rclpy.spin(node)

    # Shuts down the ROS 2 node
    rclpy.shutdown()

if __name__ == 'main':
    main()
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
To run your package
```bash
ros2 run <package_name> <application_name>
```
# Notes

## Usage of Namespace

When running several nodes esspacialy when running them inside launch files there could 
be the problem that the name could conflict.
With namespace several scripts can be run without remapping the names

```bash
 ros2 run my_robot_controller hw_status_publisher --ros-args -r __ns:=/test
```

## Define Parameters and execute a script with parameters

Parameter können mit folgenden Befehlen in ein belibiges Projekt hinzugeführt werden
```python
self.declare_parameter("number", 2)
self.declare_parameter("timer_period", 1.0)
self.number_ = self.get_parameter("number").value
self.timer_period_ = self.get_parameter("timer_period").value
self.publisher = self.create_publisher(Int64, "number", 10)
```

Um die Parameter aufzurufen kann folgendes Argument hinzugefügt werden
```bash
ros2 run <package> <skript> --ros-args -p number:=3 -p timer_period:=0.5
```

I case of using many parameters you can use files to configure them into
the file
```yml
/parameter_publisher_node:
  ros__parameters:
    number: 5
    timer_period: 1.7
```

To Execute the file you can enter:

``ros2 run my_robot_controller parameter_publisher --ros-args --params-file ros_params.yml``

## Launchfile

For all Launchfile a new project has to be created
then src and include as to be deleted.
With added the launch directory.
Afterwards following lines need to be added so all the
files inside the launch directory will be installed

```cmake
install{DIRECTORY 
  launch
  DESTINATION share/${PROJECT_NAME}/
}
```

After adding the project to your package and building it
you can run the lauchfile via
```bash
ros2 launch my_robot_bringup number_app.launch.xml
```
To add a package the launchfile should start you can add it to your xml file
```xml
<launch>
    <node pkg="my_robot_controller" exec="led_panel_node"/>
    <node pkg="my_robot_controller" exec="battery_node"/>
</launch>

```

### Remap node

So when you want to run a node on another node you can add this to your launch file

```xml
<launch>
    <node pkg="<pkg>" name="<name>">
        <remap from="/number" to="/my_number"/>
    </node>
</launch>
```

### Parameters
When adding Parameter there is a tag that can be add
```xml
<launch>
    <node pkg="<pkg>" name="<name>">
        <remap from="/number" to="/my_number"/>
        <param name="number" value="6"/>
    </node>
</launch>
```

To add params trough a yml file. you can create a folder where you add your configs
inside this folder you add the same yml files you would create to use parameters in the terminal

```xml
<launch>
    <node pkg="<pkg>" name="<name>">
        <remap from="/number" to="/my_number">
        <param from="$(find-pkg-share my_robot_bringup)/config/<yml_file>.yml"/>
    </node>
</launch>
```

### Namespaces

To run an application in an namespace an attriute ``namespace`` can be add.
It is important to not add the `/` to the remap. Remapping is optional.

```xml
<launch>
    <node pkg="<pkg>" name="<name>" namespace="/test">
        <remap from="number" to="my_number"/>
        <param name="number" value="6"/>
    </node>
</launch>
```

### Including another lauchfile
For include another launchfile you can add following line to your launch file

```xml
<include file="$(find-pkg-share gazebo_ros)/launch/gazebo.launch.py"/>
```

Every launch file can be found in the directory /launch
By running find-pkg-share we get the path of the respective package

## Running a program in a namespace
## ROS2 CLI

To see all running nodes
* ``ros2 node list``
* ``ros2 node info /<node_name>``
 
## Running two seperate nodes
When running two seperate nodes the name will be the same so to run one node in parallel
you can remapp it with this command.

```bash
ros2 run <package> <script> --ros-args -r __node:=<name>
```

## Colcon tricks

Building only specific packages
```bash
colcon build --packages-select <package_name>
```

Symlink installing a package to build everytime is is runc over ros2 run.
It works only with python!
```bash
colcon build --packages-select <package_name> --symlink-install
```
## Topics

There are several arguments you can add to get more info:
* **bw** - Bamdbreite eines Channels
* **hz** - Fequenz eines Channels
* **echo** - Ausgabe was im Channel übertragen wird
With `ros2 interface`you can gather info about an interface definition
```bash
ros2 interface show esample_interfaces/msg/String
```

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
## Services

To list all the services enter
```bash
ros2 service list
```

To call a specific service you need to call it over.
Interface types can be found in `example_interface`.
```bash
ros2 service call /<service_path> <interface> "{example: "data"}"
```
## Create a interface package

Use the ros2 pkg comand to create a simple cpp package.
Delete `src` and `include` afterwards.
Add following lines to `package.xml` under **buildtool_depend**
```bash
<build_depend>rosidl_default_runtime</build_depend>
<build_depend>rosidl_default_generators</build_depend>
<member_of_group>rosidl_interface_packages</member_of_group>
```

Then add this to your **CMakeLists.xml**
Add this under **find_package(ament_cmake REQUIRED)**
Depending on your message definition add the files to rosidl_generate_interfaces
```cmake
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
    "msg/HardwareStatus.msg"
)
ament_export_dependencies(rosidl_default_runtime)
```

When using your new interface it is important to use the packagename
from the package you created
e.q from my_robot_interface.msg import HardwareMessages

When the package is not present add the path of the installfolder of the package to your
**setting.json** 
e.q 
```json
    "python.autoComplete.extraPath":{
        "path to python path"
    }
```

NOTE: When the interface is still not recignized open the project via the sourced enviroment
(source install/setup.bash)

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

## Create a workspace

Create a folder where you project needs to be put in.
Then create a src folder inside.
Then by running `colcon build` all the nessesary folder and files are created.

# Install folders
When adding folders in one of your project different projects need access to you need to add 
the folder name to the `CMakeList.txt` file.

Example:
```make
install(
  DIRECTORY launch config new_foldername
  DESTINATION share/${PROJECT_NAME}/
)
``` 