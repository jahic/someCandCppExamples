cmake_minimum_required (VERSION 2.8)

project(Core LANGUAGES CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)



# Common infrastructure for kernels to manipulate their arrays.
add_executable(core src/main.cpp)
target_link_libraries(core PRIVATE Threads::Threads)


