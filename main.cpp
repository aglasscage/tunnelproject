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
	Event e;
	/** Initialize SDL2 **/
	init();
	Score score;

	while(1) // main loop
	{
		bool quit = false;
		Terrain terrain;
		Sub sub;
		score.init();
		while(1) // game loop
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
			if (sub.getAlive())
			{
				SDL_RenderCopy(g_renderer, sub.subTexture, NULL, &sub.subRect);
			}
			//Render Score
			SDL_RenderCopy(g_renderer, score.scoreText, NULL, &score.scoreRect);
			score.printScore();
			if (SDL_RenderCopy(g_renderer, score.pointsText, NULL, &score.pointsRect) < 0) 
				printf("RenderCopy failed: %s\n", SDL_GetError());
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

			if (sub.getAlive() == true) ++score.points;
			else sub.decDeathCounter();

			delay(10);
			score.freeSurface();

			if (sub.getDeathCounter() < 1) break;
		}
		while (1) // score loop
		{
			if (quit) break;

			bool restart = false;

			/** Handle events and user input **/
			eventHandler(e, quit, restart);
			/** Draw functions **/
			//Clear the last frame
			SDL_RenderClear(g_renderer);
			//Render Score
			SDL_RenderCopy(g_renderer, score.scoreText, NULL, &score.scoreRect);
			score.printFinal();
			if (SDL_RenderCopy(g_renderer, score.pointsText, NULL, &score.pointsRect) < 0) 
				printf("RenderCopy failed: %s\n", SDL_GetError());
			if (SDL_RenderCopy(g_renderer, score.conText, NULL, &score.conRect) < 0) 
				printf("RenderCopy failed: %s\n", SDL_GetError());
			//Update Screen
			SDL_RenderPresent(g_renderer);
			delay(10);
			score.freeSurface();

			if (restart) break;
		}
		//Cleanup
		SDL_DestroyTexture(sub.subTexture);
		if (quit) break;
	}
	
	//Cleanup
	SDL_DestroyTexture(score.scoreText);
		
	close();
	return 0;
}
