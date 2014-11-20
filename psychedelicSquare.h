#ifndef __PSYCHEDELICSQUARE_H__
#define __PSYCHEDELICSQUARE_H__
#include "square.h"

class PsychedelicSquare: public Square{
	
	public:
	~PsychedelicSquare();
	int getColour();
	int getRow();
	int getCol();
	int getType();
	void notify();
};

#endif	
