#ifndef RESOURCE_H
#define RESOURCE_H




/**
 * Platform specific helper functions to get resources like images.
 */

#include <iostream>
#include <string>

#ifdef __unix__ 

    /**
     * Get the path to an image resource.
     *
     * @param filename The name of the file to load
     *
     * @return The full path to the image resource
     */
    std::string ImageResource(const std::string& filename) {
        std::string path = "../res/images/" + filename;
        return path;
    }

    /**
     * Get the path to an shader resource.
     *
     * @param filename The name of the file to load
     *
     * @return The full path to the shader file
     */
    std::string ShaderResource(const std::string& filename) {
        std::string path = "../res/shaders/" + filename;
        return path;
    }

#elif _WIN32

    /**
     * Get the path to an image resource.
     *
     * @param filename The name of the file to load
     *
     * @return The full path to the image resource
     */
    std::string ImageResource(const std::string& filename) {
        std::string path = "../../../res/images/" + filename;
        return path;
    }

    /**
     * Get the path to an shader resource.
     *
     * @param filename The name of the file to load
     *
     * @return The full path to the shader file
     */
    std::string ShaderResource(const std::string& filename) {
        std::string path = "../../../res/shaders/" + filename;
        return path;
    }

#endif

#endif // !RESOURCE_H
