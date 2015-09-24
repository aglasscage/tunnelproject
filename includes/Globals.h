#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL2/SDL.h>

SDL_Texture* load_texture(std::string path);
SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;
//Colors
SDL_Color White = {255, 255, 255};
//Fonts
TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
#endif

