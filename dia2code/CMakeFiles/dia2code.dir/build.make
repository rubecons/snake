# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/ruben/Documents/Projets/snake/dia2code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruben/Documents/Projets/snake/dia2code

# Include any dependencies generated for this target.
include CMakeFiles/dia2code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dia2code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dia2code.dir/flags.make

CMakeFiles/dia2code.dir/src/comment_helper.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/comment_helper.c.o: src/comment_helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dia2code.dir/src/comment_helper.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/comment_helper.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/comment_helper.c

CMakeFiles/dia2code.dir/src/comment_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/comment_helper.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/comment_helper.c > CMakeFiles/dia2code.dir/src/comment_helper.c.i

CMakeFiles/dia2code.dir/src/comment_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/comment_helper.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/comment_helper.c -o CMakeFiles/dia2code.dir/src/comment_helper.c.s

CMakeFiles/dia2code.dir/src/comment_helper.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/comment_helper.c.o.requires

CMakeFiles/dia2code.dir/src/comment_helper.c.o.provides: CMakeFiles/dia2code.dir/src/comment_helper.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/comment_helper.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/comment_helper.c.o.provides

CMakeFiles/dia2code.dir/src/comment_helper.c.o.provides.build: CMakeFiles/dia2code.dir/src/comment_helper.c.o


CMakeFiles/dia2code.dir/src/decls.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/decls.c.o: src/decls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dia2code.dir/src/decls.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/decls.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/decls.c

CMakeFiles/dia2code.dir/src/decls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/decls.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/decls.c > CMakeFiles/dia2code.dir/src/decls.c.i

CMakeFiles/dia2code.dir/src/decls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/decls.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/decls.c -o CMakeFiles/dia2code.dir/src/decls.c.s

CMakeFiles/dia2code.dir/src/decls.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/decls.c.o.requires

CMakeFiles/dia2code.dir/src/decls.c.o.provides: CMakeFiles/dia2code.dir/src/decls.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/decls.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/decls.c.o.provides

CMakeFiles/dia2code.dir/src/decls.c.o.provides.build: CMakeFiles/dia2code.dir/src/decls.c.o


CMakeFiles/dia2code.dir/src/dia2code.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/dia2code.c.o: src/dia2code.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/dia2code.dir/src/dia2code.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/dia2code.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/dia2code.c

CMakeFiles/dia2code.dir/src/dia2code.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/dia2code.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/dia2code.c > CMakeFiles/dia2code.dir/src/dia2code.c.i

CMakeFiles/dia2code.dir/src/dia2code.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/dia2code.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/dia2code.c -o CMakeFiles/dia2code.dir/src/dia2code.c.s

CMakeFiles/dia2code.dir/src/dia2code.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/dia2code.c.o.requires

CMakeFiles/dia2code.dir/src/dia2code.c.o.provides: CMakeFiles/dia2code.dir/src/dia2code.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/dia2code.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/dia2code.c.o.provides

CMakeFiles/dia2code.dir/src/dia2code.c.o.provides.build: CMakeFiles/dia2code.dir/src/dia2code.c.o


CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o: src/generate_code_cpp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/generate_code_cpp.c

CMakeFiles/dia2code.dir/src/generate_code_cpp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/generate_code_cpp.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/generate_code_cpp.c > CMakeFiles/dia2code.dir/src/generate_code_cpp.c.i

CMakeFiles/dia2code.dir/src/generate_code_cpp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/generate_code_cpp.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/generate_code_cpp.c -o CMakeFiles/dia2code.dir/src/generate_code_cpp.c.s

CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.requires

CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.provides: CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.provides

CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.provides.build: CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o


CMakeFiles/dia2code.dir/src/includes.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/includes.c.o: src/includes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/dia2code.dir/src/includes.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/includes.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/includes.c

CMakeFiles/dia2code.dir/src/includes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/includes.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/includes.c > CMakeFiles/dia2code.dir/src/includes.c.i

CMakeFiles/dia2code.dir/src/includes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/includes.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/includes.c -o CMakeFiles/dia2code.dir/src/includes.c.s

CMakeFiles/dia2code.dir/src/includes.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/includes.c.o.requires

CMakeFiles/dia2code.dir/src/includes.c.o.provides: CMakeFiles/dia2code.dir/src/includes.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/includes.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/includes.c.o.provides

CMakeFiles/dia2code.dir/src/includes.c.o.provides.build: CMakeFiles/dia2code.dir/src/includes.c.o


CMakeFiles/dia2code.dir/src/main.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/dia2code.dir/src/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/main.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/main.c

CMakeFiles/dia2code.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/main.c > CMakeFiles/dia2code.dir/src/main.c.i

CMakeFiles/dia2code.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/main.c -o CMakeFiles/dia2code.dir/src/main.c.s

CMakeFiles/dia2code.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/main.c.o.requires

CMakeFiles/dia2code.dir/src/main.c.o.provides: CMakeFiles/dia2code.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/main.c.o.provides

CMakeFiles/dia2code.dir/src/main.c.o.provides.build: CMakeFiles/dia2code.dir/src/main.c.o


CMakeFiles/dia2code.dir/src/parse_diagram.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/parse_diagram.c.o: src/parse_diagram.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/dia2code.dir/src/parse_diagram.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/parse_diagram.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/parse_diagram.c

CMakeFiles/dia2code.dir/src/parse_diagram.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/parse_diagram.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/parse_diagram.c > CMakeFiles/dia2code.dir/src/parse_diagram.c.i

