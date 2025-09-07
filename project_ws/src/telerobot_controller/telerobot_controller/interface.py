from flask import Flask, render_template, Response, request, jsonify
from aiortc import RTCPeerConnection, RTCSessionDescription
import rclpy
import json
import uuid
import asyncio
from rclpy.node import Node
from sensor_msgs.msg import Image
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

    def listener_callback(self, msg: Image):
        try:
            global latest_frame
            cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            ret, jpeg = cv2.imencode('.jpg', cv_image)
            latest_frame = jpeg.tobytes()
        except Exception as e:
            self.get_logger().error(f'Error processing image: {e}')


def ros_spin(image_node: ImageSubscriber):
    rclpy.spin(image_node)
    image_node.destroy_node()
    rclpy.shutdown()

@app.route('/')
def index():
    return render_template("index.html")

def generate_frames():
    while True:
        start_time = time.time()
        # Concatenate frame and yield for streaming
        yield (b'--frame\r\n'
                b'Content-Type: image/jpeg\r\n\r\n' + latest_frame + b'\r\n') 
        elapsed_time = time.time() - start_time
        print(f"Frame generation time: {elapsed_time} seconds")

async def offer_async():
    params = await request.json # type: ignore
    offer = RTCSessionDescription(sdp=params["sdp"], type=params["type"])

    # Create an RTCPeerConnection instance
    pc = RTCPeerConnection()

    # Generate a unique ID for the RTCPeerConnection
    pc_id = "PeerConnection(%s)" % uuid.uuid4()
    pc_id = pc_id[:8]

    # Create a data channel named "chat"
    # pc.createDataChannel("chat")

    # Create and set the local description
    await pc.createOffer(offer) # type: ignore
    await pc.setLocalDescription(offer)

    # Prepare the response data with local SDP and type
    response_data = {"sdp": pc.localDescription.sdp, "type": pc.localDescription.type}

    return jsonify(response_data)

def offer():
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    
    future = asyncio.run_coroutine_threadsafe(offer_async(), loop)
    return future.result()

# Route to handle the offer request
@app.route('/offer', methods=['POST'])
def offer_route():
    return offer()

# Route to stream video frames
@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

def main():
    rclpy.init()
    image_node = ImageSubscriber()
    t = threading.Thread(target=ros_spin, args=(image_node, ), daemon=True)
    t.start()
    app.run(host='0.0.0.0', port=5000, debug=False, use_reloader=False)

if __name__ == "__main__":
    main()