#ifndef __BASICSQUARE_H__
#define __BASICSQUARE_H__
#include "square.h"

class BasicSquare: public Square{
	
	public:
	~BasicSquare();
	int getColour();
	int getRow();
	int getCol();
	int getType();
	void notify();
};

#endif	
