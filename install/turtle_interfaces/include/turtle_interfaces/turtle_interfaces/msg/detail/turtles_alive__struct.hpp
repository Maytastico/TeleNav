// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_interfaces:msg/TurtlesAlive.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__STRUCT_HPP_
#define TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'turtles'
#include "turtle_interfaces/msg/detail/turtle_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turtle_interfaces__msg__TurtlesAlive __attribute__((deprecated))
#else
# define DEPRECATED__turtle_interfaces__msg__TurtlesAlive __declspec(deprecated)
#endif

namespace turtle_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurtlesAlive_
{
  using Type = TurtlesAlive_<ContainerAllocator>;

  explicit TurtlesAlive_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit TurtlesAlive_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _turtles_type =
    std::vector<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>>>;
  _turtles_type turtles;

  // setters for named parameter idiom
  Type & set__turtles(
    const std::vector<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>>> & _arg)
  {
    this->turtles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_interfaces__msg__TurtlesAlive
    std::shared_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_interfaces__msg__TurtlesAlive
    std::shared_ptr<turtle_interfaces::msg::TurtlesAlive_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtlesAlive_ & other) const
  {
    if (this->turtles != other.turtles) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtlesAlive_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtlesAlive_

// alias to use template instance with default allocator
using TurtlesAlive =
  turtle_interfaces::msg::TurtlesAlive_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__MSG__DETAIL__TURTLES_ALIVE__STRUCT_HPP_
