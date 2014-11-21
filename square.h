#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>

class Square{
	protected:
	int row,col,colour,type;
	bool locked;
	virtual void draw() = 0;
	public:
	enum { BasicSquare = 0, LateralSquare, UprightSquare, UnstableSquare, PsychedelicSquare };
	enum { White = 0, Red, Green, Blue };
	Square();
	virtual ~Square();
	int getRow();
	int getCol();
	int getColour();
	int getType();
	bool getLocked();
	virtual void print();
	virtual void notify() = 0;
};

#endif
