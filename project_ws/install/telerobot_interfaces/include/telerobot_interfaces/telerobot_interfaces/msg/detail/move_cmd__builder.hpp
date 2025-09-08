// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from telerobot_interfaces:msg/MoveCmd.idl
// generated code does not contain a copyright notice

#ifndef TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__BUILDER_HPP_
#define TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "telerobot_interfaces/msg/detail/move_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace telerobot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MoveCmd_cmd
{
public:
  explicit Init_MoveCmd_cmd(::telerobot_interfaces::msg::MoveCmd & msg)
  : msg_(msg)
  {}
  ::telerobot_interfaces::msg::MoveCmd cmd(::telerobot_interfaces::msg::MoveCmd::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::telerobot_interfaces::msg::MoveCmd msg_;
};

class Init_MoveCmd_joy_y
{
public:
  explicit Init_MoveCmd_joy_y(::telerobot_interfaces::msg::MoveCmd & msg)
  : msg_(msg)
  {}
  Init_MoveCmd_cmd joy_y(::telerobot_interfaces::msg::MoveCmd::_joy_y_type arg)
  {
    msg_.joy_y = std::move(arg);
    return Init_MoveCmd_cmd(msg_);
  }

private:
  ::telerobot_interfaces::msg::MoveCmd msg_;
};

class Init_MoveCmd_joy_x
{
public:
  Init_MoveCmd_joy_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveCmd_joy_y joy_x(::telerobot_interfaces::msg::MoveCmd::_joy_x_type arg)
  {
    msg_.joy_x = std::move(arg);
    return Init_MoveCmd_joy_y(msg_);
  }

private:
  ::telerobot_interfaces::msg::MoveCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::telerobot_interfaces::msg::MoveCmd>()
{
  return telerobot_interfaces::msg::builder::Init_MoveCmd_joy_x();
}

}  // namespace telerobot_interfaces

#endif  // TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__BUILDER_HPP_
