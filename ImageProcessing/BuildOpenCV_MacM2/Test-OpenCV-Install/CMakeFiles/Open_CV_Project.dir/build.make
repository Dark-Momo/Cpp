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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install

# Include any dependencies generated for this target.
include CMakeFiles/Open_CV_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Open_CV_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Open_CV_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Open_CV_Project.dir/flags.make

CMakeFiles/Open_CV_Project.dir/Main.cpp.o: CMakeFiles/Open_CV_Project.dir/flags.make
CMakeFiles/Open_CV_Project.dir/Main.cpp.o: Main.cpp
CMakeFiles/Open_CV_Project.dir/Main.cpp.o: CMakeFiles/Open_CV_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Open_CV_Project.dir/Main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Open_CV_Project.dir/Main.cpp.o -MF CMakeFiles/Open_CV_Project.dir/Main.cpp.o.d -o CMakeFiles/Open_CV_Project.dir/Main.cpp.o -c /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install/Main.cpp

CMakeFiles/Open_CV_Project.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Open_CV_Project.dir/Main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install/Main.cpp > CMakeFiles/Open_CV_Project.dir/Main.cpp.i

CMakeFiles/Open_CV_Project.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Open_CV_Project.dir/Main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install/Main.cpp -o CMakeFiles/Open_CV_Project.dir/Main.cpp.s

# Object files for target Open_CV_Project
Open_CV_Project_OBJECTS = \
"CMakeFiles/Open_CV_Project.dir/Main.cpp.o"

# External object files for target Open_CV_Project
Open_CV_Project_EXTERNAL_OBJECTS =

Open_CV_Project: CMakeFiles/Open_CV_Project.dir/Main.cpp.o
Open_CV_Project: CMakeFiles/Open_CV_Project.dir/build.make
Open_CV_Project: /usr/local/lib/libopencv_gapi.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_highgui.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_ml.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_objdetect.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_photo.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_stitching.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_video.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_videoio.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_imgcodecs.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_dnn.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_calib3d.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_features2d.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_flann.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_imgproc.4.6.0.dylib
Open_CV_Project: /usr/local/lib/libopencv_core.4.6.0.dylib
Open_CV_Project: CMakeFiles/Open_CV_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Open_CV_Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Open_CV_Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Open_CV_Project.dir/build: Open_CV_Project
.PHONY : CMakeFiles/Open_CV_Project.dir/build

CMakeFiles/Open_CV_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Open_CV_Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Open_CV_Project.dir/clean

CMakeFiles/Open_CV_Project.dir/depend:
	cd /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install /Users/momo/Cpp/ImageProcessing/BuildOpenCV_MacM2/Test-OpenCV-Install/CMakeFiles/Open_CV_Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Open_CV_Project.dir/depend

