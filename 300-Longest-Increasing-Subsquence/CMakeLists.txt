cmake_minimum_required(VERSION 3.16)
project(300_Longest_Increasing_Subsequence)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11")
set(SOURCE_FILE main.cpp Solution.h)

add_executable(main ${SOURCE_FILE})