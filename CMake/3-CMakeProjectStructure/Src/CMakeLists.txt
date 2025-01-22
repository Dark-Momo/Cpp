add_executable(SimpleAdder main.cpp)

# We don't need target_link_directories() since we have add_subdirectory() at top.
target_link_libraries(SimpleAdder PRIVATE AdderLibrary)