# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("VS-CMake-SDL")

# Include sub-projects.
#add_subdirectory ("src")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL/libs")

# Add source to this project's executable.
add_executable (VS-CMake-SDL "src/main.cpp")

target_link_libraries(VS-CMake-SDL SDL2.lib)
target_link_libraries(VS-CMake-SDL SDL2main.lib)
