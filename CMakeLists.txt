cmake_minimum_required(VERSION 3.19)
project(SharedMemory_example)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("${PROJECT_SOURCE_DIR}/writer" "${PROJECT_SOURCE_DIR}/writer/writer_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/reader" "${PROJECT_SOURCE_DIR}/reader/reader_output")
