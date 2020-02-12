//#if _WIN32
//    #define GLEW_STATIC
//    #include "eglew.h"
//    #include "glew.h"
//#endif

#include <iostream>
#include "SDL.h"


int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer);

	SDL_Event event;

	while (1) {

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		SDL_SetRenderDrawColor(renderer, 200, 150, 200, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

