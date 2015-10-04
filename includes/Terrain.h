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
    bool collision(const SDL_Rect & r)
    {
        /*
        * This is for collision detection. We're just
        * checking to see if the sub is higher or lower
        * on the screen than the top or bottom walls.
        * You notice the constant "5" is just to make
        * the hit box slightly smaller than the image
        * (5 pixels smaller in each direction).
        */
        for (int i = r.x + 8; i < r.x + r.w - 8; i++)
        {
            if (r.y + 8 < tWall[i].getY()
                || r.y + r.h - 8 > bWall[i].getY())
            {
                return 0;
            }
        }
        return 1;
    }
private:
	Wall tWall[WALL_TOTAL];
    Wall bWall[WALL_TOTAL];
	RandWall topRand;
    RandWall botRand;
};

#endif