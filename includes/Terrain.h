/*
* File: Terrain.h
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL2/SDL.h>
#include "RandWall.h"
#include "Wall.h"
#include "Constants.h"

class Terrain
{
public:
	Terrain();
	void draw(SDL_Renderer* & g_renderer)
    {
    	for (int i = 0; i < WALL_TOTAL; i++)
    	{
    		tWall[i].draw(g_renderer);
            bWall[i].draw(g_renderer);
    	}
    }
    void update();
private:
	Wall tWall[WALL_TOTAL];
    Wall bWall[WALL_TOTAL];
	RandWall topRand;
    RandWall botRand;
};

#endif