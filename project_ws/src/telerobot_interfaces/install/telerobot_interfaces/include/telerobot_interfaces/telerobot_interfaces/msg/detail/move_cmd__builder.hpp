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
  Init_MoveCmd_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::telerobot_interfaces::msg::MoveCmd cmd(::telerobot_interfaces::msg::MoveCmd::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
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
  return telerobot_interfaces::msg::builder::Init_MoveCmd_cmd();
}

}  // namespace telerobot_interfaces

#endif  // TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__BUILDER_HPP_
