#ifndef __BASICSQUARE_H__
#define __BASICSQUARE_H__
#include "square.h"

class BasicSquare: public Square{
	
	public:
	BasicSquare(int r, int c, int colour, bool locked);
	~BasicSquare();
	void notify();
};

#endif	
