// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_interfaces:msg/TurtlePosition.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__BUILDER_HPP_
#define TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_interfaces/msg/detail/turtle_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtlePosition_theta
{
public:
  explicit Init_TurtlePosition_theta(::turtle_interfaces::msg::TurtlePosition & msg)
  : msg_(msg)
  {}
  ::turtle_interfaces::msg::TurtlePosition theta(::turtle_interfaces::msg::TurtlePosition::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interfaces::msg::TurtlePosition msg_;
};

class Init_TurtlePosition_y
{
public:
  explicit Init_TurtlePosition_y(::turtle_interfaces::msg::TurtlePosition & msg)
  : msg_(msg)
  {}
  Init_TurtlePosition_theta y(::turtle_interfaces::msg::TurtlePosition::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TurtlePosition_theta(msg_);
  }

private:
  ::turtle_interfaces::msg::TurtlePosition msg_;
};

class Init_TurtlePosition_x
{
public:
  explicit Init_TurtlePosition_x(::turtle_interfaces::msg::TurtlePosition & msg)
  : msg_(msg)
  {}
  Init_TurtlePosition_y x(::turtle_interfaces::msg::TurtlePosition::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TurtlePosition_y(msg_);
  }

private:
  ::turtle_interfaces::msg::TurtlePosition msg_;
};

class Init_TurtlePosition_name
{
public:
  Init_TurtlePosition_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtlePosition_x name(::turtle_interfaces::msg::TurtlePosition::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_TurtlePosition_x(msg_);
  }

private:
  ::turtle_interfaces::msg::TurtlePosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interfaces::msg::TurtlePosition>()
{
  return turtle_interfaces::msg::builder::Init_TurtlePosition_name();
}

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__BUILDER_HPP_
