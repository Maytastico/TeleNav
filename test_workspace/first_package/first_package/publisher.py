

# api for ros
import rclpy

# datatype for sending and recieving messages
from std_msgs.msg import String

# opens a node class
from rclpy.node import Node

class PublisherNode(Node):
    def __init__(self):
        """Initializes the superclass with a a name and configures the communication"""
        super().__init__('node_publisher')

        # Configures the class to become a publisher node
        bufferSize = 15
        self.publisher = self.create_publisher(String, 'communicatio_topic', bufferSize)

        # Defines at time between the execution of the main program
        comRate = 1

        # counts how often a message is sent
        self.counter = 0

        # creates a timer that executes the main function every second
        self.timer = self.create_timer(comRate, self.callbackFunction)

    def callbackFunction(self):
        messagePublisher = String()
        messagePublisher.data = 'Counter value: %d' % self.counter
        self.publisher.publish(messagePublisher)

        # logs the message sent
        self.get_logger().info(f'''
                               I have published: {messagePublisher.data}
        ''')
        self.counter += 1

def main(args=None):
    rclpy.init(args=args)
    node_publisher = PublisherNode()
    rclpy.spin(node_publisher)
    node_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

    