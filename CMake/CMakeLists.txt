# Use your current version or version when you edit this file as minimum requirement.
cmake_minimum_required(VERSION 3.22.1)

# This will set ${PROJECT_NAME} to the content in () so later, you can just use ${PROJECT_NAME}.
project(HelloWorldExample)

# When this line is added, the generated Makefile has our source .cpp file in it.
add_executable(${PROJECT_NAME} HelloWorld.cpp)

# 'intall' will enable "make install" at make stage after cmake command.
# It will copy generated executable file into /usr/local/bin.
install(TARGETS ${PROJECT_NAME} DESTINATION bin)