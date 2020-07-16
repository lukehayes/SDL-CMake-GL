#if _WIN32
    #define GLEW_STATIC
    #include "eglew.h"
    #include "glew.h"

#elif __linux__
    #include "GL/glew.h"
#endif

#include <iostream>
#include "SDL.h"
#include "app/window.h"

int main(int argc, char* argr[])
{

    App::Window window(800, 600, "Window Title");


    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
          /* Problem: glewInit failed, something is seriously wrong. */
          fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	SDL_Event event;

    const int MS_PER_UPDATE = 30;
	double previous = SDL_GetTicks();
	double lag = 0.0;

    while (true)
        {
            double current = SDL_GetTicks();
            double elapsed = current - previous;
            previous = current;
            lag += elapsed;

            // processInput();

            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT) {
                break;
            }

            while (lag >= MS_PER_UPDATE)
            {
                // Update here
                lag -= MS_PER_UPDATE;
            }

            // Render here
            glClearColor(0.0,0.5,0.5,1);
            glClear(GL_COLOR_BUFFER_BIT);

            SDL_GL_SwapWindow(window.getWindow());
        }

	SDL_Quit();

	return 0;
}

