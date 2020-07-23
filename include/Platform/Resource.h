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
        std::string path = "../assets/images/" + filename;
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
    void ImageResource() {
        std::cout << "Running on Windows. ImageResource() function needs implementation!" << std::endl;
        exit(EXIT_FAILURE);
    }

#endif
