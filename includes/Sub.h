#ifndef SUB_H
#define SUB_H

#include <SDL2/SDL.h>
#include <Constants.h>
#include <Globals.h>
#include <GameFunctions.h>
 
class Sub
{
public:
	Sub()
	{
		subTexture = load_texture("includes/sub.png");
		subRect.x = W / 2 - SUB_WIDTH / 2;
		subRect.y = H / 2 - SUB_HEIGHT / 2;
		subRect.h = SUB_HEIGHT;
		subRect.w = SUB_WIDTH;
	}
	int getSuby(Sub s) const { return subRect.y; }
	void setSuby(Sub s, int newY)
	{
		subRect.y += newY;			
	}

	
//private:
	SDL_Texture* subTexture = NULL;
	SDL_Rect subRect;
};

#endif

