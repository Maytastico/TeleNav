// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from telerobot_interfaces:msg/MoveCmd.idl
// generated code does not contain a copyright notice

#ifndef TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__STRUCT_HPP_
#define TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__telerobot_interfaces__msg__MoveCmd __attribute__((deprecated))
#else
# define DEPRECATED__telerobot_interfaces__msg__MoveCmd __declspec(deprecated)
#endif

namespace telerobot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MoveCmd_
{
  using Type = MoveCmd_<ContainerAllocator>;

  explicit MoveCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joy_x = 0;
      this->joy_y = 0;
      this->cmd = 0;
    }
  }

  explicit MoveCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joy_x = 0;
      this->joy_y = 0;
      this->cmd = 0;
    }
  }

  // field types and members
  using _joy_x_type =
    int8_t;
  _joy_x_type joy_x;
  using _joy_y_type =
    int8_t;
  _joy_y_type joy_y;
  using _cmd_type =
    uint8_t;
  _cmd_type cmd;

  // setters for named parameter idiom
  Type & set__joy_x(
    const int8_t & _arg)
  {
    this->joy_x = _arg;
    return *this;
  }
  Type & set__joy_y(
    const int8_t & _arg)
  {
    this->joy_y = _arg;
    return *this;
  }
  Type & set__cmd(
    const uint8_t & _arg)
  {
    this->cmd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t STOP =
    0u;
  static constexpr uint8_t FORWARD =
    1u;
  static constexpr uint8_t BACKWARD =
    4u;
  static constexpr uint8_t TURN_LEFT =
    2u;
  static constexpr uint8_t TURN_RIGHT =
    3u;

  // pointer types
  using RawPtr =
    telerobot_interfaces::msg::MoveCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const telerobot_interfaces::msg::MoveCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      telerobot_interfaces::msg::MoveCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      telerobot_interfaces::msg::MoveCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__telerobot_interfaces__msg__MoveCmd
    std::shared_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__telerobot_interfaces__msg__MoveCmd
    std::shared_ptr<telerobot_interfaces::msg::MoveCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveCmd_ & other) const
  {
    if (this->joy_x != other.joy_x) {
      return false;
    }
    if (this->joy_y != other.joy_y) {
      return false;
    }
    if (this->cmd != other.cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveCmd_

// alias to use template instance with default allocator
using MoveCmd =
  telerobot_interfaces::msg::MoveCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MoveCmd_<ContainerAllocator>::STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MoveCmd_<ContainerAllocator>::FORWARD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MoveCmd_<ContainerAllocator>::BACKWARD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MoveCmd_<ContainerAllocator>::TURN_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MoveCmd_<ContainerAllocator>::TURN_RIGHT;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace telerobot_interfaces

#endif  // TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__STRUCT_HPP_
