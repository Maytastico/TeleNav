import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SimplePublisher(Node):

    def __init__(self):
        super().__init__('simple_publisher')
        
        # Defines the type of message to be published
                                        # type    # topic name  # queue size
        self.pub_ = self.create_publisher(String, 'chatter', 10)

        # Counts the numer of messages sent
        self.counter_ = 0

        # Defines the frequency of the messages sent
        self.frequency_ = 1 # Hz

        # Prints a message to the console
        self.get_logger().info('Publishing at %d Hz' % self.frequency_)

        # Creates a timer that calls the publish_message method at the frequency defined
        self.timer_ = self.create_timer(1.0 / self.frequency_, self.timerCallback)

    def timerCallback(self):
        # initializes the string message
        msg = String()

        # builds the message
        msg.data = 'Hello World: %d' % self.counter_

        # publishes the message
        self.pub_.publish(msg)

        # increments the counter
        self.counter_ += 1

def main():

    # Initializes the ROS client library for Python
    rclpy.init()

    # Creates the node
    simple_publisher = SimplePublisher()

    # Spins the node so the callback function is called
    rclpy.spin(simple_publisher)

    # Destroys the node explicitly when closing the program
    simple_publisher.destroy_node()

    # Shutdown the ROS client library for Python
    rclpy.shutdown()

if __name__ == '__main__':
    main()