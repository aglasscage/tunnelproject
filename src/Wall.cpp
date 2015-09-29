/*
* File: Wall.cpp
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>
#include "Wall.h"
#include "Constants.h"

/** Constructor **/
Wall::Wall()
	: orientation_(TOP)
{}
/** Initializer **/
void Wall::init(const int & x, const int & orientation)
{
	setX(x);
	setO(orientation);
}
/** Accessors **/
int Wall::getX() const
{
	return x_;
}
int Wall::getY() const
{
	return y_;
}
bool Wall::getO() const
{
	return orientation_;
}
int Wall::getY2()
{
	int y2;
	getO() == UP ? y2 = 0 : y2 = H - 1;
	return y2;
}
int Wall::getX2()
{
	/*
	* Return getX(), because x2 will always be the same
	* as x1. This only exists to make the program easier
	* to read.
	*/
	return getX();
}
/** Mutators **/
void Wall::setX(const int & x)
{
	x_ = x;
}
void Wall::setY(const int & y)
{
	y_ = y;
}
void Wall::setO(const int & orientation)
{
	orientation_ = orientation;
}
/** Operators **/
Wall & Wall::operator=(const RandWall & r)
{
	/*
	* This function allows us to set our wall equal to our
	* rand wall that we change every iteration. We only need
	* to set the Y and H values because the X values of our
	* cave walls do not change.
	*/
	if (*this != r)
	{
		setY(r.getY());
	}
}
Wall & Wall::operator=(const Wall & c)
{
	/*
	* This function allows us to set our walls equal to
	* each other. Similar to the above function, we only
	* need to set the Y and H values because the X values
	* of our cave walls do not change.
	*/
	if (*this != c)
	{
		setY(c.getY());
	}
}
bool Wall::operator!=(const RandWall & r)
{
	/*
	* This function allows us to check if our wall objects
	* are already equal to eachother before we perform
	* the = operator.
	*/
	if (getY() == r.getY())
	{
		return false;
	}
	return true;
}
bool Wall::operator!=(const Wall & c)
{	
	/*
	* This function allows us to check if our first wall
	* is already equal to our RandWall. If they are already
	* equal then we won't perform the = operator.
	*/
	if (getY() == c.getY())
	{
		return false;
	}
	return true;
}
/** Other Functions **/
void Wall::draw(Renderer & g_renderer)
{
	/*
	* Draw the line for this Wall object. Use the simple SDL
	* functions. The hexidecimal can also be written as decimal.
	*/
	SDL_SetRenderDrawColor(g_renderer, 0x20, 0x20, 0x20, 0x20);
	SDL_RenderDrawLine(g_renderer, getX(), getY(), getX2(), getY2());
	/*
	int y = getY();
	do
	{
		SDL_RenderDrawPoint(g_renderer, getX(), y);
		y > getY2() ? y-- : y++;
	} while (y != getY2());
	*/
}