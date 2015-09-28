#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include "Constants.h"
#include "Globals.h"
#include "Terrain.h"
#include "GameFunctions.h"
#include "Score.h"
#include "Sub.h"

int main()
{
	bool quit = false;
	bool checkMove = false;
	Terrain terrain;
	Event e;

	/** Initialize SDL2 **/
	init();
	/** Initialize Submarine **/
	Sub sub;
	Score score;
	while(1)
	{
	if (quit) break;
		/** Handle events and user input **/
		eventHandler(e, quit, checkMove);
		
		/** Draw functions **/
		//Clear the last frame
		SDL_RenderClear(g_renderer);
		//Render texture to the screen
		background(g_renderer);
		terrain.draw(g_renderer);
		if (sub.getAlive())
		{
			SDL_RenderCopy(g_renderer, sub.subTexture, NULL, &sub.subRect);
		}
		//Render Score
		SDL_RenderCopy(g_renderer, score.scoreText, NULL, &score.scoreRect);
		score.printScore();
		if (SDL_RenderCopy(g_renderer, score.pointsText, NULL, &score.pointsRect) < 0) printf("RenderCopy failed: %s\n", SDL_GetError());
		//Update Screen
		SDL_RenderPresent(g_renderer);
		/** Logic and update functions **/
		sub.movement();
		terrain.update();
		if (sub.getAlive())
		{
			sub.setAlive(terrain.collision(sub.getRect()));
		}
		SDL_UpdateWindowSurface(g_window);
		if (sub.getAlive() == true)
		{
			++score.points;
		}
		delay(10);
		score.freeSurface();
	}
	
	//Cleanup
	SDL_DestroyTexture(sub.subTexture);
	SDL_DestroyTexture(score.scoreText);
		
	close();
	return 0;
}
