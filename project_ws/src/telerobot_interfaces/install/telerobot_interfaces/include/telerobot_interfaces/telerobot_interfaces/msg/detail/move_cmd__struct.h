// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from telerobot_interfaces:msg/MoveCmd.idl
// generated code does not contain a copyright notice

#ifndef TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__STRUCT_H_
#define TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'STOP'.
enum
{
  telerobot_interfaces__msg__MoveCmd__STOP = 0
};

/// Constant 'FORWARD'.
enum
{
  telerobot_interfaces__msg__MoveCmd__FORWARD = 1
};

/// Constant 'TURN_LEFT'.
enum
{
  telerobot_interfaces__msg__MoveCmd__TURN_LEFT = 2
};

/// Constant 'TURN_RIGHT'.
enum
{
  telerobot_interfaces__msg__MoveCmd__TURN_RIGHT = 3
};

/// Struct defined in msg/MoveCmd in the package telerobot_interfaces.
typedef struct telerobot_interfaces__msg__MoveCmd
{
  uint8_t cmd;
} telerobot_interfaces__msg__MoveCmd;

// Struct for a sequence of telerobot_interfaces__msg__MoveCmd.
typedef struct telerobot_interfaces__msg__MoveCmd__Sequence
{
  telerobot_interfaces__msg__MoveCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} telerobot_interfaces__msg__MoveCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__STRUCT_H_
