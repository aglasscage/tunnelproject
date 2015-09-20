/*
* File: Wall.cpp
*/

#include <cstdlib>
#include <ctime>
#include "Constants.h"
#include "Terrain.h"

Terrain::Terrain()
{
	topRand.init(SEED_Y_TOP, UP);
	botRand.init(SEED_Y_BOT, DOWN);

	for (int i = 0; i < WALL_TOTAL; i++)
	{
		tWall[i].init(i, TOP);
		bWall[i].init(i, BOT);
		update();
	}
}
void Terrain::update()
{
	topRand.randomize(TOP);
	botRand.randomize(BOT);
	for (int i = 0; i < WALL_TOTAL - 1; i++)
	{
		tWall[i] = tWall[i + 1];
		bWall[i] = bWall[i + 1];

	}
	tWall[WALL_TOTAL - 1] = topRand;
	bWall[WALL_TOTAL - 1] = botRand;
}