# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)
project ("app")

# ------------------------------------------------------
# Helper Variables
# ------------------------------------------------------
SET(SRC_DIR "src")
SET(SRC_FILE "${SRC_DIR}/main.cpp")
SET(LIBS_DIR "${PROJECT_SOURCE_DIR}/deps/libs")

SET(CORE_INCLUDES
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/deps/libs/glm"
	"${PROJECT_SOURCE_DIR}/deps/libs/stb"
)

# ------------------------------------------------------
# WINDOWS
# ------------------------------------------------------
if (WIN32)

    message("Running on Windows")

    set(INC_DIRS
        ${PROJECT_SOURCE_DIR}/deps/libs/SDL/include
        ${PROJECT_SOURCE_DIR}/deps/libs/GLEW/include
        ${CORE_INCLUDES}
    )

    include_directories(${INC_DIRS})
    link_directories(${PROJECT_SOURCE_DIR}/deps/libs/SDL/libs)
    link_directories(${PROJECT_SOURCE_DIR}/deps/libs/GLEW/libs)

    # Add source to this project's executable.
    add_executable (app "${SRC_FILE}")

    target_link_libraries(app SDL2.lib)
    target_link_libraries(app SDL2main.lib)
    target_link_libraries(app glew32)
    target_link_libraries(app opengl32)

endif(WIN32)


# ------------------------------------------------------
# OSX | LINUX
# ------------------------------------------------------
if(APPLE OR UNIX)
    message("Running on APPLE or LINUX")

    # Modules Path
    set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
    set(CMAKE_CXX_STANDARD 20)

    find_package (SDL2 REQUIRED)
    find_package (OpenGL)
    find_package (GLEW REQUIRED STATIC)


    include_directories(
		${PROJECT_SOURCE_DIR}/include
		${SDL2_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        "${PROJECT_SOURCE_DIR}/deps/libs/stb" # Load stb_image.h header
    )

    # Add source to this project's executable.
    add_executable (app "${SRC_FILE}")
    target_link_libraries (app ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

endif(APPLE OR UNIX)

