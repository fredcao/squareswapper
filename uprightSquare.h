#ifndef __UPRIGHTSQUARE_H__
#define __UPRIGHTSQUARE_H__
#include "square.h"

class UprightSquare: public Square{
	
	public:
	~UprightSquare();
	int getColour();
	int getRow();
	int getCol();
	int getType();
	void notify();
};

#endif	
