#ifndef __LATERALSQUARE_H__
#define __LATERALSQUARE_H__
#include "square.h"

class LateralSquare: public Square{
	void draw();	
	public:
	LateralSquare(int row, int col, int colour, bool locked);
	~LateralSquare();
	void print();
	void notify();
};

#endif	
