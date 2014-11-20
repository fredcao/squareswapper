#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"

class Board {

	protected:

	static Board *instance;

	Square ***board;
	TextDisplay *td;
	Xwindow *xw;
	
	int boardSize;
	int level;
	int movesLeft;
	int score;
	int highscore;

	// Private stuff

	void clearBoard();

	public:

	virtual ~Board();
	virtual constructBoard() = 0;
	static Board *getInstance();
	int getLevel();
	int getMovesLeft();
	int getScore();
	int getHighScore();
	
	void printBoard();
	void cleanup();	
	


};



#endif
