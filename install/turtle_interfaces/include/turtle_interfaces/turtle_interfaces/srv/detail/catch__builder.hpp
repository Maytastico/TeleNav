// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_interfaces:srv/Catch.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__SRV__DETAIL__CATCH__BUILDER_HPP_
#define TURTLE_INTERFACES__SRV__DETAIL__CATCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_interfaces/srv/detail/catch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_Catch_Request_catch_turtle
{
public:
  explicit Init_Catch_Request_catch_turtle(::turtle_interfaces::srv::Catch_Request & msg)
  : msg_(msg)
  {}
  ::turtle_interfaces::srv::Catch_Request catch_turtle(::turtle_interfaces::srv::Catch_Request::_catch_turtle_type arg)
  {
    msg_.catch_turtle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interfaces::srv::Catch_Request msg_;
};

class Init_Catch_Request_own_turtle
{
public:
  Init_Catch_Request_own_turtle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Catch_Request_catch_turtle own_turtle(::turtle_interfaces::srv::Catch_Request::_own_turtle_type arg)
  {
    msg_.own_turtle = std::move(arg);
    return Init_Catch_Request_catch_turtle(msg_);
  }

private:
  ::turtle_interfaces::srv::Catch_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interfaces::srv::Catch_Request>()
{
  return turtle_interfaces::srv::builder::Init_Catch_Request_own_turtle();
}

}  // namespace turtle_interfaces


namespace turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_Catch_Response_success
{
public:
  Init_Catch_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_interfaces::srv::Catch_Response success(::turtle_interfaces::srv::Catch_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interfaces::srv::Catch_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interfaces::srv::Catch_Response>()
{
  return turtle_interfaces::srv::builder::Init_Catch_Response_success();
}

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__SRV__DETAIL__CATCH__BUILDER_HPP_
