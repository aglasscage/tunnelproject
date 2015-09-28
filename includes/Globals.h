#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL2/SDL.h>

SDL_Texture* load_texture(std::string path);
SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;
//Colors
const SDL_Color WHITE = {255, 255, 255, 255};
#endif

