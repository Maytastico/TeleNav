// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_interfaces:msg/TurtlesAlive.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__STRUCT_H_
#define TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'turtles'
#include "turtle_interfaces/msg/detail/turtle_position__struct.h"

/// Struct defined in msg/TurtlesAlive in the package turtle_interfaces.
typedef struct turtle_interfaces__msg__TurtlesAlive
{
  turtle_interfaces__msg__TurtlePosition__Sequence turtles;
} turtle_interfaces__msg__TurtlesAlive;

// Struct for a sequence of turtle_interfaces__msg__TurtlesAlive.
typedef struct turtle_interfaces__msg__TurtlesAlive__Sequence
{
  turtle_interfaces__msg__TurtlesAlive * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_interfaces__msg__TurtlesAlive__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__STRUCT_H_
