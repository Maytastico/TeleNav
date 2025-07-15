# Setup

For simulating robots you need following packages:

* ros-humble-ros-gz/jammy 0.244.20-1jammy.20250618.013536 amd64
  Meta-package containing interfaces for using ROS 2 with Gazebo simulation.

* ros-humble-ros-gz-bridge/jammy 0.244.20-1jammy.20250617.220534 amd64
  Bridge communication between ROS and Gazebo Transport


* ros-humble-ros-gz-image/jammy 0.244.20-1jammy.20250617.225438 amd64
  Image utilities for Gazebo simulation with ROS.

* ros-humble-ros-gz-interfaces/jammy 0.244.20-1jammy.20250617.204734 amd64
  Message and service data structures for interacting with Gazebo from ROS2.

* ros-humble-ros-gz-sim/jammy 0.244.20-1jammy.20250617.215546 amd64
  Tools for using Gazebo Sim simulation with ROS.

Just run `sudo apt install ros-humble-ros-gz`

For installing the nessesary plugins run:
`sudo  apt-get install ros-humble-gazebo-plugins`

# Gazebo Commands

Because for some reason my computer is using ign instead of gz this list will 
use commands with ign if they will not work use gz

* `ign topic -l`: Lists all topics
* `ign topic -i -t <topic_name>`: Explains the topi

To see the topics in ros2 you can use following command:
* `ros2 topic list`

# Configuration

## Model modification
Add a file `mobile_base_gazebo.xacro` to your urdf folder.
Then you are able to add your gazebo plugins you want to use with your model.

You can find all plugins inside the gazebo/src/systems folder inside the gazebo 
[github repository](https://github.com/gazebosim/gz-sim/tree/gz-sim9/src/systems)
Inside the header file you are able to see the documentation and variables you need to interact
with the plugin. The name can be find inside source file `.cc` there is code that looks like this.

```xml
...
    // Clear the outbound queue, except for messages that were
    // in transit.
    _newRegistry[address].outboundMsgs = newOutbound;
  }
}

GZ_ADD_PLUGIN(AcousticComms,
              System,
              comms::ICommsModel::ISystemConfigure,
              comms::ICommsModel::ISystemPreUpdate)

GZ_ADD_PLUGIN_ALIAS(AcousticComms,
                          "gz::sim::systems::AcousticComms")
```

The name for this example is `gz::sim::systems::AcousticComms`.
This name you are able to set inside your gazebo plugin definition.

```xml
<?xml version="1.0"?>
<robot xmlns:xacro="http://www.ros.org/wiki/xacro">

    <!--Adds friction to the caster wheel to prevent glitches-->
    <gazebo reference="caster_wheel_link">
        <mu1 value="0.1" />
        <mu2 value="0.1" />
    </gazebo>

    <gazebo>
        <plugin filename="gz-sim-diff-drive-system"
                name="gz::sim::systems::DiffDrive">
                <left_joint>base_left_wheel_joint</left_joint>
                <right_joint>base_right_wheel_joint</right_joint>
                <wheel_separation>0.45</wheel_separation>
                <wheel_radius>0.1</wheel_radius>
                <frame_id>odom</frame_id>
                <child_frame_id>base_footprint</child_frame_id>
        </plugin>
    </gazebo> 

    <gazebo>
        <plugin filename="gz-sim-joint-state-publisher"
                name="gz::sim::systems::JointStatePublisher">
                <joint_name>base_left_wheel_joint</joint_name>
                <joint_name>base_right_wheel_joint</joint_name>
        </plugin>
    </gazebo>
</robot>
```

* `gz-sim-diff-drive-system` adds a differentials drive system that handles the two wheels
* `gz-sim-joint-state-publisher` add the joint state publisher
to modify the tf-elements inside the model

* The coeffiziat mu1 and mu2 are add to add friction to the caster wheel

## Bridge Configuration
The bridge is needed to interact with gazebo and ros2.
For this it is nessesary to add a bridge node.

```xml
<!-- Configuration for the bridge module for gazebo -->
<node pkg="ros_gz_bridge" exec="parameter_bridge">
    <param name="config_file" value="$(var gazebo_config_path"/>
</node>
```

Add a config folder to your **bringup** module.
Inside this folder add a file with the name `gazebo_bridge.yaml`
Then you are able to add the variable inside the node tag.
This can look like this:

```xml
    <let name="gazebo_config_path" value="$(find-pkg-share my_robot_bringup)/config/gazebo_bridge.yaml" />
``` 

It uses the package my_robot_bringup for the path.

Inside the Bridge configuration you can describe which topic you want to share with ros.
`ros_topic_name` is the name you want to give the see other ros programs
`gz_topic_name` is the topic of the gazebo simulation
`ros_type_name` is the datatype used by ros and that need to be converted by the bridge
`gz_type_name` is the datatype used by gazebo and that need to be converted by the bridge

You can find all datatypes inside this [git repo](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_bridge)

Example for clock
```yaml
- ros_topic_name: "/clock"
  gz_topic_name: "/clock"
  ros_type_name: "rosgraph_msgs/msg/Clock"
  gz_type_name: "gz.msgs.Clock"
  direction: GZ_TO_ROS
```

Following Direction exists:
* `GZ_TO_ROS` : From Gazebo to ros
* `ROS_TO_GZ`: From ros to gazebo
* `BIDIRECTIONAL`: Both can send data via this topic 

For the current config following topics need to be published to work with the diff_drive and
joint_states plugin:
ros@ros-HP-ProBook-445-G7:/opt/ros/humble/lib$ ros2 topic list -t  # Zeigt Topics mit ihren Typen
/clicked_point [geometry_msgs/msg/PointStamped]
/clock [rosgraph_msgs/msg/Clock]
/cmd_vel [geometry_msgs/msg/Twist]
/goal_pose [geometry_msgs/msg/PoseStamped]
/initialpose [geometry_msgs/msg/PoseWithCovarianceStamped]
/joint_states [sensor_msgs/msg/JointState]
/parameter_events [rcl_interfaces/msg/ParameterEvent]
/robot_description [std_msgs/msg/String]
/rosout [rcl_interfaces/msg/Log]
/tf [tf2_msgs/msg/TFMessage]
/tf_static [tf2_msgs/msg/TFMessage]

In rqt graph following picture should be seen:

![rqt_graph](image-2.png)

Note: When looking for gazebo topics in gazebo fortress only publisher service are shown
cmd_vel is a subscriber service and not visible
Look at this [article](https://robotics.stackexchange.com/questions/110989/gazebo-plugin-not-creating-cmd-vel-and-odom-topics-in-ros-2-humble-with-gazebo-f)

To see the values of a message type you can type:
`ros2 interface show geometry_msgs/msg/Twist` 

To drive the robot you can send following commend:
Forwards:
```bash
ros2 topic pub -r 1 /cmd_vel geometry_msgs/msg/Twist "{linear: {x: -1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}"
```

To drive the robot you can use the teleop twist program by running following program
`ros2 run teleop_twist_keyboard teleop_twist_keyboard`