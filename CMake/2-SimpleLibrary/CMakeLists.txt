# Use your current version or version when you edit this file as minimum requirement.
cmake_minimum_required(VERSION 3.22.1)

# This will set ${PROJECT_NAME} to the content in () so later, you can just use ${PROJECT_NAME}.
project(2-SimpleAdder)

# Similar to add_executable:
# 1st argument is the name of the library;
# 2nd argument is the cpp file involved;
# The generated lib file will be under your build folder, with name like lib2-Library-SimpleAdder.a
add_library(2-Library-SimpleAdder simpleAdder.cpp)

#--------------------------------------------------------------------------------------------------
# Till the steps above, the generated library will be in your build folder, which is not a feasible
# way for application to call.

# 1. Till cmake the related header file for this target, not this project;
set_target_properties(2-Library-SimpleAdder PROPERTIES PUBLIC_HEADER simpleAdder.hpp)
# 2. Install library file and its header file to default locations;
install(TARGETS 2-Library-SimpleAdder
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)

# With above 2 lines, you will have below information when running "make install"
# -- Install configuration: ""
# -- Installing: /usr/local/lib/lib2-Library-SimpleAdder.a
# -- Installing: /usr/local/include/simpleAdder.hpp
