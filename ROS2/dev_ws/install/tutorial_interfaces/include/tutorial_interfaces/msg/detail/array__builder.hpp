// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/Array.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_Array_member
{
public:
  Init_Array_member()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::msg::Array member(::tutorial_interfaces::msg::Array::_member_type arg)
  {
    msg_.member = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::Array msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::Array>()
{
  return tutorial_interfaces::msg::builder::Init_Array_member();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__BUILDER_HPP_
