cmake_minimum_required(VERSION 3.16)
project(PerformanceExperiment)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
#add_library(PerformanceExperiment "../CoupledThread/")
include_directories("../CoupledThread" "../Uncoupled")

add_executable(PerformanceExperiment main.cpp CoupledThreadOOP.cpp CoupledThreadOOP.h UncoupledOOP.cpp UncoupledOOP.h globalMacro.h)
find_library(CoupledTHREAD CoupledThread "../CoupledThread/cmake-build-debug")
find_library(Uncoupled Uncoupled "../Uncoupled/cmake-build-debug")
MESSAGE(${CoupledTHREAD})
target_link_libraries(PerformanceExperiment LINK_PUBLIC ${CoupledTHREAD} ${Uncoupled} pthread)
