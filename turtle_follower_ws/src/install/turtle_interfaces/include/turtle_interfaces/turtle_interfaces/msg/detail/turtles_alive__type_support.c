// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtle_interfaces:msg/TurtlesAlive.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtle_interfaces/msg/detail/turtles_alive__rosidl_typesupport_introspection_c.h"
#include "turtle_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtle_interfaces/msg/detail/turtles_alive__functions.h"
#include "turtle_interfaces/msg/detail/turtles_alive__struct.h"


// Include directives for member types
// Member `turtles`
#include "turtle_interfaces/msg/turtle_position.h"
// Member `turtles`
#include "turtle_interfaces/msg/detail/turtle_position__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtle_interfaces__msg__TurtlesAlive__init(message_memory);
}

void turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_fini_function(void * message_memory)
{
  turtle_interfaces__msg__TurtlesAlive__fini(message_memory);
}

size_t turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__size_function__TurtlesAlive__turtles(
  const void * untyped_member)
{
  const turtle_interfaces__msg__TurtlePosition__Sequence * member =
    (const turtle_interfaces__msg__TurtlePosition__Sequence *)(untyped_member);
  return member->size;
}

const void * turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__get_const_function__TurtlesAlive__turtles(
  const void * untyped_member, size_t index)
{
  const turtle_interfaces__msg__TurtlePosition__Sequence * member =
    (const turtle_interfaces__msg__TurtlePosition__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__get_function__TurtlesAlive__turtles(
  void * untyped_member, size_t index)
{
  turtle_interfaces__msg__TurtlePosition__Sequence * member =
    (turtle_interfaces__msg__TurtlePosition__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__fetch_function__TurtlesAlive__turtles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtle_interfaces__msg__TurtlePosition * item =
    ((const turtle_interfaces__msg__TurtlePosition *)
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__get_const_function__TurtlesAlive__turtles(untyped_member, index));
  turtle_interfaces__msg__TurtlePosition * value =
    (turtle_interfaces__msg__TurtlePosition *)(untyped_value);
  *value = *item;
}

void turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__assign_function__TurtlesAlive__turtles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtle_interfaces__msg__TurtlePosition * item =
    ((turtle_interfaces__msg__TurtlePosition *)
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__get_function__TurtlesAlive__turtles(untyped_member, index));
  const turtle_interfaces__msg__TurtlePosition * value =
    (const turtle_interfaces__msg__TurtlePosition *)(untyped_value);
  *item = *value;
}

bool turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__resize_function__TurtlesAlive__turtles(
  void * untyped_member, size_t size)
{
  turtle_interfaces__msg__TurtlePosition__Sequence * member =
    (turtle_interfaces__msg__TurtlePosition__Sequence *)(untyped_member);
  turtle_interfaces__msg__TurtlePosition__Sequence__fini(member);
  return turtle_interfaces__msg__TurtlePosition__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_member_array[1] = {
  {
    "turtles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_interfaces__msg__TurtlesAlive, turtles),  // bytes offset in struct
    NULL,  // default value
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__size_function__TurtlesAlive__turtles,  // size() function pointer
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__get_const_function__TurtlesAlive__turtles,  // get_const(index) function pointer
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__get_function__TurtlesAlive__turtles,  // get(index) function pointer
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__fetch_function__TurtlesAlive__turtles,  // fetch(index, &value) function pointer
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__assign_function__TurtlesAlive__turtles,  // assign(index, value) function pointer
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__resize_function__TurtlesAlive__turtles  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_members = {
  "turtle_interfaces__msg",  // message namespace
  "TurtlesAlive",  // message name
  1,  // number of fields
  sizeof(turtle_interfaces__msg__TurtlesAlive),
  turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_member_array,  // message members
  turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_init_function,  // function to initialize message memory (memory has to be allocated)
  turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_type_support_handle = {
  0,
  &turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtle_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_interfaces, msg, TurtlesAlive)() {
  turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_interfaces, msg, TurtlePosition)();
  if (!turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_type_support_handle.typesupport_identifier) {
    turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtle_interfaces__msg__TurtlesAlive__rosidl_typesupport_introspection_c__TurtlesAlive_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
