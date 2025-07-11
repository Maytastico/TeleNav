// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_interfaces:srv/Catch.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__SRV__DETAIL__CATCH__TRAITS_HPP_
#define TURTLE_INTERFACES__SRV__DETAIL__CATCH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_interfaces/srv/detail/catch__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'own_turtle'
// Member 'catch_turtle'
#include "turtle_interfaces/msg/detail/turtle_position__traits.hpp"

namespace turtle_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Catch_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: own_turtle
  {
    out << "own_turtle: ";
    to_flow_style_yaml(msg.own_turtle, out);
    out << ", ";
  }

  // member: catch_turtle
  {
    out << "catch_turtle: ";
    to_flow_style_yaml(msg.catch_turtle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Catch_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: own_turtle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "own_turtle:\n";
    to_block_style_yaml(msg.own_turtle, out, indentation + 2);
  }

  // member: catch_turtle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "catch_turtle:\n";
    to_block_style_yaml(msg.catch_turtle, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Catch_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtle_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_interfaces::srv::Catch_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_interfaces::srv::Catch_Request & msg)
{
  return turtle_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_interfaces::srv::Catch_Request>()
{
  return "turtle_interfaces::srv::Catch_Request";
}

template<>
inline const char * name<turtle_interfaces::srv::Catch_Request>()
{
  return "turtle_interfaces/srv/Catch_Request";
}

template<>
struct has_fixed_size<turtle_interfaces::srv::Catch_Request>
  : std::integral_constant<bool, has_fixed_size<turtle_interfaces::msg::TurtlePosition>::value> {};

template<>
struct has_bounded_size<turtle_interfaces::srv::Catch_Request>
  : std::integral_constant<bool, has_bounded_size<turtle_interfaces::msg::TurtlePosition>::value> {};

template<>
struct is_message<turtle_interfaces::srv::Catch_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turtle_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Catch_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Catch_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Catch_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtle_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_interfaces::srv::Catch_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtle_interfaces::srv::Catch_Response & msg)
{
  return turtle_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_interfaces::srv::Catch_Response>()
{
  return "turtle_interfaces::srv::Catch_Response";
}

template<>
inline const char * name<turtle_interfaces::srv::Catch_Response>()
{
  return "turtle_interfaces/srv/Catch_Response";
}

template<>
struct has_fixed_size<turtle_interfaces::srv::Catch_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_interfaces::srv::Catch_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_interfaces::srv::Catch_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtle_interfaces::srv::Catch>()
{
  return "turtle_interfaces::srv::Catch";
}

template<>
inline const char * name<turtle_interfaces::srv::Catch>()
{
  return "turtle_interfaces/srv/Catch";
}

template<>
struct has_fixed_size<turtle_interfaces::srv::Catch>
  : std::integral_constant<
    bool,
    has_fixed_size<turtle_interfaces::srv::Catch_Request>::value &&
    has_fixed_size<turtle_interfaces::srv::Catch_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtle_interfaces::srv::Catch>
  : std::integral_constant<
    bool,
    has_bounded_size<turtle_interfaces::srv::Catch_Request>::value &&
    has_bounded_size<turtle_interfaces::srv::Catch_Response>::value
  >
{
};

template<>
struct is_service<turtle_interfaces::srv::Catch>
  : std::true_type
{
};

template<>
struct is_service_request<turtle_interfaces::srv::Catch_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtle_interfaces::srv::Catch_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_INTERFACES__SRV__DETAIL__CATCH__TRAITS_HPP_
