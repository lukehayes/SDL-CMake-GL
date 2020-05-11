#if _WIN32
    #define GLEW_STATIC
    #include "eglew.h"
    #include "glew.h"

#elif __linux__
    #include "GL/glew.h"
#endif

#include <iostream>
#include "SDL.h"

int main(int argc, char* argr[])
{
    
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3  );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3  );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE  );

    SDL_Window* window = SDL_CreateWindow(
        "SDL2 OpenGL",
        0,0,800,600,
        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE
    );

    SDL_GLContext context = SDL_GL_CreateContext(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
          /* Problem: glewInit failed, something is seriously wrong. */
          fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	SDL_Event event;

	while (1) {

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

        glClearColor(0.0,0.5,0.5,1);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);

	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

