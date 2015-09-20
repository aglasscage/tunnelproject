/*
* File: Wall.h
*/

#ifndef WALL_H
#define WALL_H

#include "WallObject.h"
#include "RandWall.h"
#include "Constants.h"

class Wall : public WallObject
{
public:
	/** Constructor **/
	Wall();
	/** Initializer **/
	void init(const int &, const int &);
	/** Accessors **/
	bool getO() const;
	int getX2();
	int getY2();
	/** Mutators **/
	void setO(const int &);
	/** Operators **/
	Wall & operator=(const RandWall &);
	Wall & operator=(const Wall &);
	bool operator !=(const RandWall &);
	bool operator !=(const Wall &);
	void draw(Renderer &);
private:
	int orientation_;
	/*
	* This variable represents the orientation of
	* the wall object on the screen. There is an 
	* enum in the Global.h file where 0 = TOP,
	* 1 = BOT, and 2 = MID. The orientation controls
	* some of the behaviors of the wall. Currently
	* MID is not used in our program... but could
	* be added with ease. For example, if we wanted
	* a third wall to randomly generate in our game.
	*/
};

#endif