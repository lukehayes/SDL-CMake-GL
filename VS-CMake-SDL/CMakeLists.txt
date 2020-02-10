# CMakeList.txt : CMake project for VS-CMake-SDL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories("../libs/SDL/include")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../libs/SDL/libs")

# Add source to this project's executable.
add_executable (VS-CMake-SDL "main.cpp")

target_link_libraries(VS-CMake-SDL SDL2.lib)
target_link_libraries(VS-CMake-SDL SDL2main.lib)


# TODO: Add tests and install targets if needed.
