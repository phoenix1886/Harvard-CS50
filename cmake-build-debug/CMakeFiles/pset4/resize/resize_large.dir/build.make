# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/KirillMaslov/Documents/Projects/CS50

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/KirillMaslov/Documents/Projects/CS50/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pset4/resize/resize_large.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pset4/resize/resize_large.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pset4/resize/resize_large.dir/flags.make

CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o: CMakeFiles/pset4/resize/resize_large.dir/flags.make
CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o: ../pset4/resize/resize_large.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/KirillMaslov/Documents/Projects/CS50/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o   -c /Users/KirillMaslov/Documents/Projects/CS50/pset4/resize/resize_large.c

CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/KirillMaslov/Documents/Projects/CS50/pset4/resize/resize_large.c > CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.i

CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/KirillMaslov/Documents/Projects/CS50/pset4/resize/resize_large.c -o CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.s

CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.requires:

.PHONY : CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.requires

CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.provides: CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.requires
	$(MAKE) -f CMakeFiles/pset4/resize/resize_large.dir/build.make CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.provides.build
.PHONY : CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.provides

CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.provides.build: CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o


# Object files for target pset4/resize/resize_large
pset4/resize/resize_large_OBJECTS = \
"CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o"

# External object files for target pset4/resize/resize_large
pset4/resize/resize_large_EXTERNAL_OBJECTS =

pset4/resize/resize_large: CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o
pset4/resize/resize_large: CMakeFiles/pset4/resize/resize_large.dir/build.make
pset4/resize/resize_large: CMakeFiles/pset4/resize/resize_large.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/KirillMaslov/Documents/Projects/CS50/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pset4/resize/resize_large"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pset4/resize/resize_large.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pset4/resize/resize_large.dir/build: pset4/resize/resize_large

.PHONY : CMakeFiles/pset4/resize/resize_large.dir/build

CMakeFiles/pset4/resize/resize_large.dir/requires: CMakeFiles/pset4/resize/resize_large.dir/pset4/resize/resize_large.c.o.requires

.PHONY : CMakeFiles/pset4/resize/resize_large.dir/requires

CMakeFiles/pset4/resize/resize_large.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pset4/resize/resize_large.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pset4/resize/resize_large.dir/clean

CMakeFiles/pset4/resize/resize_large.dir/depend:
	cd /Users/KirillMaslov/Documents/Projects/CS50/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/KirillMaslov/Documents/Projects/CS50 /Users/KirillMaslov/Documents/Projects/CS50 /Users/KirillMaslov/Documents/Projects/CS50/cmake-build-debug /Users/KirillMaslov/Documents/Projects/CS50/cmake-build-debug /Users/KirillMaslov/Documents/Projects/CS50/cmake-build-debug/CMakeFiles/pset4/resize/resize_large.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pset4/resize/resize_large.dir/depend

