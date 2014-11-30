#ifndef __BASICSQUARE_H__
#define __BASICSQUARE_H__

#include "square.h"

class BasicSquare: public Square{

	void draw();	
	public:
	BasicSquare(int r, int c, int colour, bool locked, Xwindow *xw = NULL);
	~BasicSquare();
	void print();
	bool notify();
};

#endif	
