# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "/Users/prakhar/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.3283.6/CLion 2018.3 EAP.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/prakhar/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.3283.6/CLion 2018.3 EAP.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/tictactoe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tictactoe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tictactoe.dir/flags.make

CMakeFiles/tictactoe.dir/tests/test.cpp.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/tests/test.cpp.o: ../tests/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tictactoe.dir/tests/test.cpp.o"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/tests/test.cpp.o -c "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/tests/test.cpp"

CMakeFiles/tictactoe.dir/tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/tests/test.cpp.i"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/tests/test.cpp" > CMakeFiles/tictactoe.dir/tests/test.cpp.i

CMakeFiles/tictactoe.dir/tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/tests/test.cpp.s"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/tests/test.cpp" -o CMakeFiles/tictactoe.dir/tests/test.cpp.s

CMakeFiles/tictactoe.dir/main.cpp.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tictactoe.dir/main.cpp.o"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/main.cpp.o -c "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/main.cpp"

CMakeFiles/tictactoe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/main.cpp.i"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/main.cpp" > CMakeFiles/tictactoe.dir/main.cpp.i

CMakeFiles/tictactoe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/main.cpp.s"
	/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/main.cpp" -o CMakeFiles/tictactoe.dir/main.cpp.s

# Object files for target tictactoe
tictactoe_OBJECTS = \
"CMakeFiles/tictactoe.dir/tests/test.cpp.o" \
"CMakeFiles/tictactoe.dir/main.cpp.o"

# External object files for target tictactoe
tictactoe_EXTERNAL_OBJECTS =

tictactoe: CMakeFiles/tictactoe.dir/tests/test.cpp.o
tictactoe: CMakeFiles/tictactoe.dir/main.cpp.o
tictactoe: CMakeFiles/tictactoe.dir/build.make
tictactoe: CMakeFiles/tictactoe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tictactoe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tictactoe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tictactoe.dir/build: tictactoe

.PHONY : CMakeFiles/tictactoe.dir/build

CMakeFiles/tictactoe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tictactoe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tictactoe.dir/clean

CMakeFiles/tictactoe.dir/depend:
	cd "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe" "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe" "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug" "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug" "/Users/prakhar/Desktop/Prakhar/Git Clone/tictactoe/cmake-build-debug/CMakeFiles/tictactoe.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tictactoe.dir/depend
