#ifndef SUB_H
#define SUB_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <surface.h>

const int SUB_HEIGHT = 50;
const int SUB_WIDTH = 50;

class Sub
{
public:	
	Sub()
	{
		subImage = SDL_LoadBMP("includes/submarine.bmp");
		subRect.x = 640 / 2 - SUB_WIDTH / 2;
		subRect.y = 480 / 2 - SUB_HEIGHT / 2;
		subRect.h = SUB_HEIGHT;
		subRect.w = SUB_WIDTH;
	}

	void move(int i)
	{
		switch(i)
		{
			case 0:
				subRect.y -= 10;
				break;
			case 1:
				subRect.y += 10;
				break;
			case 2:
				subRect.x -= 10;
				break;
			case 3:
				subRect.x += 10;
				break;		
		}
	}

	void cleanup()
	{
		SDL_FreeSurface(subImage);
		subImage = NULL;
	}
//private:
	SDL_Surface *subImage;
	SDL_Rect subRect;
};

#endif

