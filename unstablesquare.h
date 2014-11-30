#ifndef __UNSTABLESQUARE_H__
#define __UNSTABLESQUARE_H__
#include "square.h"

class UnstableSquare: public Square{
	void draw();	
	public:
	UnstableSquare(int row, int col, int colour, bool locked, Xwindow *xw);
	~UnstableSquare();
	void print();
	bool notify();
};

#endif	
