# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/scott/Desktop/LeveldbFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/scott/Desktop/LeveldbFinal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/read_sst.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/read_sst.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/read_sst.dir/flags.make

CMakeFiles/read_sst.dir/test/read_sst.cc.o: CMakeFiles/read_sst.dir/flags.make
CMakeFiles/read_sst.dir/test/read_sst.cc.o: ../test/read_sst.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/scott/Desktop/LeveldbFinal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/read_sst.dir/test/read_sst.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/read_sst.dir/test/read_sst.cc.o -c /Users/scott/Desktop/LeveldbFinal/test/read_sst.cc

CMakeFiles/read_sst.dir/test/read_sst.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/read_sst.dir/test/read_sst.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/scott/Desktop/LeveldbFinal/test/read_sst.cc > CMakeFiles/read_sst.dir/test/read_sst.cc.i

CMakeFiles/read_sst.dir/test/read_sst.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/read_sst.dir/test/read_sst.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/scott/Desktop/LeveldbFinal/test/read_sst.cc -o CMakeFiles/read_sst.dir/test/read_sst.cc.s

# Object files for target read_sst
read_sst_OBJECTS = \
"CMakeFiles/read_sst.dir/test/read_sst.cc.o"

# External object files for target read_sst
read_sst_EXTERNAL_OBJECTS =

read_sst: CMakeFiles/read_sst.dir/test/read_sst.cc.o
read_sst: CMakeFiles/read_sst.dir/build.make
read_sst: CMakeFiles/read_sst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/scott/Desktop/LeveldbFinal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable read_sst"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/read_sst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/read_sst.dir/build: read_sst

.PHONY : CMakeFiles/read_sst.dir/build

CMakeFiles/read_sst.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/read_sst.dir/cmake_clean.cmake
.PHONY : CMakeFiles/read_sst.dir/clean

CMakeFiles/read_sst.dir/depend:
	cd /Users/scott/Desktop/LeveldbFinal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/scott/Desktop/LeveldbFinal /Users/scott/Desktop/LeveldbFinal /Users/scott/Desktop/LeveldbFinal/cmake-build-debug /Users/scott/Desktop/LeveldbFinal/cmake-build-debug /Users/scott/Desktop/LeveldbFinal/cmake-build-debug/CMakeFiles/read_sst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/read_sst.dir/depend
