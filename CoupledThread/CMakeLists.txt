cmake_minimum_required(VERSION 3.16)
project(CoupledThread)

set(CMAKE_CXX_STANDARD 17)


add_library(CoupledThread CoupledThread.cpp CoupledThread.h)
target_link_libraries(CoupledThread pthread)