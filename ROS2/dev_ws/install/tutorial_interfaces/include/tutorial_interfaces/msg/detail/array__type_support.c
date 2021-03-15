// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/Array.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/array__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/array__functions.h"
#include "tutorial_interfaces/msg/detail/array__struct.h"


// Include directives for member types
// Member `member`
#include "tutorial_interfaces/msg/num.h"
// Member `member`
#include "tutorial_interfaces/msg/detail/num__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Array__rosidl_typesupport_introspection_c__Array_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__Array__init(message_memory);
}

void Array__rosidl_typesupport_introspection_c__Array_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__Array__fini(message_memory);
}

size_t Array__rosidl_typesupport_introspection_c__size_function__Num__member(
  const void * untyped_member)
{
  const tutorial_interfaces__msg__Num__Sequence * member =
    (const tutorial_interfaces__msg__Num__Sequence *)(untyped_member);
  return member->size;
}

const void * Array__rosidl_typesupport_introspection_c__get_const_function__Num__member(
  const void * untyped_member, size_t index)
{
  const tutorial_interfaces__msg__Num__Sequence * member =
    (const tutorial_interfaces__msg__Num__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Array__rosidl_typesupport_introspection_c__get_function__Num__member(
  void * untyped_member, size_t index)
{
  tutorial_interfaces__msg__Num__Sequence * member =
    (tutorial_interfaces__msg__Num__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Array__rosidl_typesupport_introspection_c__resize_function__Num__member(
  void * untyped_member, size_t size)
{
  tutorial_interfaces__msg__Num__Sequence * member =
    (tutorial_interfaces__msg__Num__Sequence *)(untyped_member);
  tutorial_interfaces__msg__Num__Sequence__fini(member);
  return tutorial_interfaces__msg__Num__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember Array__rosidl_typesupport_introspection_c__Array_message_member_array[1] = {
  {
    "member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__Array, member),  // bytes offset in struct
    NULL,  // default value
    Array__rosidl_typesupport_introspection_c__size_function__Num__member,  // size() function pointer
    Array__rosidl_typesupport_introspection_c__get_const_function__Num__member,  // get_const(index) function pointer
    Array__rosidl_typesupport_introspection_c__get_function__Num__member,  // get(index) function pointer
    Array__rosidl_typesupport_introspection_c__resize_function__Num__member  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Array__rosidl_typesupport_introspection_c__Array_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "Array",  // message name
  1,  // number of fields
  sizeof(tutorial_interfaces__msg__Array),
  Array__rosidl_typesupport_introspection_c__Array_message_member_array,  // message members
  Array__rosidl_typesupport_introspection_c__Array_init_function,  // function to initialize message memory (memory has to be allocated)
  Array__rosidl_typesupport_introspection_c__Array_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Array__rosidl_typesupport_introspection_c__Array_message_type_support_handle = {
  0,
  &Array__rosidl_typesupport_introspection_c__Array_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, Array)() {
  Array__rosidl_typesupport_introspection_c__Array_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, Num)();
  if (!Array__rosidl_typesupport_introspection_c__Array_message_type_support_handle.typesupport_identifier) {
    Array__rosidl_typesupport_introspection_c__Array_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Array__rosidl_typesupport_introspection_c__Array_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
