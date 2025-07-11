// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_interfaces:srv/Catch.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__SRV__DETAIL__CATCH__STRUCT_HPP_
#define TURTLE_INTERFACES__SRV__DETAIL__CATCH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'own_turtle'
// Member 'catch_turtle'
#include "turtle_interfaces/msg/detail/turtle_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turtle_interfaces__srv__Catch_Request __attribute__((deprecated))
#else
# define DEPRECATED__turtle_interfaces__srv__Catch_Request __declspec(deprecated)
#endif

namespace turtle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Catch_Request_
{
  using Type = Catch_Request_<ContainerAllocator>;

  explicit Catch_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : own_turtle(_init),
    catch_turtle(_init)
  {
    (void)_init;
  }

  explicit Catch_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : own_turtle(_alloc, _init),
    catch_turtle(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _own_turtle_type =
    turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>;
  _own_turtle_type own_turtle;
  using _catch_turtle_type =
    turtle_interfaces::msg::TurtlePosition_<ContainerAllocator>;
  _catch_turtle_type catch_turtle;

  // setters for named parameter idiom
  Type & set__own_turtle(
    const turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> & _arg)
  {
    this->own_turtle = _arg;
    return *this;
  }
  Type & set__catch_turtle(
    const turtle_interfaces::msg::TurtlePosition_<ContainerAllocator> & _arg)
  {
    this->catch_turtle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_interfaces::srv::Catch_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_interfaces::srv::Catch_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::Catch_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::Catch_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_interfaces__srv__Catch_Request
    std::shared_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_interfaces__srv__Catch_Request
    std::shared_ptr<turtle_interfaces::srv::Catch_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Catch_Request_ & other) const
  {
    if (this->own_turtle != other.own_turtle) {
      return false;
    }
    if (this->catch_turtle != other.catch_turtle) {
      return false;
    }
    return true;
  }
  bool operator!=(const Catch_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Catch_Request_

// alias to use template instance with default allocator
using Catch_Request =
  turtle_interfaces::srv::Catch_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_interfaces


#ifndef _WIN32
# define DEPRECATED__turtle_interfaces__srv__Catch_Response __attribute__((deprecated))
#else
# define DEPRECATED__turtle_interfaces__srv__Catch_Response __declspec(deprecated)
#endif

namespace turtle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Catch_Response_
{
  using Type = Catch_Response_<ContainerAllocator>;

  explicit Catch_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Catch_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_interfaces::srv::Catch_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_interfaces::srv::Catch_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::Catch_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::Catch_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_interfaces__srv__Catch_Response
    std::shared_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_interfaces__srv__Catch_Response
    std::shared_ptr<turtle_interfaces::srv::Catch_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Catch_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Catch_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Catch_Response_

// alias to use template instance with default allocator
using Catch_Response =
  turtle_interfaces::srv::Catch_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_interfaces

namespace turtle_interfaces
{

namespace srv
{

struct Catch
{
  using Request = turtle_interfaces::srv::Catch_Request;
  using Response = turtle_interfaces::srv::Catch_Response;
};

}  // namespace srv

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__SRV__DETAIL__CATCH__STRUCT_HPP_
