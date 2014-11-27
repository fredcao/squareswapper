#ifndef __BOARD_L1__
#define __BOARD_L1__

#include "board.h"

class BoardL1 : public Board {


	// Private stuff


	public:

	BoardL1();
	~BoardL1();

	void constructBoard();
	Square *getSquare(int r, int c);


};


#endif
