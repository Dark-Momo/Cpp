# Use your current version or version when you edit this file as minimum requirement.
cmake_minimum_required(VERSION 3.22.1)

# This will set ${PROJECT_NAME} to the content in () so later, you can just use ${PROJECT_NAME}.
project(2-TestSimpleLibrary
        VERSION 1.0.0
        LANGUAGES CXX)

# Here we generate the TARGET, with its name set to ${PROJECT_NAME}.
add_executable(${PROJECT_NAME} main.cpp)

# -------------------------------------------------------------------------------------------------------
# Option 1: If we didn't install the library and its header file, then we need to:
# -------------------------------------------------------------------------------------------------------
# 1. First tell cmake, for this project, where is the library;
# The parameter of PRIVATE/PIUBLIC makes no difference here;
# target_link_directories(${PROJECT_NAME} PUBLIC ../build/2-SimpleLibrary/)
# 2. Then we just need to tell cmake, for this project, what library will be used.
# target_link_libraries(${PROJECT_NAME} PUBLIC 2-Library-SimpleAdder)

# -------------------------------------------------------------------------------------------------------
# Option 2: If we installed the library and its header file, then we need to:
# -------------------------------------------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC 2-Library-SimpleAdder)
# and directly include the header file without its path;

