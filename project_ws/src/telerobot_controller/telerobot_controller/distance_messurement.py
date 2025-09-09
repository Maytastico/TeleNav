import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
from geometry_msgs.msg import Twist
from telerobot_interfaces.msg import MoveCmd
from telerobot_controller.types.messurement import Measurements
from telerobot_controller.helpers.movecmd_to_twist import move_cmd_to_twist

class DistanceReader(Node):
    """
    Ein ROS2-Node, der Distanzmessungen von Lidar-Sensoren abonniert und ausgibt.
    """
    def __init__(self):
        super().__init__('distance_reader')

        self.measurements = Measurements()

        # self.front_subscription = self.create_subscription(
        #     Range,
        #     '/distance_front/out',
        #     self.front_callback,
        #     10
        # )
        # self.lower_subscription = self.create_subscription(
        #     Range,
        #     '/distance_lower/out',
        #     self.lower_callback,
        #     10
        # )
        # self.back_subscription = self.create_subscription(
        #     Range,
        #     '/distance_back/out',
        #     self.back_callback,
        #     10
        # )

        self.move_cmd_subscription = self.create_subscription(
            MoveCmd,
            'move_cmd',
            self.move_cmd_callback,
            10
        )

        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10)

        self.get_logger().info('New DistanceReader-Node gestartet.')

    # def front_callback(self, msg: Range):
    #     """
    #     Callback-Funktion für den vorderen Lidar-Sensor.
    #     """
    #     self.get_logger().info(f'Vordere Distanz: {msg.range:.2f} m')
    #     #self.measurements.front_distance = msg.range

    # def lower_callback(self,  msg: Range):
    #     """
    #     Callback-Funktion für den unteren Lidar-Sensor.
    #     """
    #     self.get_logger().info(f'Untere Distanz: {msg.range:.2f} m')
    #     #self.measurements.lower_distance = msg.range

    # def back_callback(self,  msg: Range):
    #     """
    #     Callback-Funktion für den hinteren Lidar-Sensor.
    #     """
    #     self.get_logger().info(f'Hintere Distanz: {msg.range:.2f} m')
    #     #self.measurements.back_distance = msg.range

    def move_cmd_callback(self, msg: MoveCmd):
        """
        Callback-Funktion für empfangene MoveCmd-Nachrichten.
        """
        self.get_logger().info(f'MoveCmd empfangen: {msg}')
        self.cmd_vel_publisher.publish(move_cmd_to_twist(msg))

def main(args=None):
    rclpy.init(args=args)
    distance_reader = DistanceReader()
    rclpy.spin(distance_reader)
    distance_reader.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()