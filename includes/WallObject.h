/*
* File: WallObject.h
*
* This class will encapsulate the data for all of the
* wall objects that we create. This will control the x,
* y, and h values "behind the scenes" so that our code
* is very easy to read. Our other wall objects will
* inherit this class. Because the variables are private
* we need to use the mutators and accessors to access
* the variables.
* Example - to increase the x_ variable by 5, you can
* simply call objectName.incX(5)
*
*/

#ifndef WALLOBJECT_H
#define WALLOBJECT_H

#include <iostream>

class WallObject
{
public:
	/** Constructor **/
	WallObject();
	/** Accessors **/
	int getX() const;
	int getY() const;
	int getH() const;
	/** Mutators **/
	void setX(const int &);
	void setY(const int &);
	void setH(const int &);
	void incX(const int &);
	void incY(const int &);
	void incH(const int &);
	void decX(const int &);
	void decY(const int &);
	void decH(const int &);
private:
	int x_;
	int y_;
	int h_;
};

#endif