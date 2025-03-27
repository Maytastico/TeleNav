// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_interfaces:msg/TurtlePosition.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__STRUCT_HPP_
#define TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_interfaces__msg__TurtlePosition __attribute__((deprecated))
#else
# define DEPRECATED__turtle_interfaces__msg__TurtlePosition __declspec(deprecated)
#endif

namespace turtle_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurtlePosition_
{
  using Type = TurtlePosition_<ContainerAllocator>;

  explicit TurtlePosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
    }
  }

  explicit TurtlePosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _theta_type =
    float;
  _theta_type theta;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const float & _arg)
  {
    this->theta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_interfaces__msg__TurtlePosition
    std::shared_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_interfaces__msg__TurtlePosition
    std::shared_ptr<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtlePosition_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtlePosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtlePosition_

// alias to use template instance with default allocator
using TurtlePosition =
  turtle_interfaces::msg::TurtlePosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__MSG__DETAIL__TURTLE_POSITION__STRUCT_HPP_
