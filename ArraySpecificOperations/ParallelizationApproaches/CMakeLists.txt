cmake_minimum_required (VERSION 2.8)

project(ParallelizationApproaches LANGUAGES CXX)

find_package(Threads)
find_package(OpenMP REQUIRED)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )



# Common infrastructure for kernels to manipulate their arrays.
add_executable(MatrixMultiplication src/MatrixMultiplication.cpp)
add_executable(ImageGrayscaling src/ImageGrayscaling.cpp)
add_executable(GrayscaleParallel src/GrayscaleParallel.cpp)
add_executable(Filtering src/Filtering.cpp)
add_executable(Priority src/priority.cpp)
add_executable(Adjoint src/Adjoint.cpp)

target_link_libraries(Priority PRIVATE Threads::Threads)

target_link_libraries(ImageGrayscaling ${OpenCV_LIBS})
target_link_libraries(GrayscaleParallel ${OpenCV_LIBS} "${OpenMP_CXX_FLAGS}")
target_link_libraries(MatrixMultiplication PRIVATE "${OpenMP_CXX_FLAGS}")
target_compile_options(MatrixMultiplication PRIVATE "${OpenMP_CXX_FLAGS}")

target_link_libraries(Filtering PRIVATE "${OpenMP_CXX_FLAGS}")
target_compile_options(Filtering PRIVATE "${OpenMP_CXX_FLAGS}")

