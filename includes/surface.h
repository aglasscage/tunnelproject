#ifndef SURFACE_H
#define SURFACE_H

#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Surface
{
public:
	Surface()
		: gWindow(NULL), gScreenSurface(NULL)
	{}
	void init()
	{
		bool success = true;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			printf("Failed to initialize SDL\n");
			success = false;
		}
		else
		{
			gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, 					  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
					  SDL_WINDOW_SHOWN);
			renderer = SDL_CreateRenderer(gWindow, -1, 0);
			if (gWindow == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", 
						SDL_GetError());
				printf("Failed to initialize SDL\n");
				success = false;
			}
			else
			{
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}
	void close()
	{
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
		SDL_Quit();
	}
	void update()
	{
		SDL_BlitSurface(NULL, NULL, gScreenSurface, NULL);
		SDL_UpdateWindowSurface(gWindow);
	}
	void delay(const int & milli)
	{
		SDL_Delay(milli);
	}
private:
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
	SDL_Renderer* renderer;
};

#endif
