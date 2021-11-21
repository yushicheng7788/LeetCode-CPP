cmake_minimum_required(VERSION 3.16)
project(LeetCode_0001)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11")
set(SOURCE_FILES main.cpp Solution.h)

add_executable(main ${SOURCE_FILES})
