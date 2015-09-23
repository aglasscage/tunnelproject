/*
* File: RandWall.h
*/

#ifndef RANDWALL_H
#define RANDWALL_H

#include "WallObject.h"
#include <bitset>

class RandWall : public WallObject
{
public:
	/** Constructor **/
	RandWall();
	/** Accessors **/
	int getDY() const;
	int getT() const;
	int get_tStart() const;
	bool getD() const;
	/** Mutators **/
	void setDY(const int &);
	void setT(const int &);
	void setT();
	void set_tStart(const int &);
	void decT();
	void setD(const bool &);
	void swapD();
	/** Other Functions **/
	void checkSpace();
	//void updateBit(const int &, const bool &);
	void init(const int &, const bool &, int h=99);
	void randomize(const bool &, const RandWall &);
private:
	int dy_; //Change in Y
	int t_;
	int tStart_;
	bool d_; //Direction. (0 = North) (1 = South)
};

#endif