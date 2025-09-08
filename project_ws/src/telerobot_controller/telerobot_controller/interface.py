from flask import Flask, render_template, Response, request, jsonify
from telerobot_controller.types.move_cmd_emum import MoveCmdEnum 
from telerobot_controller.nodes.image_subscriber import ImageSubscriber, latest_frame
from telerobot_controller.nodes.move_cmd_publisher import MoveCmdPublisher
from sensor_msgs.msg import Image
import rclpy
import threading


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
pcs: set = set()

move_cmd_publisher: MoveCmdPublisher
image_node: ImageSubscriber

def ros_spin(image_node: ImageSubscriber, move_cmd_publisher: MoveCmdPublisher):
    rclpy.spin(image_node)
    rclpy.spin(move_cmd_publisher)
    image_node.destroy_node()
    image_node.destroy_node()
    rclpy.shutdown()

@app.route('/')
def index():
    return render_template("index.html")

def generate_frames():
    last_frame = None
    global image_node
    while True:
        print(str(image_node.latest_frame))
        if image_node.latest_frame is not None and image_node.latest_frame != last_frame:

            last_frame = image_node.latest_frame
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

    # Extract values from received data
    if data is None:
        return jsonify({"status": "error", "message": "No JSON data received"}), 400
    joy_x = data.get('joy_x', 0)
    joy_y = data.get('joy_y', 0)
    cmd = data.get('cmd', 0)

    try:
        # Convert cmd to MoveCmdEnum if necessary
        if not isinstance(cmd, MoveCmdEnum):
            cmd_enum = MoveCmdEnum(cmd)
        else:
            cmd_enum = cmd
        move_cmd_publisher.publish_move_cmd(joy_x, joy_y, cmd_enum)
        return jsonify({"status": "success", "received": data})
    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500

def main():
    rclpy.init()
    global image_node
    image_node = ImageSubscriber()
    global move_cmd_publisher
    move_cmd_publisher = MoveCmdPublisher()
    t = threading.Thread(target=ros_spin, args=(image_node, move_cmd_publisher), daemon=True)
    t.start()
    app.run(host='0.0.0.0', port=5000, debug=False, use_reloader=False)

if __name__ == "__main__":
    main()