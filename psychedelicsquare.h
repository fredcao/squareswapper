#ifndef __PSYCHEDELICSQUARE_H__
#define __PSYCHEDELICSQUARE_H__
#include "square.h"

class PsychedelicSquare: public Square{
	
	public:
	PsychedelicSquare(int row, int col, int colour,bool locked);
	~PsychedelicSquare();
	void notify();
};

#endif	
