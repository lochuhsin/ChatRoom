# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/albertlo/Desktop/chatroom/chatroom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/albertlo/Desktop/chatroom/chatroom/build

# Include any dependencies generated for this target.
include CMakeFiles/my-project-exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my-project-exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my-project-exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my-project-exe.dir/flags.make

CMakeFiles/my-project-exe.dir/src/App.cpp.o: CMakeFiles/my-project-exe.dir/flags.make
CMakeFiles/my-project-exe.dir/src/App.cpp.o: ../src/App.cpp
CMakeFiles/my-project-exe.dir/src/App.cpp.o: CMakeFiles/my-project-exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertlo/Desktop/chatroom/chatroom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my-project-exe.dir/src/App.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-project-exe.dir/src/App.cpp.o -MF CMakeFiles/my-project-exe.dir/src/App.cpp.o.d -o CMakeFiles/my-project-exe.dir/src/App.cpp.o -c /Users/albertlo/Desktop/chatroom/chatroom/src/App.cpp

CMakeFiles/my-project-exe.dir/src/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my-project-exe.dir/src/App.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertlo/Desktop/chatroom/chatroom/src/App.cpp > CMakeFiles/my-project-exe.dir/src/App.cpp.i

CMakeFiles/my-project-exe.dir/src/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my-project-exe.dir/src/App.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertlo/Desktop/chatroom/chatroom/src/App.cpp -o CMakeFiles/my-project-exe.dir/src/App.cpp.s

# Object files for target my-project-exe
my__project__exe_OBJECTS = \
"CMakeFiles/my-project-exe.dir/src/App.cpp.o"

# External object files for target my-project-exe
my__project__exe_EXTERNAL_OBJECTS =

my-project-exe: CMakeFiles/my-project-exe.dir/src/App.cpp.o
my-project-exe: CMakeFiles/my-project-exe.dir/build.make
my-project-exe: libmy-project-lib.a
my-project-exe: /usr/local/lib/oatpp-1.3.0/liboatpp-test.a
my-project-exe: /usr/local/lib/oatpp-1.3.0/liboatpp.a
my-project-exe: CMakeFiles/my-project-exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/albertlo/Desktop/chatroom/chatroom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my-project-exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my-project-exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my-project-exe.dir/build: my-project-exe
.PHONY : CMakeFiles/my-project-exe.dir/build

CMakeFiles/my-project-exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my-project-exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my-project-exe.dir/clean

CMakeFiles/my-project-exe.dir/depend:
	cd /Users/albertlo/Desktop/chatroom/chatroom/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/albertlo/Desktop/chatroom/chatroom /Users/albertlo/Desktop/chatroom/chatroom /Users/albertlo/Desktop/chatroom/chatroom/build /Users/albertlo/Desktop/chatroom/chatroom/build /Users/albertlo/Desktop/chatroom/chatroom/build/CMakeFiles/my-project-exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my-project-exe.dir/depend

