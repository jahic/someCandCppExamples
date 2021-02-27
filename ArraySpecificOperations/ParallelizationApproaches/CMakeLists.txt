cmake_minimum_required (VERSION 2.8)

project(ParallelizationApproaches LANGUAGES CXX)

find_package(Threads)
find_package(OpenMP REQUIRED)



# Common infrastructure for kernels to manipulate their arrays.
add_executable(MatrixMultiplication src/MatrixMultiplication.cpp)
target_link_libraries(MatrixMultiplication PRIVATE "${OpenMP_CXX_FLAGS}")
target_compile_options(MatrixMultiplication PRIVATE "${OpenMP_CXX_FLAGS}")
