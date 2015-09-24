#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "SDL2/SDL.h"

const int W = 640;
const int H = 480;
const int WALL_TOTAL = W;
const int SEED_Y_TOP = 99;
const int SEED_Y_BOT = 379;
const int SEED_H = 100;
const int DY = 2;
const int HEIGHT_OF_SUB = 20;
//Submarine Constants
const int SUB_HEIGHT = 25;
const int SUB_WIDTH = 25;
//Other
typedef SDL_Renderer* Renderer;
typedef SDL_Event Event;

enum Direction
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

enum Orientation
{
	TOP = 0,
	BOT = 1,
	MID = 2
};

#endif
