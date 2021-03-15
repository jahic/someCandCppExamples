// generated from rosidl_typesupport_connext_cpp/resource/idl__rosidl_typesupport_connext_cpp.hpp.em
// with input from tutorial_interfaces:msg/Array.idl
// generated code does not contain a copyright notice


#ifndef TUTORIAL_INTERFACES__MSG__ARRAY__ROSIDL_TYPESUPPORT_CONNEXT_CPP_HPP_
#define TUTORIAL_INTERFACES__MSG__ARRAY__ROSIDL_TYPESUPPORT_CONNEXT_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_connext_cpp__visibility_control.h"
#include "tutorial_interfaces/msg/detail/array__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif

#include "tutorial_interfaces/msg/dds_connext/Array_Support.h"
#include "tutorial_interfaces/msg/dds_connext/Array_Plugin.h"
#include "ndds/ndds_cpp.h"

#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// forward declaration of internal CDR Stream
struct ConnextStaticCDRStream;

// forward declaration of DDS types
class DDSDomainParticipant;
class DDSDataWriter;
class DDSDataReader;


namespace tutorial_interfaces
{

namespace msg
{
namespace typesupport_connext_cpp
{

DDS_TypeCode *
get_type_code__Array();

bool
ROSIDL_TYPESUPPORT_CONNEXT_CPP_PUBLIC_tutorial_interfaces
convert_ros_message_to_dds(
  const tutorial_interfaces::msg::Array & ros_message,
  tutorial_interfaces::msg::dds_::Array_ & dds_message);

bool
ROSIDL_TYPESUPPORT_CONNEXT_CPP_PUBLIC_tutorial_interfaces
convert_dds_message_to_ros(
  const tutorial_interfaces::msg::dds_::Array_ & dds_message,
  tutorial_interfaces::msg::Array & ros_message);

bool
to_cdr_stream__Array(
  const void * untyped_ros_message,
  ConnextStaticCDRStream * cdr_stream);

bool
to_message__Array(
  const ConnextStaticCDRStream * cdr_stream,
  void * untyped_ros_message);

}  // namespace typesupport_connext_cpp

}  // namespace msg

}  // namespace tutorial_interfaces


#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CONNEXT_CPP_PUBLIC_tutorial_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_connext_cpp,
  tutorial_interfaces, msg,
  Array)();

#ifdef __cplusplus
}
#endif


#endif  // TUTORIAL_INTERFACES__MSG__ARRAY__ROSIDL_TYPESUPPORT_CONNEXT_CPP_HPP_
