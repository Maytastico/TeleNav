from setuptools import find_packages, setup

package_name = 'my_robot_controller'
setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ros',
    maintainer_email='may_grune@hotmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "py_node = my_robot_controller.my_first_node:main",
            "add_two_numbers = my_robot_controller.add_two_int_server:main",
            "add_two_number_client = my_robot_controller.add_two_ints_client:main",
            "number_counter = my_robot_controller.number_counter:main",
            "hw_status_publisher = my_robot_controller.hardware_status:main",
            "compute_rectangle_service = my_robot_controller.compute_rectangle_area_service:main",
            "battery_node = my_robot_controller.battery_node:main",
            "led_panel_node = my_robot_controller.led_panel_node:main",
            "parameter_publisher = my_robot_controller.parameter_publisher:main",
        ],
    },
)