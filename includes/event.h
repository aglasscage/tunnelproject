#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
	Event()
	{}
	bool check_quit()
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				return true;
			}
		}
		return false;
	}
private:
	SDL_Event e;
};

#endif