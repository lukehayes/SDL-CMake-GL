# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project ("app")

# ------------------------------------------------------
# WINDOWS
# ------------------------------------------------------
if (WIN32)
    message("Running on Windows")
    set(INC_DIRS
        ${PROJECT_SOURCE_DIR}/deps/libs/SDL/include
        ${PROJECT_SOURCE_DIR}/deps/libs/GLEW/include
        ${PROJECT_SOURCE_DIR}/include
    )
    include_directories(${INC_DIRS})
    link_directories(${PROJECT_SOURCE_DIR}/deps/libs/SDL/libs)

    # Add source to this project's executable.
    add_executable (app "src/main.cpp")

    target_link_libraries(app SDL2.lib)
    target_link_libraries(app SDL2main.lib)

endif(WIN32)


# ------------------------------------------------------
# OSX
# ------------------------------------------------------
if(APPLE)
    message("Running on APPLE")

    # Modules Path
    set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

    # Find SDL2 on OSX - must be at top
    find_package (SDL2 REQUIRED)

    include_directories(${SDL2_INCLUDE_DIR})

    # Add source to this project's executable.
    add_executable (app "src/main.cpp")
    target_link_libraries (app ${SDL2_LIBRARIES})

endif(APPLE)

