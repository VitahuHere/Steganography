# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\vumir\CLionProjects\Steganography

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/steganography.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/steganography.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/steganography.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/steganography.dir/flags.make

CMakeFiles/steganography.dir/src/files/main.cpp.obj: CMakeFiles/steganography.dir/flags.make
CMakeFiles/steganography.dir/src/files/main.cpp.obj: C:/Users/vumir/CLionProjects/Steganography/src/files/main.cpp
CMakeFiles/steganography.dir/src/files/main.cpp.obj: CMakeFiles/steganography.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/steganography.dir/src/files/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/steganography.dir/src/files/main.cpp.obj -MF CMakeFiles\steganography.dir\src\files\main.cpp.obj.d -o CMakeFiles\steganography.dir\src\files\main.cpp.obj -c C:\Users\vumir\CLionProjects\Steganography\src\files\main.cpp

CMakeFiles/steganography.dir/src/files/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steganography.dir/src/files/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vumir\CLionProjects\Steganography\src\files\main.cpp > CMakeFiles\steganography.dir\src\files\main.cpp.i

CMakeFiles/steganography.dir/src/files/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steganography.dir/src/files/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vumir\CLionProjects\Steganography\src\files\main.cpp -o CMakeFiles\steganography.dir\src\files\main.cpp.s

CMakeFiles/steganography.dir/src/files/flags.cpp.obj: CMakeFiles/steganography.dir/flags.make
CMakeFiles/steganography.dir/src/files/flags.cpp.obj: C:/Users/vumir/CLionProjects/Steganography/src/files/flags.cpp
CMakeFiles/steganography.dir/src/files/flags.cpp.obj: CMakeFiles/steganography.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/steganography.dir/src/files/flags.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/steganography.dir/src/files/flags.cpp.obj -MF CMakeFiles\steganography.dir\src\files\flags.cpp.obj.d -o CMakeFiles\steganography.dir\src\files\flags.cpp.obj -c C:\Users\vumir\CLionProjects\Steganography\src\files\flags.cpp

CMakeFiles/steganography.dir/src/files/flags.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steganography.dir/src/files/flags.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vumir\CLionProjects\Steganography\src\files\flags.cpp > CMakeFiles\steganography.dir\src\files\flags.cpp.i

CMakeFiles/steganography.dir/src/files/flags.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steganography.dir/src/files/flags.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vumir\CLionProjects\Steganography\src\files\flags.cpp -o CMakeFiles\steganography.dir\src\files\flags.cpp.s

CMakeFiles/steganography.dir/src/files/info.cpp.obj: CMakeFiles/steganography.dir/flags.make
CMakeFiles/steganography.dir/src/files/info.cpp.obj: C:/Users/vumir/CLionProjects/Steganography/src/files/info.cpp
CMakeFiles/steganography.dir/src/files/info.cpp.obj: CMakeFiles/steganography.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/steganography.dir/src/files/info.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/steganography.dir/src/files/info.cpp.obj -MF CMakeFiles\steganography.dir\src\files\info.cpp.obj.d -o CMakeFiles\steganography.dir\src\files\info.cpp.obj -c C:\Users\vumir\CLionProjects\Steganography\src\files\info.cpp

CMakeFiles/steganography.dir/src/files/info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steganography.dir/src/files/info.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vumir\CLionProjects\Steganography\src\files\info.cpp > CMakeFiles\steganography.dir\src\files\info.cpp.i

CMakeFiles/steganography.dir/src/files/info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steganography.dir/src/files/info.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vumir\CLionProjects\Steganography\src\files\info.cpp -o CMakeFiles\steganography.dir\src\files\info.cpp.s

CMakeFiles/steganography.dir/src/files/help.cpp.obj: CMakeFiles/steganography.dir/flags.make
CMakeFiles/steganography.dir/src/files/help.cpp.obj: C:/Users/vumir/CLionProjects/Steganography/src/files/help.cpp
CMakeFiles/steganography.dir/src/files/help.cpp.obj: CMakeFiles/steganography.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/steganography.dir/src/files/help.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/steganography.dir/src/files/help.cpp.obj -MF CMakeFiles\steganography.dir\src\files\help.cpp.obj.d -o CMakeFiles\steganography.dir\src\files\help.cpp.obj -c C:\Users\vumir\CLionProjects\Steganography\src\files\help.cpp

CMakeFiles/steganography.dir/src/files/help.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steganography.dir/src/files/help.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vumir\CLionProjects\Steganography\src\files\help.cpp > CMakeFiles\steganography.dir\src\files\help.cpp.i

CMakeFiles/steganography.dir/src/files/help.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steganography.dir/src/files/help.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vumir\CLionProjects\Steganography\src\files\help.cpp -o CMakeFiles\steganography.dir\src\files\help.cpp.s

CMakeFiles/steganography.dir/src/files/encrypt.cpp.obj: CMakeFiles/steganography.dir/flags.make
CMakeFiles/steganography.dir/src/files/encrypt.cpp.obj: C:/Users/vumir/CLionProjects/Steganography/src/files/encrypt.cpp
CMakeFiles/steganography.dir/src/files/encrypt.cpp.obj: CMakeFiles/steganography.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/steganography.dir/src/files/encrypt.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/steganography.dir/src/files/encrypt.cpp.obj -MF CMakeFiles\steganography.dir\src\files\encrypt.cpp.obj.d -o CMakeFiles\steganography.dir\src\files\encrypt.cpp.obj -c C:\Users\vumir\CLionProjects\Steganography\src\files\encrypt.cpp

