// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/LedState.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/led_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LedState & msg,
  std::ostream & out)
{
  out << "{";
  // member: leds
  {
    if (msg.leds.size() == 0) {
      out << "leds: []";
    } else {
      out << "leds: [";
      size_t pending_items = msg.leds.size();
      for (auto item : msg.leds) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: led_state
  {
    out << "led_state: ";
    rosidl_generator_traits::value_to_yaml(msg.led_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LedState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: leds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.leds.size() == 0) {
      out << "leds: []\n";
    } else {
      out << "leds:\n";
      for (auto item : msg.leds) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: led_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "led_state: ";
    rosidl_generator_traits::value_to_yaml(msg.led_state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LedState & msg, bool use_flow_style = false)
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

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::msg::LedState & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::LedState & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::LedState>()
{
  return "my_robot_interfaces::msg::LedState";
}

template<>
inline const char * name<my_robot_interfaces::msg::LedState>()
{
  return "my_robot_interfaces/msg/LedState";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::LedState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::LedState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::msg::LedState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE__TRAITS_HPP_
