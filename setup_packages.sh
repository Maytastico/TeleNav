# Python Package manager
sudo apt install python3-pip -y
sudo apt install ros-dev-tools -y

# Ros2 simulator
sudo apt install ros-humble-turtlesim -y
sudo apt install ros-humble-joint-state-publisher -y
sudo apt install ros-humble-joint-state-publisher-gui -y
sudo apt install ros-humble-xacro -y
sudo apt install '~nros-humble-rqt*' -y
#old gazebo simulation sudo apt install ros-humble-gazebo-* -y
sudo apt install ros-humble-desktop -y
sudo apt install ros-humble-ros-gz -y
# Colcon pip packages for code suggestions
sudo apt install python3-colcon-common-extensions python3-colcon-coveragepy-result python3-colcon-core -y

# URDF
sudo apt install ros-humble-urdf-tutorial -y
sudo apt install ros-humble-tf2-tools -y

# Nav2
sudo apt install ros-humble-navigation2 ros-humble-nav2-bringup ros-humble-turtlebot3* -y
sudo apt install ros-humble-rmw-cyclonedds-cpp -y # Only for humble
sudo apt-get install ros-humble-nav2-rviz-plugins -y
