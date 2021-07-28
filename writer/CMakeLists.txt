cmake_minimum_required(VERSION 3.19)
project(SharedMemory_example)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrt")
#target_compile_options(writer PRIVATE -lrt)

add_executable(writer writer.cpp)
#target_link_libraries (writer mman)