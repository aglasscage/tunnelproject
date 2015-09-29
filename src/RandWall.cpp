/*
* File: RandWall.cpp
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RandWall.h"
#include "Constants.h"

/** Constructor **/
RandWall::RandWall()
	: incline_(1)
{
	setT();
	if (rand() % 2 == 1) dy_ = 1.0;
	else dy_ = -1.0;

	if (dy_ == 1.0) d_ = DOWN;
	else d_ = UP;
}
/** Accessors **/
int RandWall::getY() const
{
	return y_;
}
float RandWall::getDY() const
{
	return dy_;
}
int RandWall::getT() const
{
	return t_;
}
int RandWall::get_tStart() const
{
	return tStart_;
}
bool RandWall::getD() const
{
	return d_;
}
int RandWall::getIncline() const
{
	return incline_;
}
/** Mutators **/
void RandWall::setY(const int & y)
{
	y_ = y;
}
void RandWall::setDY(const float & dy)
{	
	dy_ = dy;
}
void RandWall::setT(const int & t)
{
	t_ = t;
}
void RandWall::setT()
{
	t_ = rand() % 50 + 50;
	set_tStart(t_);
}
void RandWall::set_tStart(const int & tStart)
{
	tStart_ = tStart;
}
void RandWall::setD(const bool & d)
{
	d_ = d;
}
void RandWall::setIncline(const int & incline)
{
	incline_ = incline;
}
void RandWall::swapD(const bool & orientation)
{
	if (d_ == DOWN)
	{
		d_ = UP;
	}
	else
	{
		d_ = DOWN;
	}

	if (d_ != orientation)
	{
		int r = rand() % 3 + 1;
		setIncline(r);
	}
}
/** Other Functions **/
void RandWall::incY(const int & n)
{
	setY(getY() + n);
}
void RandWall::decT()
{
	if (t_ == -1)
	{
		setT();
	}
	else
	{
		t_--;
	}
}
void RandWall::init(const int & y)
{
	setY(y);
}
void RandWall::checkSpace()
{
	if (getT() > 30)
	{
		if (getY() < 100 && getDY() < 0.0
			|| getY() > 379 && getDY() > 0.0)
		{
			setT(30);
		}
	}
}
void RandWall::randomize(const bool & orientation, const RandWall & r)
{
	int dy;
	if (getT() < 20 || getT() > get_tStart() - 10)
	{
		if (getT() % 2 == 0) dy = 1 * getDY();
		else dy = 0;
	}
	else if (getT() < 30 || getT() > get_tStart() - 20)
	{
		dy = 1 * getDY();
	}
	else
	{
		if (getIncline() > 1 && (getT() < 50 || getT() > get_tStart() - 40))
		{
			dy = 3 * getDY();
		}
		else if (getIncline() == 2 && (getT() < 60 || getT() > get_tStart() - 50))
		{
			dy = 4 * getDY();
		}
		else
		{
			dy = 2 * getDY();
		}
	}
	incY(dy);
	if (getT() == 0)
	{	
		getDY() > 0 ? setDY(-1.0) : setDY(1.0);
		decT();
	}
	else if (getT() == 10)
	{
		getDY() > 0 ? setDY(.5) : setDY(-.5);
	}

	if (abs(getY() - r.getY()) < 100 && getT() > 30)
	{
		if (orientation == BOT && getDY() < 0
			|| orientation == TOP && getDY() > 0)
		{
			setT(30);
		}
	}

	checkSpace();
	decT();
}