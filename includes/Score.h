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
		//Continue Surface
		conSurfaceText = TTF_RenderText_Solid(Sans, "Press SPACE", WHITE);
		if (conSurfaceText == NULL) printf("Surface is NULL: %s\n", 
											  TTF_GetError());
		conText = SDL_CreateTextureFromSurface(g_renderer, conSurfaceText);
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
		//Continue Rectanble
		conRect.x = 225;
		conRect.y = 400;
		conRect.w = 175;
		conRect.h = 75;
	}

	void init()
	{
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

		setPoints(0);
	}

	void setPoints(const int & p)
	{
		points = p;
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
	
	void printFinal()
	{
		static int r = 254;
		static int g = 254;
		static int b = 0;
		static bool direction = true;
		
		if (r == 50) direction = false;
		else if (r == 254) direction = true;

		if (direction == true)
		{
			r -= 2;
			g -= 2;
		}
		else
		{
			r += 2;
			g += 2;
		}
		SDL_Color color = {r, g, b, 255};
		//Score Rectangle
		scoreRect.x = 235;
		scoreRect.y = 200;
		scoreRect.w = 100;
		scoreRect.h = 75;
		//Points Rectangle
		pointsRect.x = 335;
		pointsRect.y = 220;
		pointsRect.w = 50;
		pointsRect.h = 50;	
		//TTF_Font* Sans = TTF_OpenFont("includes/Subterran.ttf", 24);
		std::stringstream out;
		out << points;
		pointsSurfaceText = TTF_RenderText_Solid(Sans, 
												 out.str().c_str(), color);
		if (pointsSurfaceText == NULL) printf("pointsSurfaceText = NULL: %s\n",
											  TTF_GetError());
		pointsText = SDL_CreateTextureFromSurface(g_renderer, 
												  pointsSurfaceText);
		conText = SDL_CreateTextureFromSurface(g_renderer, 
												  conSurfaceText);
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
	SDL_Surface* conSurfaceText = NULL;
	SDL_Texture* conText = NULL;
	SDL_Rect conRect;
	int points;
};

#endif
