# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/Engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Engine.dir/flags.make

CMakeFiles/Engine.dir/main.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/main.cpp.o: /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Engine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/main.cpp.o -c /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/main.cpp

CMakeFiles/Engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/main.cpp > CMakeFiles/Engine.dir/main.cpp.i

CMakeFiles/Engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/main.cpp -o CMakeFiles/Engine.dir/main.cpp.s

CMakeFiles/Engine.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Engine.dir/main.cpp.o.requires

CMakeFiles/Engine.dir/main.cpp.o.provides: CMakeFiles/Engine.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Engine.dir/build.make CMakeFiles/Engine.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Engine.dir/main.cpp.o.provides

CMakeFiles/Engine.dir/main.cpp.o.provides.build: CMakeFiles/Engine.dir/main.cpp.o


CMakeFiles/Engine.dir/catmullrom.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/catmullrom.cpp.o: /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/catmullrom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Engine.dir/catmullrom.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/catmullrom.cpp.o -c /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/catmullrom.cpp

CMakeFiles/Engine.dir/catmullrom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/catmullrom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/catmullrom.cpp > CMakeFiles/Engine.dir/catmullrom.cpp.i

CMakeFiles/Engine.dir/catmullrom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/catmullrom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/catmullrom.cpp -o CMakeFiles/Engine.dir/catmullrom.cpp.s

CMakeFiles/Engine.dir/catmullrom.cpp.o.requires:

.PHONY : CMakeFiles/Engine.dir/catmullrom.cpp.o.requires

CMakeFiles/Engine.dir/catmullrom.cpp.o.provides: CMakeFiles/Engine.dir/catmullrom.cpp.o.requires
	$(MAKE) -f CMakeFiles/Engine.dir/build.make CMakeFiles/Engine.dir/catmullrom.cpp.o.provides.build
.PHONY : CMakeFiles/Engine.dir/catmullrom.cpp.o.provides

CMakeFiles/Engine.dir/catmullrom.cpp.o.provides.build: CMakeFiles/Engine.dir/catmullrom.cpp.o


# Object files for target Engine
Engine_OBJECTS = \
"CMakeFiles/Engine.dir/main.cpp.o" \
"CMakeFiles/Engine.dir/catmullrom.cpp.o"

# External object files for target Engine
Engine_EXTERNAL_OBJECTS =

Engine: CMakeFiles/Engine.dir/main.cpp.o
Engine: CMakeFiles/Engine.dir/catmullrom.cpp.o
Engine: CMakeFiles/Engine.dir/build.make
Engine: /usr/lib/x86_64-linux-gnu/libGLEW.so
Engine: /usr/lib/x86_64-linux-gnu/libIL.so
Engine: /usr/lib/x86_64-linux-gnu/libGL.so
Engine: /usr/lib/x86_64-linux-gnu/libGLU.so
Engine: /usr/lib/x86_64-linux-gnu/libglut.so
Engine: /usr/lib/x86_64-linux-gnu/libXmu.so
Engine: /usr/lib/x86_64-linux-gnu/libXi.so
Engine: /usr/lib/x86_64-linux-gnu/libGL.so
Engine: /usr/lib/x86_64-linux-gnu/libGLU.so
Engine: /usr/lib/x86_64-linux-gnu/libGLEW.so
Engine: /usr/lib/x86_64-linux-gnu/libGL.so
Engine: /usr/lib/x86_64-linux-gnu/libGLU.so
Engine: /usr/lib/x86_64-linux-gnu/libIL.so
Engine: /usr/lib/x86_64-linux-gnu/libglut.so
Engine: /usr/lib/x86_64-linux-gnu/libXmu.so
Engine: /usr/lib/x86_64-linux-gnu/libXi.so
Engine: CMakeFiles/Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Engine"
	/usr/bin/cmake -E copy_directory /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/../../exemplos/Figures /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build
	/usr/bin/cmake -E copy_directory /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code/../../exemplos/SolarSystem /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Engine.dir/build: Engine

.PHONY : CMakeFiles/Engine.dir/build

CMakeFiles/Engine.dir/requires: CMakeFiles/Engine.dir/main.cpp.o.requires
CMakeFiles/Engine.dir/requires: CMakeFiles/Engine.dir/catmullrom.cpp.o.requires

.PHONY : CMakeFiles/Engine.dir/requires

CMakeFiles/Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Engine.dir/clean

CMakeFiles/Engine.dir/depend:
	cd /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/code /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build /home/francisco/Desktop/cg-solarsystem/Fase4-Grupo14/Engine/build/CMakeFiles/Engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Engine.dir/depend

