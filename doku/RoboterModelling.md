# URDF


To open your model you can run following command.
When you install the urdf-tutorial package you can find example models inside 
**/opt/ros/humble/share/urdf_tutorial/urdf/**

```
ros2 launch urdf_tutorial display.launch.py model:=/opt/ros/humble/share/urdf_tutorial/urdf/08-macroed.urdf.xacro
```

## Creating a urdf project

1. Create classic ament_c project
2. Delete `src` and `install`
3. Create a `urdf` folder
4. Add following to your `CMakeList.txt` file

```c
install(
  DIRECTORY urdf
  DESTINATION share/${PROJECT_NAME}/
)
```

# Transformations

## Get treerepresentation of your robot
To see the tree of all the link of the robot run:

```
ros2 run tf2_tools view_frames
```

# Create Models

The most basic structure is a structure with a base_link.
Inside the base_link you add a geometry.

```xml
<?xml version="1.0"?>
<robot name="my_robot">
    <!-- Defines the geometry and link of the robot-->
    <link name="base_link"><!-- The base link is nessesary as a basic link object-->
        <visual>
            <geometry>
                <box size="0.6 0.4 0.2"/> <!-- in meters |  60cm long | 40cm wide | 20 cm high -->
            </geometry>
            <!-- Places the robot on the default position -->
            <origin xyz="0 0 0.1" rpy="0 0 0"/> <!-- position of the box rpy: toll pitch yaw-->
        </visual>
    </link>
</robot>

```

## Colors
After creating a basic structure you can add materials to colorize your visual elements.
Add following under the robot tag:

```xml
<material name="green">
        <color rgba="0 0.5 0 1"/> <!-- green color in rgba-->
</material>
```

After adding a material you are able to describe a geometry with this material by
adding the *material* tag
```xml
<?xml version="1.0"?>
<robot name="my_robot">
    <material name="blue">
        <color rgba="0 0 0.5 1"/> <!-- green color in rgba-->
    </material>

    <!-- Defines the geometry and link of the robot-->
    <link name="base_link"><!-- The base link is nessesary as a basic link object-->
        <visual>
            <geometry>
                <box size="0.6 0.4 0.2"/> <!-- in meters |  60cm long | 40cm wide | 20 cm high -->
            </geometry>
            <!-- Places the robot on the default position -->
            <origin xyz="0 0 0.1" rpy="0 0 0"/> <!-- position of the box rpy: toll pitch yaw-->
            <material name="blue"/> <!-- color of the box -->
        </visual>
    </link>
</robot>
```

## Links
When just adding links you need to make sure, that you create links between them.
That is because you can not haver several links as root elements.

Pro Tip: At first you just provide a origin with `xyz="0 0 0"` 
Then you can modify it as you need it to be in rviz

To define the relationships of your link you can use following code:

```xml
<joint name="base_second_joint" type="fixed">
        <parent link="base_link"/>
        <child link="second_link"/>
        <origin xyz="0 0 0" rpy="0 0 0"/>
</joint>
```

The `<parent>` tag specifies the parent link of the joint, which in this case is "base_link". The `<child>` tag specifies the child link, which is "second_link". These tags define the two links that are connected by the joint.

The `<origin>` tag defines the position and orientation of the joint relative to the parent link. The xyz attribute specifies the position in the x, y, and z coordinates, and the rpy attribute specifies the orientation in roll, pitch, and yaw angles. In this example, both the position and orientation are set to zero, meaning the joint is located at the origin of the parent link's coordinate frame with no rotation.

### Placement
When placing the object right you need to firstly adjust the orgin inside the defined joint just after that you can modify the origin 
of the links!!

1. All origins to zero
2. Then change the origin of the geometry

### Joints

[Link](https://wiki.ros.org/urdf/XML/link)

[Joints](https://wiki.ros.org/urdf/XML/joint)

Rotation values:
* 1.57: 90°
* 3.14: 180°

**Fixed** is a joint that is not able to move and stands still.

```xml
<joint name="base_second_joint" type="fixed">
    <parent link="base_link"/>
    <child link="second_link"/>
    <origin xyz="0 0 0.2" rpy="0 0 0"/>
</joint>
```

**Revolute** is a joint were the parameters can be passed to rotate and move the geometry of the link.

* `axis` defines how the geometry should be moved. This element should be placed after `origin`
* `limit` defines the limits of the movement of the element

```xml
<joint name="second_third_joint" type="revolute">
    <parent link="second_link"/>
    <child link="third_link"/>
    <origin xyz="0 0 0.2" rpy="0 0 0"/>
    <axis xyz="1 0 0"/> <!-- rotation axis -->
    <limit lower="-1.57" upper="1.57" velocity="100" effort="100"/> <!-- joint limits -->
</joint>
```

**Continous** is the same as revolute but it has no limits. It is used for wheels. This element is similair to a revolute joint just that is does not use limits, just the axis where the object should be able to rotate.

**Prismatic** is used for objects that slide on the object.

```xml
<joint name="base_second_joint" type="prismatic">
    <parent link="base_link"/>
    <child link="second_link"/>
    <origin xyz="0 0 0.2" rpy="0 0 0"/>
    <axis xyz="1 0 0"/> <!-- rotation axis -->
    <limit lower="0" upper="0.2" velocity="100" effort="100"/> <!-- joint limits -->
</joint>
```

# Modelling advise

When designing a robot and using navigation libraries like nav 2 it is important to provide a base_footprint.
This is an invisible joint and link that defines the ground of the robot. With that a reference of the ground can be created.

## Plain Rviz
When running Rviz with a custom launch file the simulation will lack a Robot Model as well as the TFs.
For changing this add following elements

1. RobotModel: Add -> rviz_default_plugins -> RobotModel
2. TF: Add -> rviz_default_plugins -> TF

Then open the setting of RobotModel and add /robot_description to the Description Element

## Xacro

To make a urdf file working you add following attribute to the xacro file

```xml
<robot name="mosro" xmlns:xacro="http://www.ros.org/wiki/xacro">
```

# Variables

Inside xacro files variables can be used to define the properties of an object. In addition sizes can be calculated inside the description.

You can use variables with `${var}`

To define a Variable you can use following code

```xml
<xacro:property name="base_lenght" value="0.6">
```

Common variables are:
* pi
  * You can use pi to define roll pitch or yaw
  * pi = 360° = 3.14
  * pi/2 = 180° = 1.57

# Makros (Functions)

For automaticaly generate xarco code you can use makros that work like functions.
You can define a macro with following code

```xml
<xacro:macro name="wheel_link" params="prefix">
    <link name="${prefix}_wheel_link">
        <visual>
            <origin xyz="0 0 0" rpy="${pi/2.0} 0 0"/>
            <geometry>
                <cylinder radius="${wheel_radius}" length="${wheel_length}"/> <!-- in meters |  20cm radius | 20cm height -->
            </geometry>
            <material name="grey"/>
        </visual>
    </link>
</xacro:macro>
```

Then for executing the defined makro you can use.
```xml
<xacro:wheel_link prefix="right"/>
```

# Import a urdf

1. Choose a mainfile where the most basic geometric properties are described
   * Only the main file contains a name
2. Create a file to import into your base file
```xml
<?xml version="1.0" encoding="UTF-8"?>
<robot xmlns:xacro="http://www.ros.org/wiki/xacro">
</robot>
```
Launching a file that is meant to be included will result in an error!

# Interia

When adding the incertia of a simple robot you can calculate these with macros and a formular from wikipedia [inertia table](https://en.wikipedia.org/wiki/List_of_moments_of_inertia#List_of_3D_inertia_tensors)

You can add these macros to generate the inertia tags for the specific
from.

```xml
<xacro:macro name="box_inertia" params="mass lenght width height xyz_origin rpy_orgin">
    <intertial>
        <origin xyz="${xyz_origin}" rpy="${rpy_orgin}"/>
        <mass value="${mass}"/>
        <inertia 
        ixx="${(mass/12)*(width**2 + height**2)}" ixy="0" ixz="0" 
        iyx="0" iyy="${(mass/12)*(lenght**2 + height**2)}" iyz="0" 
        izx="0" izy="0" izz="${(mass/12)*(lenght**2 + width**2)}"/>
    </intertial>
</xacro:macro>

<xacro:macro name="cylinder_inertia" params="mass radius height xyz_origin rpy_orgin">
    <intertial>
        <origin xyz="${xyz_origin}" rpy="${rpy_orgin}"/>
        <mass value="${mass}"/>
        <inertia 
        ixx="${(mass/12)*(3*radius**2 + height**2)}" ixy="0" ixz="0" 
        iyx="0" iyy="${(mass/12)*(3*radius**2 + height**2)}" iyz="0" 
        izx="0" izy="0" izz="${(mass/2)*radius**2}"/>
    </intertial>
</xacro:macro>

<xacro:macro name="sphere_inertia" params="mass radius xyz_origin rpy_orgin">
    <intertial>
        <origin xyz="${xyz_origin}" rpy="${rpy_orgin}"/>
        <mass value="${mass}"/>
        <inertia 
        ixx="${(2*mass*radius**2)/5}" ixy="0" ixz="0" 
        iyx="0" iyy="${(2*mass*radius**2)/5}" iyz="0" 
        izx="0" izy="0" izz="${(2*mass*radius**2)/5}"/>
    </intertial>
</xacro:macro>
```

**Important**: When using a wrong name or duplicate attributes the model can behave wierd.

# Collisions
Collisions are simplified forms of the visual geometry they use
simple shapes like boxes, cylinders oder spheres

You can add them by adding the `collision`-Element
below your visual that can look like that

```xml
<link name="${prefix}_wheel_link">
    <visual>
        <origin xyz="0 0 0" rpy="${pi/2.0} 0 0"/>
        <geometry>
            <cylinder radius="${wheel_radius}" length="${wheel_length}"/> <!-- in meters |  20cm radius | 20cm height -->
        </geometry>
        <material name="grey"/>
    </visual>
    <collision>
        <origin xyz="0 0 0" rpy="${pi/2.0} 0 0"/>
        <geometry>
            <cylinder radius="${wheel_radius}" length="${wheel_length}"/> <!-- in meters |  20cm radius | 20cm height -->
        </geometry>
    </collision>
    <xacro:cylinder_inertia mass="1" radius="${wheel_radius}" height="${wheel_length}" xyz_origin="0 0 0" rpy_orgin="0 0 0"/> 
</link>
```