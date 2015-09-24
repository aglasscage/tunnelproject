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
		: alive_(true), dy(0)
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
	bool setAlive(const bool & alive)
	{
		alive_ = alive;
	}
	bool getAlive() const
	{
		return alive_;
	}
	SDL_Rect getRect() const
	{
		return subRect;
	}
	void movement()
	{
		const Uint8 * keystate = SDL_GetKeyboardState(NULL);
   	 	if(keystate[SDL_SCANCODE_SPACE])
    	{
    		dy = -3;
    	}
	    else
	    {
	    }
	    if (dy <= 1)
		{
			dy++;
		}
	    subRect.y += dy;
	}
	void moveSub()		{ subRect.y += dy; } 
//private:
	SDL_Texture* subTexture = NULL;
	SDL_Rect subRect;
	int dy;
private:
	bool alive_;
};

#endif
