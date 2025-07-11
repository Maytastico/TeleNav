// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_interfaces:msg/TurtlePosition.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__STRUCT_H_
#define TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TurtlePosition in the package turtle_interfaces.
typedef struct turtle_interfaces__msg__TurtlePosition
{
  rosidl_runtime_c__String name;
  float x;
  float y;
  float theta;
} turtle_interfaces__msg__TurtlePosition;

// Struct for a sequence of turtle_interfaces__msg__TurtlePosition.
typedef struct turtle_interfaces__msg__TurtlePosition__Sequence
{
  turtle_interfaces__msg__TurtlePosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_interfaces__msg__TurtlePosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__STRUCT_H_
