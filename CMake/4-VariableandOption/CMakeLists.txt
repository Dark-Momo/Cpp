# Use your current version or version when you edit this file as minimum requirement
cmake_minimum_required(VERSION 3.22.1)

project(4-VariableandOption
        VERSION 1.0.0
        LANGUAGES CXX)

# Explicitly requires to use C++17 to aviod different users use different C++ compiler
set(CMAKE_CXX_STANDARD          17)
# Use standard C++ compiler
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Disable C++ extensions (implemented by compiler, but not in standard)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(LIBRARY_NAME SimpleAdder)
set(EXECUTABLE_NAME 4-VariableandOption)

option(BUILD_EXECUTABLE "Decide whether to build executable" OFF)
# ------------------------------------------------------------------------------------------------
# 1. Run "cmake -S ../../4-VariableandOption/ -B ./" will have message like
# -- Detecting CXX compile features - done
# Will NOT build executable...
# -- Configuring done
# at cmake stage. Then in build folder, only Src folder will be there for library;

# 2. Run "cmake -S ../../4-VariableandOption/ -B ./ -DBUILD_EXECUTABLE=ON" will have message like
# -- Detecting CXX compile features - done
# Will build executable...
# -- Configuring done
# at cmake stage. 
# Then in build folder, both Src and App folders are there;
# ------------------------------------------------------------------------------------------------

# What in set() will be accessible to all add_subdirectory() here
add_subdirectory(Src)

if (BUILD_EXECUTABLE)
    message("Will build executable...")
    add_subdirectory(App)
else()  # Don't use else
    message("Will NOT build executable...")
endif() # Don't use endif

# -----------------------------------------------------------------------------
# Attention: 
# - Final executable will be in build/App folder, not directly in build folder;
# - Generated library file will be in build/Src folder;
# -----------------------------------------------------------------------------
