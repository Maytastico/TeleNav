import enum

class MoveCmdEnum(enum.Enum):
    STOP = 0
    FORWARD = 1
    TURN_LEFT = 2
    TURN_RIGHT = 3
    BACKWARD = 4

    @staticmethod
    def from_string(cmd_str):
        try:
            return MoveCmdEnum[cmd_str.upper()]
        except KeyError:
            raise ValueError(f"Unknown command: {cmd_str}")