CMakeFiles/dia2code.dir/src/parse_diagram.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/parse_diagram.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/parse_diagram.c -o CMakeFiles/dia2code.dir/src/parse_diagram.c.s

CMakeFiles/dia2code.dir/src/parse_diagram.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/parse_diagram.c.o.requires

CMakeFiles/dia2code.dir/src/parse_diagram.c.o.provides: CMakeFiles/dia2code.dir/src/parse_diagram.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/parse_diagram.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/parse_diagram.c.o.provides

CMakeFiles/dia2code.dir/src/parse_diagram.c.o.provides.build: CMakeFiles/dia2code.dir/src/parse_diagram.c.o


CMakeFiles/dia2code.dir/src/scan_tree.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/scan_tree.c.o: src/scan_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/dia2code.dir/src/scan_tree.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/scan_tree.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/scan_tree.c

CMakeFiles/dia2code.dir/src/scan_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/scan_tree.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/scan_tree.c > CMakeFiles/dia2code.dir/src/scan_tree.c.i

CMakeFiles/dia2code.dir/src/scan_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/scan_tree.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/scan_tree.c -o CMakeFiles/dia2code.dir/src/scan_tree.c.s

CMakeFiles/dia2code.dir/src/scan_tree.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/scan_tree.c.o.requires

CMakeFiles/dia2code.dir/src/scan_tree.c.o.provides: CMakeFiles/dia2code.dir/src/scan_tree.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/scan_tree.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/scan_tree.c.o.provides

CMakeFiles/dia2code.dir/src/scan_tree.c.o.provides.build: CMakeFiles/dia2code.dir/src/scan_tree.c.o


CMakeFiles/dia2code.dir/src/source_parser.c.o: CMakeFiles/dia2code.dir/flags.make
CMakeFiles/dia2code.dir/src/source_parser.c.o: src/source_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/dia2code.dir/src/source_parser.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dia2code.dir/src/source_parser.c.o   -c /home/ruben/Documents/Projets/snake/dia2code/src/source_parser.c

CMakeFiles/dia2code.dir/src/source_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dia2code.dir/src/source_parser.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruben/Documents/Projets/snake/dia2code/src/source_parser.c > CMakeFiles/dia2code.dir/src/source_parser.c.i

CMakeFiles/dia2code.dir/src/source_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dia2code.dir/src/source_parser.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruben/Documents/Projets/snake/dia2code/src/source_parser.c -o CMakeFiles/dia2code.dir/src/source_parser.c.s

CMakeFiles/dia2code.dir/src/source_parser.c.o.requires:

.PHONY : CMakeFiles/dia2code.dir/src/source_parser.c.o.requires

CMakeFiles/dia2code.dir/src/source_parser.c.o.provides: CMakeFiles/dia2code.dir/src/source_parser.c.o.requires
	$(MAKE) -f CMakeFiles/dia2code.dir/build.make CMakeFiles/dia2code.dir/src/source_parser.c.o.provides.build
.PHONY : CMakeFiles/dia2code.dir/src/source_parser.c.o.provides

CMakeFiles/dia2code.dir/src/source_parser.c.o.provides.build: CMakeFiles/dia2code.dir/src/source_parser.c.o


# Object files for target dia2code
dia2code_OBJECTS = \
"CMakeFiles/dia2code.dir/src/comment_helper.c.o" \
"CMakeFiles/dia2code.dir/src/decls.c.o" \
"CMakeFiles/dia2code.dir/src/dia2code.c.o" \
"CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o" \
"CMakeFiles/dia2code.dir/src/includes.c.o" \
"CMakeFiles/dia2code.dir/src/main.c.o" \
"CMakeFiles/dia2code.dir/src/parse_diagram.c.o" \
"CMakeFiles/dia2code.dir/src/scan_tree.c.o" \
"CMakeFiles/dia2code.dir/src/source_parser.c.o"

# External object files for target dia2code
dia2code_EXTERNAL_OBJECTS =

bin/dia2code: CMakeFiles/dia2code.dir/src/comment_helper.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/decls.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/dia2code.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/includes.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/main.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/parse_diagram.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/scan_tree.c.o
bin/dia2code: CMakeFiles/dia2code.dir/src/source_parser.c.o
bin/dia2code: CMakeFiles/dia2code.dir/build.make
bin/dia2code: /usr/lib/x86_64-linux-gnu/libxml2.so
bin/dia2code: CMakeFiles/dia2code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruben/Documents/Projets/snake/dia2code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable bin/dia2code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dia2code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dia2code.dir/build: bin/dia2code

.PHONY : CMakeFiles/dia2code.dir/build

CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/comment_helper.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/decls.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/dia2code.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/generate_code_cpp.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/includes.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/main.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/parse_diagram.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/scan_tree.c.o.requires
CMakeFiles/dia2code.dir/requires: CMakeFiles/dia2code.dir/src/source_parser.c.o.requires

.PHONY : CMakeFiles/dia2code.dir/requires

CMakeFiles/dia2code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dia2code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dia2code.dir/clean

CMakeFiles/dia2code.dir/depend:
	cd /home/ruben/Documents/Projets/snake/dia2code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruben/Documents/Projets/snake/dia2code /home/ruben/Documents/Projets/snake/dia2code /home/ruben/Documents/Projets/snake/dia2code /home/ruben/Documents/Projets/snake/dia2code /home/ruben/Documents/Projets/snake/dia2code/CMakeFiles/dia2code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dia2code.dir/depend

