# Setup

To use this project, you need **ROS 2 Humble** on **Ubuntu 22.04.5 LTS** as well as the following Python packages:

    * `flask`
    * `scipy`
    * `numpy`

All required packages can be easily installed using the `bash setup_packages.sh` script in the root directory of the repository.

-----

# Running

1.  First, set up the ROS 2 environment by sourcing the `install/setup.bash` file:

        ```bash
        source install/setup.bash
        ```

2.  Then, start the simulation with:

        ```bash
        ros2 launch telerobot_bringup telerobo_simple.xml
        ```

3.  Next, start the web interface:

        ```bash
        ros2 run telerobot_controller interface
        ```

4.  Finally, start the controller:

        ```bash
        ros2 run telerobot_controller controller
        ```

The web interface is now available at **127.0.0.1:5000**.

> **Note:** The controller may crash due to a known ROS 2 bug with the range sensor, which causes it to return **NaN** values. 
> There is currently no known solution for this issue.

-----

# Usage

You can control the robot either with the keyboard or the mouse.

### Keyboard Control

    * **W:** Forward
    * **S:** Backward
    * **D:** Turn right
    * **A:** Turn left
    * **Spacebar:** Stop

### Mouse Control

Move the green circle in the desired direction to control the robot.