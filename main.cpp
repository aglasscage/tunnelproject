#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include "Constants.h"
#include "Globals.h"
#include "Terrain.h"
#include "GameFunctions.h"

int main()
{
	bool quit = false;
	Terrain terrain;
	Event e;

	/** Initialize SDL2 **/
	init();

	while(1)
	{
		if (quit) break;
		/** Handle events and user input **/
		eventHandler(e, quit);

		/** Draw functions **/
		background(g_renderer);
		terrain.draw(g_renderer);
		SDL_RenderPresent(g_renderer);

		/** Logic and update functions **/
		terrain.update();

		delay(10);
	}

	close();

	return 0;
}