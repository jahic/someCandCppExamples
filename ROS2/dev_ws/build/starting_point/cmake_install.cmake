# Install script for directory: /home/arian/dev_ws/src/starting_point

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/arian/dev_ws/install/starting_point")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/starting_point" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/starting_point")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/starting_point"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/starting_point" TYPE EXECUTABLE FILES "/home/arian/dev_ws/build/starting_point/starting_point")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/starting_point" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/starting_point")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/starting_point"
         OLD_RPATH "/home/arian/ros2_foxy/install/rclcpp/lib:/home/arian/ros2_foxy/install/libstatistics_collector/lib:/home/arian/ros2_foxy/install/std_msgs/lib:/home/arian/ros2_foxy/install/rcl/lib:/home/arian/ros2_foxy/install/rcl_interfaces/lib:/home/arian/ros2_foxy/install/rmw_implementation/lib:/home/arian/ros2_foxy/install/rmw/lib:/home/arian/ros2_foxy/install/rcl_logging_spdlog/lib:/home/arian/ros2_foxy/install/rcl_yaml_param_parser/lib:/home/arian/ros2_foxy/install/libyaml_vendor/lib:/home/arian/ros2_foxy/install/rosgraph_msgs/lib:/home/arian/ros2_foxy/install/statistics_msgs/lib:/home/arian/ros2_foxy/install/builtin_interfaces/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_c/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_introspection_cpp/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_introspection_c/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_cpp/lib:/home/arian/ros2_foxy/install/rcpputils/lib:/home/arian/ros2_foxy/install/rosidl_runtime_c/lib:/home/arian/ros2_foxy/install/rcutils/lib:/home/arian/ros2_foxy/install/tracetools/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/starting_point")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/minimal_examples" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/minimal_examples")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/minimal_examples"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/starting_point" TYPE EXECUTABLE FILES "/home/arian/dev_ws/build/starting_point/minimal_examples")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/minimal_examples" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/minimal_examples")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/minimal_examples"
         OLD_RPATH "/home/arian/ros2_foxy/install/rclcpp/lib:/home/arian/ros2_foxy/install/libstatistics_collector/lib:/home/arian/ros2_foxy/install/std_msgs/lib:/home/arian/ros2_foxy/install/rcl/lib:/home/arian/ros2_foxy/install/rcl_interfaces/lib:/home/arian/ros2_foxy/install/rmw_implementation/lib:/home/arian/ros2_foxy/install/rmw/lib:/home/arian/ros2_foxy/install/rcl_logging_spdlog/lib:/home/arian/ros2_foxy/install/rcl_yaml_param_parser/lib:/home/arian/ros2_foxy/install/libyaml_vendor/lib:/home/arian/ros2_foxy/install/rosgraph_msgs/lib:/home/arian/ros2_foxy/install/statistics_msgs/lib:/home/arian/ros2_foxy/install/builtin_interfaces/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_c/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_introspection_cpp/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_introspection_c/lib:/home/arian/ros2_foxy/install/rosidl_typesupport_cpp/lib:/home/arian/ros2_foxy/install/rcpputils/lib:/home/arian/ros2_foxy/install/rosidl_runtime_c/lib:/home/arian/ros2_foxy/install/rcutils/lib:/home/arian/ros2_foxy/install/tracetools/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/starting_point/minimal_examples")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/starting_point")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/starting_point")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point/environment" TYPE FILE FILES "/home/arian/ros2_foxy/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point/environment" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point/environment" TYPE FILE FILES "/home/arian/ros2_foxy/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point/environment" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/arian/dev_ws/build/starting_point/ament_cmake_index/share/ament_index/resource_index/packages/starting_point")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point/cmake" TYPE FILE FILES
    "/home/arian/dev_ws/build/starting_point/ament_cmake_core/starting_pointConfig.cmake"
    "/home/arian/dev_ws/build/starting_point/ament_cmake_core/starting_pointConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/starting_point" TYPE FILE FILES "/home/arian/dev_ws/src/starting_point/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/arian/dev_ws/build/starting_point/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
