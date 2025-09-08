from flask import Flask, render_template, Response, request, jsonify
from aiortc import RTCPeerConnection, RTCSessionDescription
import rclpy
import json
import uuid
import asyncio
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
import threading
import cv2
from cv_bridge import CvBridge
import time
import os
from ament_index_python.packages import get_package_share_directory

PACKAGE_NAME = "telerobot_controller"
SHARE_DIR = get_package_share_directory(PACKAGE_NAME)
app = Flask(
    __name__,
    static_folder=os.path.join(SHARE_DIR, 'static'),
    template_folder=os.path.join(SHARE_DIR, 'templates')
)

print(os.path.join(SHARE_DIR, 'static'))
pcs = set()
IMAGE_TOPIC = '/camera_sensor/image_raw'
bridge = CvBridge()
global latest_frame


class ImageSubscriber(Node):
    def __init__(self):
        super().__init__('image_subscriber')
        print("Node initialized Hi")
        self.camera = self.create_subscription(
            Image,
            '/camera_sensor/image_raw',
            self.listener_callback,
            10
        )
        self.controller = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )

    def listener_callback(self, msg: Image):
        try:
            global latest_frame
            cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            ret, jpeg = cv2.imencode('.jpg', cv_image)
            latest_frame = jpeg.tobytes()
        except Exception as e:
            self.get_logger().error(f'Error processing image: {e}')

class ControlSubscriber(Node):
    def __init__(self):
        super().__init__('control_subscriber')
        self.publisher = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )


def ros_spin(image_node: ImageSubscriber):
    rclpy.spin(image_node)
    image_node.destroy_node()
    rclpy.shutdown()

@app.route('/')
def index():
    return render_template("index.html")

def generate_frames():
    last_frame = None
    while True:
        global latest_frame
        if latest_frame is not None and latest_frame != last_frame:
            last_frame = latest_frame
            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + latest_frame + b'\r\n')
        else:
            time.sleep(0.01)  # kurz warten, um CPU-Last zu reduzieren


# Route to stream video frames
@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/control', methods=['POST'])
def control():
    data = request.json
    print(f"Received control data: {data}")
    # Hier können Sie die Steuerbefehle verarbeiten und an den Roboter senden
    return jsonify({"status": "success", "received": data})

def main():
    rclpy.init()
    image_node = ImageSubscriber()
    t = threading.Thread(target=ros_spin, args=(image_node, ), daemon=True)
    t.start()
    app.run(host='0.0.0.0', port=5000, debug=False, use_reloader=False)

if __name__ == "__main__":
    main()