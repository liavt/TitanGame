# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/liavt/Desktop/TitanGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liavt/Desktop/TitanGame/build

# Include any dependencies generated for this target.
include MACE/CMakeFiles/MACE-Cleaning.dir/depend.make

# Include the progress variables for this target.
include MACE/CMakeFiles/MACE-Cleaning.dir/progress.make

# Include the compile flags for this target's objects.
include MACE/CMakeFiles/MACE-Cleaning.dir/flags.make

MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o: MACE/CMakeFiles/MACE-Cleaning.dir/flags.make
MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o: ../MACE/demos/Cleaning.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liavt/Desktop/TitanGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o"
	cd /home/liavt/Desktop/TitanGame/build/MACE && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o -c /home/liavt/Desktop/TitanGame/MACE/demos/Cleaning.cpp

MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.i"
	cd /home/liavt/Desktop/TitanGame/build/MACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liavt/Desktop/TitanGame/MACE/demos/Cleaning.cpp > CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.i

MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.s"
	cd /home/liavt/Desktop/TitanGame/build/MACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liavt/Desktop/TitanGame/MACE/demos/Cleaning.cpp -o CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.s

MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.requires:

.PHONY : MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.requires

MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.provides: MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.requires
	$(MAKE) -f MACE/CMakeFiles/MACE-Cleaning.dir/build.make MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.provides.build
.PHONY : MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.provides

MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.provides.build: MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o


# Object files for target MACE-Cleaning
MACE__Cleaning_OBJECTS = \
"CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o"

# External object files for target MACE-Cleaning
MACE__Cleaning_EXTERNAL_OBJECTS =

MACE/MACE-Cleaning: MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o
MACE/MACE-Cleaning: MACE/CMakeFiles/MACE-Cleaning.dir/build.make
MACE/MACE-Cleaning: MACE/libMACE.a
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libfreetype.so
MACE/MACE-Cleaning: /usr/local/lib/libglfw.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libXrandr.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libXcursor.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libXinerama.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopenal.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libGLU.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libGL.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libGLEW.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libSM.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libICE.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libX11.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libXext.so
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
MACE/MACE-Cleaning: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
MACE/MACE-Cleaning: MACE/CMakeFiles/MACE-Cleaning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liavt/Desktop/TitanGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MACE-Cleaning"
	cd /home/liavt/Desktop/TitanGame/build/MACE && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MACE-Cleaning.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MACE/CMakeFiles/MACE-Cleaning.dir/build: MACE/MACE-Cleaning

.PHONY : MACE/CMakeFiles/MACE-Cleaning.dir/build

MACE/CMakeFiles/MACE-Cleaning.dir/requires: MACE/CMakeFiles/MACE-Cleaning.dir/demos/Cleaning.cpp.o.requires

.PHONY : MACE/CMakeFiles/MACE-Cleaning.dir/requires

MACE/CMakeFiles/MACE-Cleaning.dir/clean:
	cd /home/liavt/Desktop/TitanGame/build/MACE && $(CMAKE_COMMAND) -P CMakeFiles/MACE-Cleaning.dir/cmake_clean.cmake
.PHONY : MACE/CMakeFiles/MACE-Cleaning.dir/clean

MACE/CMakeFiles/MACE-Cleaning.dir/depend:
	cd /home/liavt/Desktop/TitanGame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liavt/Desktop/TitanGame /home/liavt/Desktop/TitanGame/MACE /home/liavt/Desktop/TitanGame/build /home/liavt/Desktop/TitanGame/build/MACE /home/liavt/Desktop/TitanGame/build/MACE/CMakeFiles/MACE-Cleaning.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : MACE/CMakeFiles/MACE-Cleaning.dir/depend

