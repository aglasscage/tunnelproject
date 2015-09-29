/*
* File: RandWall.h
*/

#ifndef RANDWALL_H
#define RANDWALL_H

class RandWall
{
public:
	/** Constructor **/
	RandWall();
	/** Accessors **/
	int getY() const;
	float getDY() const;
	int getT() const;
	int get_tStart() const;
	bool getD() const;
	int getIncline() const;
	/** Mutators **/
	void setY(const int &);
	void setDY(const float &);
	void setT(const int &);
	void setT(const bool &);
	void setT();
	void set_tStart(const int &);
	void decT(const bool &);
	void incY(const int &);
	void setD(const bool &);
	void setIncline(const int &);
	/** Other Functions **/
	void checkSpace();
	//void updateBit(const int &, const bool &);
	void init(const int &);
	void randomize(const bool &, const RandWall &);
private:
	int y_;
	float dy_; //Change in Y
	int t_;
	int tStart_;
	int incline_;
	bool d_; //Direction. (0 = North) (1 = South)
};

#endif