// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/Array.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'member'
#include "tutorial_interfaces/msg/detail/num__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__Array __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__Array __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Array_
{
  using Type = Array_<ContainerAllocator>;

  explicit Array_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Array_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _member_type =
    std::vector<tutorial_interfaces::msg::Num_<ContainerAllocator>, typename ContainerAllocator::template rebind<tutorial_interfaces::msg::Num_<ContainerAllocator>>::other>;
  _member_type member;

  // setters for named parameter idiom
  Type & set__member(
    const std::vector<tutorial_interfaces::msg::Num_<ContainerAllocator>, typename ContainerAllocator::template rebind<tutorial_interfaces::msg::Num_<ContainerAllocator>>::other> & _arg)
  {
    this->member = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::Array_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::Array_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::Array_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::Array_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__Array
    std::shared_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__Array
    std::shared_ptr<tutorial_interfaces::msg::Array_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Array_ & other) const
  {
    if (this->member != other.member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Array_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Array_

// alias to use template instance with default allocator
using Array =
  tutorial_interfaces::msg::Array_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__STRUCT_HPP_
