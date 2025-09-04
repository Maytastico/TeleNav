import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range

class DistanceReader(Node):
    """
    Ein ROS2-Node, der Distanzmessungen von Lidar-Sensoren abonniert und ausgibt.
    """
    def __init__(self):
        super().__init__('distance_reader')

        # Abonnieren der Lidar-Topics
        self.front_subscription = self.create_subscription(
            Range,
            'distance_front',
            self.front_callback,
            10
        )
        self.lower_subscription = self.create_subscription(
            Range,
            'distance_lower',
            self.lower_callback,
            10
        )
        self.back_subscription = self.create_subscription(
            Range,
            'distance_back',
            self.back_callback,
            10
        )
        self.get_logger().info('DistanceReader-Node gestartet.')

    def front_callback(self, msg):
        """
        Callback-Funktion für den vorderen Lidar-Sensor.
        """
        self.get_logger().info(f'Vordere Distanz: {msg.range:.2f} m')

    def lower_callback(self, msg):
        """
        Callback-Funktion für den unteren Lidar-Sensor.
        """
        self.get_logger().info(f'Untere Distanz: {msg.range:.2f} m')

    def back_callback(self, msg):
        """
        Callback-Funktion für den hinteren Lidar-Sensor.
        """
        self.get_logger().info(f'Hintere Distanz: {msg.range:.2f} m')

def main(args=None):
    rclpy.init(args=args)
    distance_reader = DistanceReader()
    rclpy.spin(distance_reader)
    distance_reader.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()