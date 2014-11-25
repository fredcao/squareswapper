#ifndef __BOARD_L2__
#define __BOARD_L2__

#include "board.h"

class BoardL2 : public Board {


	// Private stuff


	public:

	BoardL2();
	~BoardL2();

	void constructBoard();
	Square *getSquare();


};


#endif
