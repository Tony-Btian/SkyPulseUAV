# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/Flight_Control_System.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Flight_Control_System.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Flight_Control_System.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Flight_Control_System.dir/flags.make

CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o: CMakeFiles/Flight_Control_System.dir/flags.make
CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o: Flight_Control_System_autogen/mocs_compilation.cpp
CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o: CMakeFiles/Flight_Control_System.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o -MF CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o -c /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/Flight_Control_System_autogen/mocs_compilation.cpp

CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/Flight_Control_System_autogen/mocs_compilation.cpp > CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.i

CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/Flight_Control_System_autogen/mocs_compilation.cpp -o CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.s

CMakeFiles/Flight_Control_System.dir/main.cpp.o: CMakeFiles/Flight_Control_System.dir/flags.make
CMakeFiles/Flight_Control_System.dir/main.cpp.o: /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/main.cpp
CMakeFiles/Flight_Control_System.dir/main.cpp.o: CMakeFiles/Flight_Control_System.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Flight_Control_System.dir/main.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Flight_Control_System.dir/main.cpp.o -MF CMakeFiles/Flight_Control_System.dir/main.cpp.o.d -o CMakeFiles/Flight_Control_System.dir/main.cpp.o -c /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/main.cpp

CMakeFiles/Flight_Control_System.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Control_System.dir/main.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/main.cpp > CMakeFiles/Flight_Control_System.dir/main.cpp.i

CMakeFiles/Flight_Control_System.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Control_System.dir/main.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/main.cpp -o CMakeFiles/Flight_Control_System.dir/main.cpp.s

CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o: CMakeFiles/Flight_Control_System.dir/flags.make
CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o: /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/ThreadPool.cpp
CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o: CMakeFiles/Flight_Control_System.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o -MF CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o.d -o CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o -c /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/ThreadPool.cpp

CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/ThreadPool.cpp > CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.i

CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System/ThreadPool.cpp -o CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.s

# Object files for target Flight_Control_System
Flight_Control_System_OBJECTS = \
"CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Flight_Control_System.dir/main.cpp.o" \
"CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o"

# External object files for target Flight_Control_System
Flight_Control_System_EXTERNAL_OBJECTS =

Flight_Control_System: CMakeFiles/Flight_Control_System.dir/Flight_Control_System_autogen/mocs_compilation.cpp.o
Flight_Control_System: CMakeFiles/Flight_Control_System.dir/main.cpp.o
Flight_Control_System: CMakeFiles/Flight_Control_System.dir/ThreadPool.cpp.o
Flight_Control_System: CMakeFiles/Flight_Control_System.dir/build.make
Flight_Control_System: /usr/lib/aarch64-linux-gnu/libQt5Core.so.5.15.8
Flight_Control_System: CMakeFiles/Flight_Control_System.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Flight_Control_System"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Flight_Control_System.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Flight_Control_System.dir/build: Flight_Control_System
.PHONY : CMakeFiles/Flight_Control_System.dir/build

CMakeFiles/Flight_Control_System.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Flight_Control_System.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Flight_Control_System.dir/clean

CMakeFiles/Flight_Control_System.dir/depend:
	cd /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/Flight_Control_System /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug /home/tony/Workspace/SkyPulseUVA/SkyPulseUVA_FCS/build-Flight_Control_System-Desktop-Debug/CMakeFiles/Flight_Control_System.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Flight_Control_System.dir/depend

