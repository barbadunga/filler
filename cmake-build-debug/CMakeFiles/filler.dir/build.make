# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/mshagga/CLionProjects/re_filler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mshagga/CLionProjects/re_filler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/filler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/filler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/filler.dir/flags.make

CMakeFiles/filler.dir/src/algo.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/algo.c.o: ../src/algo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/filler.dir/src/algo.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/algo.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/algo.c

CMakeFiles/filler.dir/src/algo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/algo.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/algo.c > CMakeFiles/filler.dir/src/algo.c.i

CMakeFiles/filler.dir/src/algo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/algo.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/algo.c -o CMakeFiles/filler.dir/src/algo.c.s

CMakeFiles/filler.dir/src/debug.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/debug.c.o: ../src/debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/filler.dir/src/debug.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/debug.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/debug.c

CMakeFiles/filler.dir/src/debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/debug.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/debug.c > CMakeFiles/filler.dir/src/debug.c.i

CMakeFiles/filler.dir/src/debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/debug.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/debug.c -o CMakeFiles/filler.dir/src/debug.c.s

CMakeFiles/filler.dir/src/init.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/init.c.o: ../src/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/filler.dir/src/init.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/init.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/init.c

CMakeFiles/filler.dir/src/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/init.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/init.c > CMakeFiles/filler.dir/src/init.c.i

CMakeFiles/filler.dir/src/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/init.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/init.c -o CMakeFiles/filler.dir/src/init.c.s

CMakeFiles/filler.dir/src/lee.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/lee.c.o: ../src/lee.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/filler.dir/src/lee.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/lee.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/lee.c

CMakeFiles/filler.dir/src/lee.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/lee.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/lee.c > CMakeFiles/filler.dir/src/lee.c.i

CMakeFiles/filler.dir/src/lee.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/lee.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/lee.c -o CMakeFiles/filler.dir/src/lee.c.s

CMakeFiles/filler.dir/src/main.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/filler.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/main.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/main.c

CMakeFiles/filler.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/main.c > CMakeFiles/filler.dir/src/main.c.i

CMakeFiles/filler.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/main.c -o CMakeFiles/filler.dir/src/main.c.s

CMakeFiles/filler.dir/src/parser.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/parser.c.o: ../src/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/filler.dir/src/parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/parser.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/parser.c

CMakeFiles/filler.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/parser.c > CMakeFiles/filler.dir/src/parser.c.i

CMakeFiles/filler.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/parser.c -o CMakeFiles/filler.dir/src/parser.c.s

CMakeFiles/filler.dir/src/queue.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/queue.c.o: ../src/queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/filler.dir/src/queue.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/queue.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/queue.c

CMakeFiles/filler.dir/src/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/queue.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/queue.c > CMakeFiles/filler.dir/src/queue.c.i

CMakeFiles/filler.dir/src/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/queue.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/queue.c -o CMakeFiles/filler.dir/src/queue.c.s

CMakeFiles/filler.dir/src/utils.c.o: CMakeFiles/filler.dir/flags.make
CMakeFiles/filler.dir/src/utils.c.o: ../src/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/filler.dir/src/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filler.dir/src/utils.c.o   -c /Users/mshagga/CLionProjects/re_filler/src/utils.c

CMakeFiles/filler.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filler.dir/src/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mshagga/CLionProjects/re_filler/src/utils.c > CMakeFiles/filler.dir/src/utils.c.i

CMakeFiles/filler.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filler.dir/src/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mshagga/CLionProjects/re_filler/src/utils.c -o CMakeFiles/filler.dir/src/utils.c.s

# Object files for target filler
filler_OBJECTS = \
"CMakeFiles/filler.dir/src/algo.c.o" \
"CMakeFiles/filler.dir/src/debug.c.o" \
"CMakeFiles/filler.dir/src/init.c.o" \
"CMakeFiles/filler.dir/src/lee.c.o" \
"CMakeFiles/filler.dir/src/main.c.o" \
"CMakeFiles/filler.dir/src/parser.c.o" \
"CMakeFiles/filler.dir/src/queue.c.o" \
"CMakeFiles/filler.dir/src/utils.c.o"

# External object files for target filler
filler_EXTERNAL_OBJECTS =

filler: CMakeFiles/filler.dir/src/algo.c.o
filler: CMakeFiles/filler.dir/src/debug.c.o
filler: CMakeFiles/filler.dir/src/init.c.o
filler: CMakeFiles/filler.dir/src/lee.c.o
filler: CMakeFiles/filler.dir/src/main.c.o
filler: CMakeFiles/filler.dir/src/parser.c.o
filler: CMakeFiles/filler.dir/src/queue.c.o
filler: CMakeFiles/filler.dir/src/utils.c.o
filler: CMakeFiles/filler.dir/build.make
filler: ../Libft/libft.a
filler: CMakeFiles/filler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable filler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/filler.dir/build: filler

.PHONY : CMakeFiles/filler.dir/build

CMakeFiles/filler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/filler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/filler.dir/clean

CMakeFiles/filler.dir/depend:
	cd /Users/mshagga/CLionProjects/re_filler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mshagga/CLionProjects/re_filler /Users/mshagga/CLionProjects/re_filler /Users/mshagga/CLionProjects/re_filler/cmake-build-debug /Users/mshagga/CLionProjects/re_filler/cmake-build-debug /Users/mshagga/CLionProjects/re_filler/cmake-build-debug/CMakeFiles/filler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/filler.dir/depend

