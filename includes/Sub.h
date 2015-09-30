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
		: alive_(true), dy(0), momentum_(0)
	{
		subTexture = load_texture("includes/sub.png");
		subRect.x = W / 2 - SUB_WIDTH / 2;
		subRect.y = H / 2 - SUB_HEIGHT / 2;
		subRect.h = SUB_HEIGHT;
		subRect.w = SUB_WIDTH;
	}
	int getSuby() const { return subRect.y; }
	void incMomentum()
	{
		if (momentum_ < 15) momentum_++;
	}
	void decMomentum()
	{
		if (momentum_ > 0) momentum_--;
	}
	int getMomentum() const
	{
		return momentum_;
	}
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
    		incMomentum();
    		if (getMomentum() < 4)
    		{
    			dy = -0;
    		}
    		else if (getMomentum() < 8)
    		{
    			dy = -1;
    		}
    		else if (getMomentum() < 12)
    		{
    			dy = -2;
    		}
    		else
    		{
    			dy = -3;
    		}
    	}
	    else
	    {
	    	decMomentum();
	    	if (getMomentum() >= 12)
	    	{
	    		dy = -3;
	    	}
	    	else if (getMomentum() >= 8)
	    	{
	    		dy = -2;
	    	}
	    	else if (getMomentum() >= 4)
	    	{
	    		dy = -1;
	    	}
	    	else if (getMomentum() > 0)
	    	{
	    		dy = 0;
	    	}
	    	else
	    	{
	    		// Speed of the ship while it is sinking.
	    		dy = 2;
	    	}
	    }
	    subRect.y += dy;
	}
	void moveSub()		{ subRect.y += dy; } 
//private:
	SDL_Texture* subTexture = NULL;
	SDL_Rect subRect;
private:
	int dy;
	bool alive_;
	int momentum_;
};

#endif
