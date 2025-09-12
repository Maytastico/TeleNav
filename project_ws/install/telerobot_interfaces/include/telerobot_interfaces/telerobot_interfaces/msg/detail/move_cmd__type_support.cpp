// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from telerobot_interfaces:msg/MoveCmd.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "telerobot_interfaces/msg/detail/move_cmd__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace telerobot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveCmd_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) telerobot_interfaces::msg::MoveCmd(_init);
}

void MoveCmd_fini_function(void * message_memory)
{
  auto typed_message = static_cast<telerobot_interfaces::msg::MoveCmd *>(message_memory);
  typed_message->~MoveCmd();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveCmd_message_member_array[3] = {
  {
    "joy_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telerobot_interfaces::msg::MoveCmd, joy_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joy_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telerobot_interfaces::msg::MoveCmd, joy_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "cmd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(telerobot_interfaces::msg::MoveCmd, cmd),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveCmd_message_members = {
  "telerobot_interfaces::msg",  // message namespace
  "MoveCmd",  // message name
  3,  // number of fields
  sizeof(telerobot_interfaces::msg::MoveCmd),
  MoveCmd_message_member_array,  // message members
  MoveCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveCmd_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveCmd_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveCmd_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace telerobot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<telerobot_interfaces::msg::MoveCmd>()
{
  return &::telerobot_interfaces::msg::rosidl_typesupport_introspection_cpp::MoveCmd_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, telerobot_interfaces, msg, MoveCmd)() {
  return &::telerobot_interfaces::msg::rosidl_typesupport_introspection_cpp::MoveCmd_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
