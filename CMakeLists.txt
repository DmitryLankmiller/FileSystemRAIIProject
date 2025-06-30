cmake_minimum_required(VERSION 3.10)
project(FileSystemRAIIProject)

set(CMAKE_CXX_STANDARD 17)

add_library(filelib FileSystemRAII.cpp)
add_executable(main main.cpp)

target_link_libraries(main filelib)
