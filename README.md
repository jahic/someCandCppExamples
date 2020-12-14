## someCandCppExamples
Just few tests in C and Cpp. Code I find useful. Bugs possible. Use it at your own responsibility. More comming soon...

## ArraySpecificOperations
This folder contains two projects: LoopIntensiveOperationsInC in C and StaticAndDynamic2DArrays in C++. These should serve as an idea on how to parallelize intensive operation loops and integrate them in ROS infrastructure.

## ROS2
This folder contains a ros2 workspace named dev_ws. Inside this workspace there is a project called starting_point. Please consult dev_ws/src/starting_point/src/minimal_examples.cpp for more information.

## Requirements
ROS2 - https://index.ros.org/doc/ros2/Installation/Foxy/Linux-Install-Debians/

## Compilation and Execution
```
~$ cd dev_ws
~/dev_ws$ colcon_build
~/dev_ws$ ./build/starting_point/minimal_examples
```