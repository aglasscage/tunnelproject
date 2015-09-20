/*
* File: WallObject.cpp
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "WallObject.h"
#include "Constants.h"

/** Constructor **/
WallObject::WallObject()
	: x_(0), y_(0), h_(0)
{}
/** Accessors **/
int WallObject::getX() const
{
	return x_;
}
int WallObject::getY() const
{
	return y_;
}
int WallObject::getH() const
{
	return h_;
}
/** Mutators **/
void WallObject::setX(const int & x)
{
	x_ = x;
}
void WallObject::setY(const int & y)
{
	y_ = y;
}
void WallObject::setH(const int & h)
{
	h_ = h;
}
void WallObject::incX(const int & n)
{
	setX(getX() + n);
}
void WallObject::incY(const int & n)
{
	setY(getY() + n);
}
void WallObject::incH(const int & n)
{
	setH(getH() + n);
}
void WallObject::decX(const int & n)
{
	decX(getX() - n);
}
void WallObject::decY(const int & n)
{
	decY(getY() - n);
}
void WallObject::decH(const int & n)
{
	decH(getH() - n);
}