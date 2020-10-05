cmake_minimum_required(VERSION 3.16)
project(Uncoupled)

set(CMAKE_CXX_STANDARD 17)

add_library(Uncoupled Uncoupled.cpp Uncoupled.h)
target_link_libraries(Uncoupled pthread)
