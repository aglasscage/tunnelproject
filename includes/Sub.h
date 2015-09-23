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
	int getSuby() const { return subRect.y; }
	
	void setSuby(int newY)
	{
		subRect.y = newY;			
	}
	
	void moveSub()		{ subRect.y += dy; } 
//private:
	SDL_Texture* subTexture = NULL;
	SDL_Rect subRect;
	int dy = 0;
};

#endif

