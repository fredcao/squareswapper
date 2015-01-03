#ifndef __BOARD_L2__
#define __BOARD_L2__

#include "board.h"

class BoardL2 : public Board {


	int scoreNeeded;

	public:

	BoardL2();
	~BoardL2();

	void constructBoard();
	Square *getSquare(int r, int c);
	int getScoreNeeded();

};


#endif
