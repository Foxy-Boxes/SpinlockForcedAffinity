# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cacoethes/CLionProjects/PerformanceExperiment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PerformanceExperiment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PerformanceExperiment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PerformanceExperiment.dir/flags.make

CMakeFiles/PerformanceExperiment.dir/main.cpp.o: CMakeFiles/PerformanceExperiment.dir/flags.make
CMakeFiles/PerformanceExperiment.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PerformanceExperiment.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PerformanceExperiment.dir/main.cpp.o -c /home/cacoethes/CLionProjects/PerformanceExperiment/main.cpp

CMakeFiles/PerformanceExperiment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PerformanceExperiment.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cacoethes/CLionProjects/PerformanceExperiment/main.cpp > CMakeFiles/PerformanceExperiment.dir/main.cpp.i

CMakeFiles/PerformanceExperiment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PerformanceExperiment.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cacoethes/CLionProjects/PerformanceExperiment/main.cpp -o CMakeFiles/PerformanceExperiment.dir/main.cpp.s

CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.o: CMakeFiles/PerformanceExperiment.dir/flags.make
CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.o: ../CoupledThreadOOP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.o -c /home/cacoethes/CLionProjects/PerformanceExperiment/CoupledThreadOOP.cpp

CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cacoethes/CLionProjects/PerformanceExperiment/CoupledThreadOOP.cpp > CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.i

CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cacoethes/CLionProjects/PerformanceExperiment/CoupledThreadOOP.cpp -o CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.s

CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.o: CMakeFiles/PerformanceExperiment.dir/flags.make
CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.o: ../UncoupledOOP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.o -c /home/cacoethes/CLionProjects/PerformanceExperiment/UncoupledOOP.cpp

CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cacoethes/CLionProjects/PerformanceExperiment/UncoupledOOP.cpp > CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.i

CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cacoethes/CLionProjects/PerformanceExperiment/UncoupledOOP.cpp -o CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.s

# Object files for target PerformanceExperiment
PerformanceExperiment_OBJECTS = \
"CMakeFiles/PerformanceExperiment.dir/main.cpp.o" \
"CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.o" \
"CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.o"

# External object files for target PerformanceExperiment
PerformanceExperiment_EXTERNAL_OBJECTS =

PerformanceExperiment: CMakeFiles/PerformanceExperiment.dir/main.cpp.o
PerformanceExperiment: CMakeFiles/PerformanceExperiment.dir/CoupledThreadOOP.cpp.o
PerformanceExperiment: CMakeFiles/PerformanceExperiment.dir/UncoupledOOP.cpp.o
PerformanceExperiment: CMakeFiles/PerformanceExperiment.dir/build.make
PerformanceExperiment: /home/cacoethes/CLionProjects/CoupledThread/cmake-build-debug/libCoupledThread.a
PerformanceExperiment: /home/cacoethes/CLionProjects/Uncoupled/cmake-build-debug/libUncoupled.a
PerformanceExperiment: CMakeFiles/PerformanceExperiment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable PerformanceExperiment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PerformanceExperiment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PerformanceExperiment.dir/build: PerformanceExperiment

.PHONY : CMakeFiles/PerformanceExperiment.dir/build

CMakeFiles/PerformanceExperiment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PerformanceExperiment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PerformanceExperiment.dir/clean

CMakeFiles/PerformanceExperiment.dir/depend:
	cd /home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cacoethes/CLionProjects/PerformanceExperiment /home/cacoethes/CLionProjects/PerformanceExperiment /home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug /home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug /home/cacoethes/CLionProjects/PerformanceExperiment/cmake-build-debug/CMakeFiles/PerformanceExperiment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PerformanceExperiment.dir/depend
