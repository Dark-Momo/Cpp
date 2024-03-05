# Use your current version or version when you edit this file as minimum requirement.
cmake_minimum_required(VERSION 3.22.1)

# This will set ${PROJECT_NAME} to the content in () so later, you can just use ${PROJECT_NAME} while just need to modify here.
project(HelloWorldExample)

# When this line is added, the generated Makefile has our source .cpp file in it.
add_executable(${PROJECT_NAME} HelloWorld.cpp)
