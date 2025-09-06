from flask import Flask, Response, render_template_string
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import threading
import cv2
from cv_bridge import CvBridge
import time

app = Flask(__name__)
IMAGE_TOPIC = '/camera_sensor/image_raw'
bridge = CvBridge()
global latest_frame

class ImageSubscriber(Node):
    def __init__(self):
        super().__init__('image_subscriber')
        print("Node initialized")
        self.camera = self.create_subscription(
            Image,
            '/camera_sensor/image_raw',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg: Image):
        try:
            global latest_frame
            self.get_logger().info('Image received')
            cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            ret, jpeg = cv2.imencode('.jpg', cv_image)
            latest_frame = jpeg.tobytes()
            self.get_logger().info('Image processed and converted to JPEG')
        except Exception as e:
            self.get_logger().error(f'Error processing image: {e}')


def ros_spin(image_node: ImageSubscriber):
    rclpy.spin(image_node)
    image_node.destroy_node()
    rclpy.shutdown()

@app.route('/')
def index():
    return render_template_string("""
        <html>
        <head>
            <title>ROS2 Camera Stream</title>
        </head>
        <body>
            <h1>ROS2 Camera Stream</h1>
            <img src="{{ url_for('video_feed') }}">
        </body>
        </html>
    """)

def gen():
    while True:
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + latest_frame + b'\r\n')

@app.route('/video_feed')
def video_feed():
    return Response(latest_frame)

def main():
    rclpy.init()
    image_node = ImageSubscriber()
    t = threading.Thread(target=ros_spin, args=(image_node, ), daemon=True)
    t.start()
    app.run(host='0.0.0.0', port=5000, debug=False, use_reloader=False)