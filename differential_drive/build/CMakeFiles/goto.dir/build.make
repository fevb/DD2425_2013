# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ghaessig/fuerte_workspace/sandbox/differential_drive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ghaessig/fuerte_workspace/sandbox/differential_drive/build

# Include any dependencies generated for this target.
include CMakeFiles/goto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/goto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/goto.dir/flags.make

CMakeFiles/goto.dir/src/goto.o: CMakeFiles/goto.dir/flags.make
CMakeFiles/goto.dir/src/goto.o: ../src/goto.cpp
CMakeFiles/goto.dir/src/goto.o: ../manifest.xml
CMakeFiles/goto.dir/src/goto.o: /opt/ros/fuerte/share/std_msgs/manifest.xml
CMakeFiles/goto.dir/src/goto.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/goto.dir/src/goto.o: /opt/ros/fuerte/share/rospy/manifest.xml
CMakeFiles/goto.dir/src/goto.o: /opt/ros/fuerte/share/roscpp/manifest.xml
CMakeFiles/goto.dir/src/goto.o: /opt/ros/fuerte/stacks/vision_opencv/opencv2/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ghaessig/fuerte_workspace/sandbox/differential_drive/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/goto.dir/src/goto.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/goto.dir/src/goto.o -c /home/ghaessig/fuerte_workspace/sandbox/differential_drive/src/goto.cpp

CMakeFiles/goto.dir/src/goto.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goto.dir/src/goto.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/ghaessig/fuerte_workspace/sandbox/differential_drive/src/goto.cpp > CMakeFiles/goto.dir/src/goto.i

CMakeFiles/goto.dir/src/goto.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goto.dir/src/goto.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/ghaessig/fuerte_workspace/sandbox/differential_drive/src/goto.cpp -o CMakeFiles/goto.dir/src/goto.s

CMakeFiles/goto.dir/src/goto.o.requires:
.PHONY : CMakeFiles/goto.dir/src/goto.o.requires

CMakeFiles/goto.dir/src/goto.o.provides: CMakeFiles/goto.dir/src/goto.o.requires
	$(MAKE) -f CMakeFiles/goto.dir/build.make CMakeFiles/goto.dir/src/goto.o.provides.build
.PHONY : CMakeFiles/goto.dir/src/goto.o.provides

CMakeFiles/goto.dir/src/goto.o.provides.build: CMakeFiles/goto.dir/src/goto.o

# Object files for target goto
goto_OBJECTS = \
"CMakeFiles/goto.dir/src/goto.o"

# External object files for target goto
goto_EXTERNAL_OBJECTS =

../bin/goto: CMakeFiles/goto.dir/src/goto.o
../bin/goto: CMakeFiles/goto.dir/build.make
../bin/goto: CMakeFiles/goto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/goto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/goto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/goto.dir/build: ../bin/goto
.PHONY : CMakeFiles/goto.dir/build

CMakeFiles/goto.dir/requires: CMakeFiles/goto.dir/src/goto.o.requires
.PHONY : CMakeFiles/goto.dir/requires

CMakeFiles/goto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/goto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/goto.dir/clean

CMakeFiles/goto.dir/depend:
	cd /home/ghaessig/fuerte_workspace/sandbox/differential_drive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ghaessig/fuerte_workspace/sandbox/differential_drive /home/ghaessig/fuerte_workspace/sandbox/differential_drive /home/ghaessig/fuerte_workspace/sandbox/differential_drive/build /home/ghaessig/fuerte_workspace/sandbox/differential_drive/build /home/ghaessig/fuerte_workspace/sandbox/differential_drive/build/CMakeFiles/goto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/goto.dir/depend

