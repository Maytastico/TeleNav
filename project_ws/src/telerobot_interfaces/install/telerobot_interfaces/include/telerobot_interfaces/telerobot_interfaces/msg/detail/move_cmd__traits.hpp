// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from telerobot_interfaces:msg/MoveCmd.idl
// generated code does not contain a copyright notice

#ifndef TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__TRAITS_HPP_
#define TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "telerobot_interfaces/msg/detail/move_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace telerobot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MoveCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd
  {
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveCmd & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace telerobot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use telerobot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const telerobot_interfaces::msg::MoveCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  telerobot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use telerobot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const telerobot_interfaces::msg::MoveCmd & msg)
{
  return telerobot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<telerobot_interfaces::msg::MoveCmd>()
{
  return "telerobot_interfaces::msg::MoveCmd";
}

template<>
inline const char * name<telerobot_interfaces::msg::MoveCmd>()
{
  return "telerobot_interfaces/msg/MoveCmd";
}

template<>
struct has_fixed_size<telerobot_interfaces::msg::MoveCmd>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<telerobot_interfaces::msg::MoveCmd>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<telerobot_interfaces::msg::MoveCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__TRAITS_HPP_
