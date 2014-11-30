#ifndef __BOARD_L1__
#define __BOARD_L1__

#include "board.h"

class BoardL1 : public Board {


	// Private stuff
	int scoreNeeded;


	public:

	BoardL1();
	~BoardL1();

	void constructBoard();
	Square *getSquare(int r, int c);
	int getScoreNeeded();

};


#endif
