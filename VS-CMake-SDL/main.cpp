// VS-CMake-SDL.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "SDL.h"

int r() {
	return std::rand() % 255;
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return 1;
	}

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer);


	//SDL_Window* window = SDL_CreateWindow
	//("An SDL2 window", // window's title
	//	10, 25, // coordinates on the screen, in pixels, of the window's upper left corner
	//	640, 480, // window's length and height in pixels  
	//	SDL_WINDOW_RESIZABLE);

	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_WINDOW_RESIZABLE) ;

	SDL_Event event;
	while (1) {
	SDL_Rect rc;
	rc.x = 10;
	rc.y = 10;
	rc.w = r();
	rc.h = r();

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		std::cout << r() << std::endl;

		SDL_SetRenderDrawColor(renderer, r(), r(), r(), 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, r(), r(), 255);

		SDL_RenderDrawRect(renderer, &rc);


		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
