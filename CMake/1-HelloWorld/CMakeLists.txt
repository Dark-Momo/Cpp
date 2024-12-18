# Use your current version or version when you edit this file as minimum requirement.
cmake_minimum_required(VERSION 3.22.1)

# This will set ${PROJECT_NAME} to the content in () so later, you can just use ${PROJECT_NAME}.
# In Cmake, CXX means C++.
project(1-HelloWorld
        VERSION 1.0.0
        LANGUAGES CXX)

# When this line is added, the generated Makefile has our source .cpp file in it.
# The 1st argument is the name of generated binary file.
# Here, we make it the same as the project's name. But we can use other names.
# The 2nd argument is thge lsit of .cpp files. It can be several;
add_executable(${PROJECT_NAME} HelloWorld.cpp)

# 'intall' will enable "make install" at make stage after cmake command.
# It will copy generated executable file into /usr/local/bin.
# The name for TARGETS shoule be the same as the 1st argument of "add_executable".
install(TARGETS ${PROJECT_NAME} DESTINATION bin)