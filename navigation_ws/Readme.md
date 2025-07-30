# Setup
This project is based on Ubuntu 22.04 for ros2-humble

You need to install colcon to build your source code
```bash
sudo apt install python3-colcon-common-extension
```
Install the extension for ros called `Robotics Developer Enviroment`
and `Cmake`

## Nav-Stack
 Install following packages for nav2

* ros-humble-navigation2
* ros-humble-nav2-bringup
* ros-humble-turtlebot3*

# SLAM
SLAM stand for "Simultaneous Localization And Mapping"
it is a technique to create a map from the enviroment of the robot.

# Turtlebot

To use a specific model for a turtlebot simulation you need to export
an environment variable inside `~/.bashrc`

Add this line to your .bashrc file

```
export TURTLEBOT3_MODEL=waffle
```

The next step is to run the simulation of the robot run.

`ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py`

After that you can start the chartographer to create a map.

`ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py`

To control the robot you can start

`ros2 run turtlebot3_teleop teleop_keyboard`

Two programs will start firstly gazebo where the simulation
is put in place. Then Rviz where the map is shown.

## Maps

When your map is created by the cartographer you are able to save the map that is published to the channel `maps/my_map`


To save the map to the filesystem run following command

`ros2 run nav2_map_server map_saver_cli -f map`

Look inside rviz and map node and look for the channel
the map is published to.

What can you see inside the maps.
When exporting the map you get two files
- my_map.yaml
    - image: defines which image file is used
    - resolution: defines how may cm a pixel is
    - origin: defines on which position the robot started
    - occupied_tresh: defines at which percentage of black (255 black; 0 white) the plane is occipied by obstacle.
    - free-tresh: defines at what percentage the area is free.
and an image file 

## Navigation

In order to make the nav2 stack work we need to change the communication framework.
Humble uses dds to make the use of the map work we need to install cyclone dds

```bash
sudo apt install ros-humble-rmw-cyclonedds-cpp
```

Afterwards it is important set the environment variable to make ros2 know to use
cyclone dds.

Add this to ~/.bashrc
```bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
```

In addition the parameters of the turtlebot3 waffle.yaml needs to be updated.
Go to `/opt/ros/humble/share/turtlebot3_navigation2/param`
Inside the folder change the parameter `robot_model_type: "differential"`
to `robot_model_type: "nav2_acml::DifferntialMotionModel`

*In my case it is updated*

To start the navigation run
```bash
ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True
```

In order to launch the simulation with a specified map you need to add another argument.
To make this work add `map:=<location of the map>`
```bash
ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=./maps/my_map.yaml
```
