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
	: incline_(0)
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
void RandWall::setT(const bool & orientation)
{
	if (orientation == TOP && getDY() == 1)
	{
		t_ = rand() % 100 + 40;
		set_tStart(t_);
		int r = rand() % 4;
		setIncline(r);
	}
	else if (orientation == BOT && getDY() == -1)
	{
		t_ = rand() % 100 + 40;
		set_tStart(t_);
		int r = rand() % 4;
		setIncline(r);
	}
	else
	{
		setT(get_tStart());
	}
}
void RandWall::setT()
{
	t_ = rand() % 50 + 50;
	set_tStart(t_);
	int r = rand() % 2;
	setIncline(r);
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
/** Other Functions **/
void RandWall::incY(const int & n)
{
	setY(getY() + n);
}
void RandWall::decT(const bool & orientation)
{
	if (t_ == -1)
	{
		setT(orientation);
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
	float slopeZero;
	float piece;

	switch (getIncline())
	{
		case 0:
			piece = get_tStart() / 6.0;
			if (getT() <= piece * 2 || getT() > get_tStart() - piece)
			{
				if (getT() % 4 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else if ((getT() > piece * 2 && getT() <= piece * 3) ||
					 (getT() <= get_tStart() - piece && 
					  getT() > get_tStart() - piece * 2))
			{
				if (getT() % 3 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else
			{
				if (getT() % 2 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			break;
		case 1:
			piece = get_tStart() / 6.0;
			if (getT() <= piece * 2 || getT() > get_tStart() - piece)
			{
				if (getT() % 4 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else if ((getT() > piece * 2 && getT() <= piece * 3) ||
					 (getT() <= get_tStart() - piece && 
					  getT() > get_tStart() - piece * 2))
			{
				if (getT() % 2 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else
			{
				dy = 1 * getDY();
			}
			break;
		case 2:
			piece = get_tStart() / 8.0;
			if (getT() <= piece * 2 || getT() > get_tStart() - piece)
			{
				if (getT() % 4 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else if ((getT() > piece * 2 && getT() <= piece * 3) ||
					 (getT() <= get_tStart() - piece && 
					  getT() > get_tStart() - piece * 2))
			{
				if (getT() % 2 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else if ((getT() > piece * 2 && getT() <= piece * 4) ||
					 (getT() <= get_tStart() - piece && 
					  getT() > get_tStart() - piece * 3))
			{
				dy = 1 * getDY();
			}
			else
			{
				dy = 2 * getDY();
			}
			break;
		case 3:
			piece = get_tStart() / 10.0;
			if (getT() <= piece * 2 || getT() > get_tStart() - piece)
			{
				if (getT() % 4 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else if ((getT() > piece * 2 && getT() <= piece * 3) ||
					 (getT() <= get_tStart() - piece && 
					  getT() > get_tStart() - piece * 2))
			{
				if (getT() % 2 == 0) dy = 1 * getDY();
				else dy = 0;
			}
			else if ((getT() > piece * 2 && getT() <= piece * 4) ||
					 (getT() <= get_tStart() - piece && 
					  getT() > get_tStart() - piece * 3))
			{
				dy = 1 * getDY();
			}
			else if ((getT() > piece * 2 && getT() <= piece * 5) ||
					 (getT() <= get_tStart() - piece && 
					  getT() > get_tStart() - piece * 4))
			{
				dy = 2 * getDY();
			}
			else
			{
				dy = 3 * getDY();
			}
			break;
	}
	/*
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
	*/
	incY(dy);
	if (getT() == 0)
	{	
		getDY() > 0 ? setDY(-1.0) : setDY(1.0);
	}
	else if (getT() == int(piece))
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
	decT(orientation);
}