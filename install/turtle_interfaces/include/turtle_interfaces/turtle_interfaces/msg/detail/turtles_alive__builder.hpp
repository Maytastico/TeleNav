// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_interfaces:msg/TurtlesAlive.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__BUILDER_HPP_
#define TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_interfaces/msg/detail/turtles_alive__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtlesAlive_turtles
{
public:
  Init_TurtlesAlive_turtles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_interfaces::msg::TurtlesAlive turtles(::turtle_interfaces::msg::TurtlesAlive::_turtles_type arg)
  {
    msg_.turtles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interfaces::msg::TurtlesAlive msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interfaces::msg::TurtlesAlive>()
{
  return turtle_interfaces::msg::builder::Init_TurtlesAlive_turtles();
}

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__BUILDER_HPP_
