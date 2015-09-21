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
#include "Sub.h"

int main()
{
	bool quit = false;
	Terrain terrain;
	Event e;

	/** Initialize SDL2 **/
	init();

	Sub sub;
	while(1)
	{
	if (quit) break;
		/** Handle events and user input **/
		eventHandler(e, quit);

		/** Draw functions **/
		//Clear the last frame
		SDL_RenderClear(g_renderer);
		//Render texture to the screen
		background(g_renderer);
		terrain.draw(g_renderer);
		SDL_RenderCopy(g_renderer, sub.subTexture, NULL, &sub.subRect);
		//Update Screen
		SDL_RenderPresent(g_renderer);

		/** Logic and update functions **/
		terrain.update();

		SDL_UpdateWindowSurface(g_window);

		delay(10);
	}
	
	//Cleanup
	SDL_DestroyTexture(sub.subTexture);
	
	close();

	return 0;
}
