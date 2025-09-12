
from sensor_msgs.msg import Range

class Measurements:

    def __init__(self) -> None:
        """Store distance measurements of the robot's sensors."""
        self.front_distance: Range = Range()
        self.back_distance: Range = Range()
        self.lower_distance: Range = Range()