//#if _WIN32
//    #define GLEW_STATIC
//    #include "eglew.h"
//    #include "glew.h"
//#endif

#include <iostream>
#include <list>
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

	const int MAX = 1000;
	std::list<SDL_Rect> rects(MAX);

	for (auto &e : rects) {
		e.x = std::rand() % 800;
		e.y = std::rand() % 600;
		e.w = 10;
		e.h = 10;
	}


	int c = 0;

	SDL_Event event;

	while (1) {
		c++;

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		SDL_SetRenderDrawColor(renderer, 0, 150, 200, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		for (auto &r : rects) {
			SDL_RenderFillRect(renderer, &r);
		}

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

