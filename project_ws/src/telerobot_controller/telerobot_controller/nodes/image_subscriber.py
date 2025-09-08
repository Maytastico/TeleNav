from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

bridge: CvBridge = CvBridge()
IMAGE_TOPIC: str = '/camera_sensor/image_raw'


class ImageSubscriber(Node):

    
    def __init__(self):
        super().__init__('image_subscriber')
        print("Node initialized")
        self.latest_frame: bytes = b''
        self.camera = self.create_subscription(
            Image,
            IMAGE_TOPIC,
            self.listener_callback,
            10
        )

    def listener_callback(self, msg: Image):
        try:
            self.get_logger().info(f'Processing image...')
            global latest_frame
            cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            ret, jpeg = cv2.imencode('.jpg', cv_image)
            self.latest_frame = jpeg.tobytes()
        except Exception as e:
            self.get_logger().error(f'Error processing image: {e}')