CMakeFiles/steganography.dir/src/files/encrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steganography.dir/src/files/encrypt.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vumir\CLionProjects\Steganography\src\files\encrypt.cpp > CMakeFiles\steganography.dir\src\files\encrypt.cpp.i

CMakeFiles/steganography.dir/src/files/encrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steganography.dir/src/files/encrypt.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vumir\CLionProjects\Steganography\src\files\encrypt.cpp -o CMakeFiles\steganography.dir\src\files\encrypt.cpp.s

CMakeFiles/steganography.dir/src/files/decrypt.cpp.obj: CMakeFiles/steganography.dir/flags.make
CMakeFiles/steganography.dir/src/files/decrypt.cpp.obj: C:/Users/vumir/CLionProjects/Steganography/src/files/decrypt.cpp
CMakeFiles/steganography.dir/src/files/decrypt.cpp.obj: CMakeFiles/steganography.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/steganography.dir/src/files/decrypt.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/steganography.dir/src/files/decrypt.cpp.obj -MF CMakeFiles\steganography.dir\src\files\decrypt.cpp.obj.d -o CMakeFiles\steganography.dir\src\files\decrypt.cpp.obj -c C:\Users\vumir\CLionProjects\Steganography\src\files\decrypt.cpp

CMakeFiles/steganography.dir/src/files/decrypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steganography.dir/src/files/decrypt.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vumir\CLionProjects\Steganography\src\files\decrypt.cpp > CMakeFiles\steganography.dir\src\files\decrypt.cpp.i

CMakeFiles/steganography.dir/src/files/decrypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steganography.dir/src/files/decrypt.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vumir\CLionProjects\Steganography\src\files\decrypt.cpp -o CMakeFiles\steganography.dir\src\files\decrypt.cpp.s

CMakeFiles/steganography.dir/src/files/check.cpp.obj: CMakeFiles/steganography.dir/flags.make
CMakeFiles/steganography.dir/src/files/check.cpp.obj: C:/Users/vumir/CLionProjects/Steganography/src/files/check.cpp
CMakeFiles/steganography.dir/src/files/check.cpp.obj: CMakeFiles/steganography.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/steganography.dir/src/files/check.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/steganography.dir/src/files/check.cpp.obj -MF CMakeFiles\steganography.dir\src\files\check.cpp.obj.d -o CMakeFiles\steganography.dir\src\files\check.cpp.obj -c C:\Users\vumir\CLionProjects\Steganography\src\files\check.cpp

CMakeFiles/steganography.dir/src/files/check.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steganography.dir/src/files/check.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vumir\CLionProjects\Steganography\src\files\check.cpp > CMakeFiles\steganography.dir\src\files\check.cpp.i

CMakeFiles/steganography.dir/src/files/check.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steganography.dir/src/files/check.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vumir\CLionProjects\Steganography\src\files\check.cpp -o CMakeFiles\steganography.dir\src\files\check.cpp.s

# Object files for target steganography
steganography_OBJECTS = \
"CMakeFiles/steganography.dir/src/files/main.cpp.obj" \
"CMakeFiles/steganography.dir/src/files/flags.cpp.obj" \
"CMakeFiles/steganography.dir/src/files/info.cpp.obj" \
"CMakeFiles/steganography.dir/src/files/help.cpp.obj" \
"CMakeFiles/steganography.dir/src/files/encrypt.cpp.obj" \
"CMakeFiles/steganography.dir/src/files/decrypt.cpp.obj" \
"CMakeFiles/steganography.dir/src/files/check.cpp.obj"

# External object files for target steganography
steganography_EXTERNAL_OBJECTS =

steganography.exe: CMakeFiles/steganography.dir/src/files/main.cpp.obj
steganography.exe: CMakeFiles/steganography.dir/src/files/flags.cpp.obj
steganography.exe: CMakeFiles/steganography.dir/src/files/info.cpp.obj
steganography.exe: CMakeFiles/steganography.dir/src/files/help.cpp.obj
steganography.exe: CMakeFiles/steganography.dir/src/files/encrypt.cpp.obj
steganography.exe: CMakeFiles/steganography.dir/src/files/decrypt.cpp.obj
steganography.exe: CMakeFiles/steganography.dir/src/files/check.cpp.obj
steganography.exe: CMakeFiles/steganography.dir/build.make
steganography.exe: CMakeFiles/steganography.dir/linklibs.rsp
steganography.exe: CMakeFiles/steganography.dir/objects1.rsp
steganography.exe: CMakeFiles/steganography.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable steganography.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\steganography.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/steganography.dir/build: steganography.exe
.PHONY : CMakeFiles/steganography.dir/build

CMakeFiles/steganography.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\steganography.dir\cmake_clean.cmake
.PHONY : CMakeFiles/steganography.dir/clean

CMakeFiles/steganography.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\vumir\CLionProjects\Steganography C:\Users\vumir\CLionProjects\Steganography C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug C:\Users\vumir\CLionProjects\Steganography\cmake-build-debug\CMakeFiles\steganography.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/steganography.dir/depend
