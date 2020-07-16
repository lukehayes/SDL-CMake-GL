#if _WIN32
    #define GLEW_STATIC
    #include "eglew.h"
    #include "glew.h"

#elif __linux__
    #include "GL/glew.h"
#endif

#include <iostream>
#include "SDL.h"
#include "app/app.h"

int main(int argc, char* argr[])
{

    App::App app(800, 600, "Window Title");


    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
          /* Problem: glewInit failed, something is seriously wrong. */
          fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    app.run();

	return 0;
}

