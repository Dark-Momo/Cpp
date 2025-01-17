# Use your current version or version when you edit this file as minimum requirement.
cmake_minimum_required(VERSION 3.22.1)

# This will set ${PROJECT_NAME}.
project(2-SimpleAdder
        VERSION 1.0.0
        LANGUAGES CXX)

# Similar to add_executable:
# 1st argument is the TARGETS, which is the library name;
# 2nd argument is the cpp file involved;
# The generated lib file will be under your build folder, with name like lib2-Library-SimpleAdder.a
add_library(2-Library-SimpleAdder STATIC simpleAdder.cpp)

#--------------------------------------------------------------------------------------------------
# Till the steps above, the generated library will be in your build folder, which is not a feasible
# way for application to call.

# 1. Tell cmake the related header file for this TARGET/library;
set_target_properties(2-Library-SimpleAdder PROPERTIES PUBLIC_HEADER simpleAdder.hpp)
# Here, we should specify the full path of the header if necessary, which is reasonable
# when generating libraries.

# 2. Install library file and its header file to default locations;
install(TARGETS 2-Library-SimpleAdder
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)

# With above 2 lines, you will have below information when running "make install"
# -- Install configuration: ""
# -- Installing: /usr/local/lib/lib2-Library-SimpleAdder.a
# -- Installing: /usr/local/include/simpleAdder.hpp
