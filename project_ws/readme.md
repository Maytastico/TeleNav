# Setup 🛠️

To use this project, you need:

    * **ROS 2 Humble** on **Ubuntu 22.04.5 LTS**
    * The following Python packages:
            * `flask`
            * `scipy`
            * `numpy`

You can easily install all required packages using the `bash setup_packages.sh` script in the root directory of the repository.

-----

# Running 🚀

1.  First, set up the ROS 2 environment by sourcing the `install/setup.bash` file:
        ```bash
        source install/setup.bash
        ```
2.  Then start the simulation with:
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

The web interface will now be available at **127.0.0.1:5000**.

> **Note:** The controller may crash due to a known ROS 2 bug with the range sensor, which causes **NaN** values to be returned. There is currently no known solution for this issue. 🐞

-----

# Usage 🎮

You can control the robot either with the keyboard or the mouse.

### Keyboard Control ⌨️

    * **W:** Move forward
    * **S:** Move backward
    * **D:** Turn right
    * **A:** Turn left
    * **Spacebar:** Stop

### Mouse Control 🖱️

Move the green circle in the desired direction to control the robot.

-----

# Development 💻

After setting up the project environment (`project_ws`), run `code .` to start Visual Studio Code.