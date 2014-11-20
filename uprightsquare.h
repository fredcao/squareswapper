#ifndef __UPRIGHTSQUARE_H__
#define __UPRIGHTSQUARE_H__
#include "square.h"

class UprightSquare: public Square{
	
	public:
	UprightSquare(int row, int col,int colour, bool locked);
	~UprightSquare();
	void notify();
};

#endif	
