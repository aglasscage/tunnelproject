/*
* File: RandWall.cpp
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include "RandWall.h"
#include "Constants.h"

/** Constructor **/
RandWall::RandWall()
	: incline_(1)
{
	setT();
	if (rand() % 2 == 1) dy_ = 1;
	else dy_ = -1;

	if (dy_ == 1) d_ = DOWN;
	else d_ = UP;
}
/** Accessors **/
int RandWall::getDY() const
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
void RandWall::setDY(const int & dy)
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

	int r = rand() % 2 + 1;
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
void RandWall::swapD()
{
	if (d_ == DOWN)
	{
		d_ = UP;
	}
	else
	{
		d_ = DOWN;
	}
}
/** Other Functions **/
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
void RandWall::init(const int & y, const bool & d, int h)
{
	incX(W); // by default X is is set to W or 640 - off of the screen.
	incY(y);
	incH(h);
	/*
	for (int i = 0; i < H; i++)
	{
		RandWall::bitmap[i] = 0;
	}
	if (d == UP)
	{
		for (int i = getY(); i >= 0; --i)
		{
			bitmap[i] = 1;
		}
	}
	if (d == DOWN)
	{
		for (int i = getY(); i < 479; ++i)
		{
			bitmap[i] = 1;
		}
	}
	*/
}
/*
void RandWall::updateBit(const int & dy, const bool & d)
{
	if (d == UP) // this is the upper wall. going down -= 1, going up += 1
	{
		if (dy > 0)
		{
			for (int i = getY(); i <= getY() + dy; i++)
			{
				if (i >= 479) break;
				bitmap[i] = 1;
			}
		}
		else if (dy < 0)
		{
			for (int i = getY(); i >= getY() + dy; i--)
			{
				if (i <= 0) break;
				bitmap[i] = 0;
			}
		}
	}
	else
	{
		if (dy > 0)
		{
			for (int i = getY(); i <= getY() + dy; i++)
			{
				if (i >= 479) break;
				bitmap[i] = 0;
			}
		}
		else if (dy < 0)
		{
			for (int i = getY(); i >= getY() + dy; i--)
			{
				if (i <= 0) break;
				bitmap[i] = 1;
			}
		}
	}
}
*/
void RandWall::checkSpace()
{
	/*
	int check = 0;
	for (int i = 0; i < H; i++)
	{
		if (bitmap[i] == 0) check++;
	}

	std::cout << check << std::endl;
	int x;
	std::cin >> x;
	*/

	if (getT() > 30)
	{
		if (getY() < 100 && getD() == UP
			|| getY() > 379 && getD() == DOWN)
		{
			setT(30);
		}
	}
	/*
	if (getT() > 30 && check < 200 && get_tStart() - getT() > 50)
	{
		setT(30);
	}
	*/
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
		if (getIncline() == 2 && (getT() < 50 || getT() > get_tStart() - 40))
		{
			dy = 3 * getDY();
		}
		else
		{
			dy = 2 * getDY();
		}
	}
	incY(dy);
	if (orientation == UP)
	{
		setH(getY());
	}
	else if (orientation == DOWN)
	{
		setH(H - 2 - getY());
	}
	if (getT() == 0)
	{	
		swapD();
		getD() == UP ? setDY(-1) : setDY(1);
		decT();
	}
	else if (getT() == 10)
	{
		setDY(0);
	}
	if (abs(r.getY() - getY()) < 80
		&& getT() > 30
		&& orientation != getD())
	{
		setT(30);
	}
	checkSpace();
	decT();
}