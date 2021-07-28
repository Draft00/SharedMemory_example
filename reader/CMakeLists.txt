cmake_minimum_required(VERSION 3.19)
project(SharedMemory_example)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrt")


add_executable(reader reader.cpp)
target_link_libraries (reader rt)