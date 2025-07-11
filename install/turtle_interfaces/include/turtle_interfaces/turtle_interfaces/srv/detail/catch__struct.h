// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_interfaces:srv/Catch.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__SRV__DETAIL__CATCH__STRUCT_H_
#define TURTLE_INTERFACES__SRV__DETAIL__CATCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'own_turtle'
// Member 'catch_turtle'
#include "turtle_interfaces/msg/detail/turtle_position__struct.h"

/// Struct defined in srv/Catch in the package turtle_interfaces.
typedef struct turtle_interfaces__srv__Catch_Request
{
  turtle_interfaces__msg__TurtlePosition own_turtle;
  turtle_interfaces__msg__TurtlePosition catch_turtle;
} turtle_interfaces__srv__Catch_Request;

// Struct for a sequence of turtle_interfaces__srv__Catch_Request.
typedef struct turtle_interfaces__srv__Catch_Request__Sequence
{
  turtle_interfaces__srv__Catch_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_interfaces__srv__Catch_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Catch in the package turtle_interfaces.
typedef struct turtle_interfaces__srv__Catch_Response
{
  bool success;
} turtle_interfaces__srv__Catch_Response;

// Struct for a sequence of turtle_interfaces__srv__Catch_Response.
typedef struct turtle_interfaces__srv__Catch_Response__Sequence
{
  turtle_interfaces__srv__Catch_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_interfaces__srv__Catch_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_INTERFACES__SRV__DETAIL__CATCH__STRUCT_H_
