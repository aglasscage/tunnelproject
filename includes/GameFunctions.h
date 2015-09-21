#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "SDL2/SDL.h"
#include "Constants.h"

void init()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	g_window = SDL_CreateWindow("Random Terrain Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W,
		H, SDL_WINDOW_SHOWN);

	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int img_flags = IMG_INIT_PNG;

	IMG_Init((img_flags)&img_flags);
}

void eventHandler(Event & e, bool & quit)
{
	while(SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if(e.type == SDL_QUIT)
		{
			quit = true;
		}
	}
}

void background(Renderer & g_renderer)
{
	SDL_SetRenderDrawColor(g_renderer, 40, 40, 255, 40);
	SDL_RenderClear(g_renderer);
}

SDL_Texture* load_texture(std::string path)
{
	SDL_Texture* new_texture = NULL;

	SDL_Surface* loaded_surface = IMG_Load(path.c_str());

	new_texture = SDL_CreateTextureFromSurface(g_renderer, loaded_surface);

	SDL_FreeSurface(loaded_surface);

	return new_texture;
}

void close()
{
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	g_renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

void delay(const int & m)
{
	SDL_Delay(m);
}

#endif
