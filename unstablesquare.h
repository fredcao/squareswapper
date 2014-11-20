#ifndef __UNSTABLESQUARE_H__
#define __UNSTABLESQUARE_H__
#include "square.h"

class UnstableSquare: public Square{
	
	public:
	~UnstableSquare();
	int getColour();
	int getRow();
	int getCol();
	int getType();
	void notify();
};

#endif	
