// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/Array.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'member'
#include "tutorial_interfaces/msg/detail/num__struct.h"

// Struct defined in msg/Array in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__Array
{
  tutorial_interfaces__msg__Num__Sequence member;
} tutorial_interfaces__msg__Array;

// Struct for a sequence of tutorial_interfaces__msg__Array.
typedef struct tutorial_interfaces__msg__Array__Sequence
{
  tutorial_interfaces__msg__Array * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__Array__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__ARRAY__STRUCT_H_
