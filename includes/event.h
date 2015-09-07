#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
	Event()
	{}
	int check_event()
	{
		if (e.type == SDL_QUIT)
		{
			return -9999;
		}
		if (e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_UP:
					return 0;
					break;
				case SDLK_DOWN:
					return 1;
					break;
				case SDLK_LEFT:
					return 2;
					break;
				case SDLK_RIGHT:
					return 3;
					break;
			}
		}
	}
	
	int poll()
	{
		return SDL_PollEvent(&e);
	}
private:
	SDL_Event e;
};

#endif
