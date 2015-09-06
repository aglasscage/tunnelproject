#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>
#include "surface.h"
#include "event.h"

/*******************/
/** Main Function **/
/*******************/
int main(int argc, char* args[])
{
	/**************************/
	/** Variable Declaration **/
	/**************************/
	Event event;
	Surface surface;

	/********************/
	/** Initialization **/
	/********************/
	surface.init();

	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(surface.gWindow, 0, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	
	SDL_RenderClear(renderer);

	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderFillRect(renderer, &r);

	SDL_RenderPresent(renderer);
	/* Main game loop. */
	while (1)
	{
		/* Check if the user closes the window. */
		if (event.check_quit()) break;

		/* Game Logic goes here. */
	
		/* Update the Surface after game logic. */
		surface.update();
		surface.delay(2000);
	}
	
	/* Close the window before stopping the program */
	surface.close();

	return 0;
}
