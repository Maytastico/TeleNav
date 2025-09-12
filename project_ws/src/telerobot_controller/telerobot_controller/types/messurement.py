
class Measurements:

    def __init__(self) -> None:
        """Store distance measurements of the robot's sensors."""
        self.front_distance: float = 0.0
        self.back_distance: float = 0.0
        self.lower_distance: float = 0.0