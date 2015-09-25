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
		TTF_Font* Sans = TTF_OpenFont("includes/Subterran.ttf", 24);
		if (Sans == NULL) printf("TTF_OpenFont: %s\n", TTF_GetError());
		std::cout << "Entering constructor\n";
		//Score Surface
		scoreSurfaceText = TTF_RenderText_Solid(Sans, "points", WHITE);
		if (scoreSurfaceText == NULL) printf("Surface is NULL: %s\n", TTF_GetError());
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
