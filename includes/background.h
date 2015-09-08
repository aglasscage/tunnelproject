#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <surface.h>

class Background
{
public:	
	Background()
	{
		bgImage = SDL_LoadBMP("image/background.bmp");
		bgRect.x = 0;
		bgRect.y = 0;
		bgRect.h = 480;
		bgRect.w = 640;
	}

	void cleanup()
	{
		SDL_FreeSurface(bgImage);
		bgImage = NULL;
	}

//private:
	SDL_Rect bgRect;
	SDL_Surface *bgImage;
};

#endif
