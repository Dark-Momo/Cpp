add_executable(${EXECUTABLE_NAME} main.cpp)
# We don't need target_link_directories() since we have add_subdirectory() at top.
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_NAME})