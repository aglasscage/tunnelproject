#ifndef SCORE_H
#define SCORE_H

#include <SDL2/SDL.h>
#include <Globals.h>
#include <GameFunctions.h>
#include <SDL_ttf.h>

class Score
{
public:
	Score()
	{
		//Score Surface
		scoreSurfaceText = TTF_RenderText_Solid(Sans, "points", White);
		scoreText = SDL_CreateTextureFromSurface(g_renderer, scoreSurfaceText);
		//Score Rectangle
		scoreRect.x = 0;
		scoreRect.y = 0;
		scoreRect.w = 100;
		scoreRect.h = 100;	
	}
	SDL_Surface* scoreSurfaceText = NULL;
	SDL_Texture* scoreText = NULL;
	SDL_Rect scoreRect;
};

#endif
