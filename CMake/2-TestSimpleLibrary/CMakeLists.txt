# Use your current version or version when you edit this file as minimum requirement.
cmake_minimum_required(VERSION 3.22.1)

# This will set ${PROJECT_NAME} to the content in () so later, you can just use ${PROJECT_NAME}.
project(2-TestSimpleLibrary
        VERSION 1.0.0
        LANGUAGES CXX)

# Here we generate the TARGET, with its name set to ${PROJECT_NAME}.
add_executable(${PROJECT_NAME} main.cpp)

# ------------------------------------------------------------------------------------------------------
# If we didn't install the library and its header in previous project "1-SimpleLibrary", then we need to
# 1. First tell cmake, for this project, where is the library;
# ------------------------------------------------------------------------------------------------------
# The parameter of PRIVATE/PIUBLIC makes no difference here;
# target_link_directories(${PROJECT_NAME} PUBLIC ../build/2-Library-SimpleAdder/)

# However, we do install them in previous project "1-SimpleLibrary".
# 2. Then we just need to tell cmake, for this project, what library will be used.
target_link_libraries(${PROJECT_NAME} PUBLIC 2-Library-SimpleAdder)
# (1) Library's actually name is lib2-Library-SimpleAdder.a;
# (2) 1st argument is TARGET, just its name is set to ${PROJECT_NAME}. It doesn't mean here we should
#     use project.
