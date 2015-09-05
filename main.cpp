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
	/** Initializatoin **/
	/********************/
	surface.init();

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
