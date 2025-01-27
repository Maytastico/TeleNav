# api for ros
import rclpy

# datatype for sending and recieving messages
from std_msgs.msg import String

# opens a node class
from rclpy.node import Node

class SubscriberNode(Node):
    def __init__(self):
        """Initializes the superclass with a a name and configures the communication"""
        super().__init('node_subscriber')

        # Configures the class to become a subscriber node
        bufferSize = 15
        self.subscription = self.create_subscription(
            String, # datatype
            'communication_topic', # topic name
            self.callbackFunction, # callback function
            bufferSize# buffer size
        )

        self.subscription

    def callbackFunction(self, message):
        self.get_logger().info(f'''
                               I have received: {message.data}
        ''')

def main(args=None):
    rclpy.init(args=args)
    node_subscriber = SubscriberNode()
    rclpy.spin(node_subscriber)
    node_subscriber.destroy_node()
    rclpy.shutdown()
    
if __name__ == '__main__':
    main()