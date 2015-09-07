#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>
#include "surface.h"
#include "event.h"
#include "sub.h"

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
	Sub sub;

	/********************/
	/** Initialization **/
	/********************/
	surface.init();
	/* Main game loop.*/
	while (1)
	{
		/* event handler */
		if (event.poll() != 0)
		{
			int i = event.check_event();
			
			if (i == -9999)
			{
				break;	
			}	

			if (i >= 0 && i <= 7)
			{
				sub.move(i);
			}				
		}
		SDL_BlitScaled(sub.subImage, NULL, surface.gScreenSurface, 
						&sub.subRect);

		/* Update the Surface after game logic. */
		surface.update();
		surface.delay(10);
	}

	/* Close the window before stopping the program */
	sub.cleanup();
	surface.close();

	return 0;
}
