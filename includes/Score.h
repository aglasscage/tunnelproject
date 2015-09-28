#ifndef SCORE_H
#define SCORE_H

#include <SDL2/SDL.h>
//#include <Globals.h>
#include <GameFunctions.h>
#include <SDL_ttf.h>
#include <sstream>

class Score
{
public:
	Score()
		: points(0)
	{
		Sans = TTF_OpenFont("includes/Subterran.ttf", 24);
		if (Sans == NULL) printf("TTF_OpenFont: %s\n", TTF_GetError());
		//Score Surface
		scoreSurfaceText = TTF_RenderText_Solid(Sans, "points: ", WHITE);
		if (scoreSurfaceText == NULL) printf("Surface is NULL: %s\n", 
											  TTF_GetError());
		scoreText = SDL_CreateTextureFromSurface(g_renderer, scoreSurfaceText);
		//Points Surface
		pointsSurfaceText = NULL;
		pointsText = SDL_CreateTextureFromSurface(g_renderer, 
												  pointsSurfaceText);
		//Score Rectangle
		scoreRect.x = 0;
		scoreRect.y = 0;
		scoreRect.w = 100;
		scoreRect.h = 50;
		//Points Rectangle
		pointsRect.x = 100;
		pointsRect.y = 20;
		pointsRect.w = 25;
		pointsRect.h = 25;	
	}
	
	void printScore()
	{
		
		//TTF_Font* Sans = TTF_OpenFont("includes/Subterran.ttf", 24);
		std::stringstream out;
		out << points;
		pointsSurfaceText = TTF_RenderText_Solid(Sans, 
												 out.str().c_str(), WHITE);
		if (pointsSurfaceText == NULL) printf("pointsSurfaceText = NULL: %s\n",
											  TTF_GetError());
		pointsText = SDL_CreateTextureFromSurface(g_renderer, 
												  pointsSurfaceText);
	}
	

	void freeSurface()
	{
		SDL_FreeSurface(pointsSurfaceText);	
	}

	TTF_Font* Sans = NULL;
	SDL_Surface* scoreSurfaceText = NULL;
	SDL_Texture* scoreText = NULL;
	SDL_Rect scoreRect;
	SDL_Surface* pointsSurfaceText = NULL;
	SDL_Texture* pointsText = NULL;
	SDL_Rect pointsRect;
	int points;
};

#endif
