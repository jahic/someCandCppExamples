# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_framework_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED framework_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(framework_FOUND FALSE)
  elseif(NOT framework_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(framework_FOUND FALSE)
  endif()
  return()
endif()
set(_framework_CONFIG_INCLUDED TRUE)

# output package information
if(NOT framework_FIND_QUIETLY)
  message(STATUS "Found framework: 0.0.0 (${framework_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'framework' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${framework_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(framework_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${framework_DIR}/${_extra}")
endforeach()
