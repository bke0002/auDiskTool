cmake_minimum_required(VERSION 3.2)
project(auDiskTool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(auDiskTool ${SOURCE_FILES} src/config_info.h)