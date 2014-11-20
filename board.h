#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"
#include "textdisplay.h"
#include "window.h"

class Board {

	protected:

	static Board *instance;

	Square ***board;
	
	int boardSize;
	int level;
	int movesLeft;
	int score;
	int highscore;

	TextDisplay *td;
	Xwindow *xw;

	// Private stuff

	void clearBoard();

	public:

	Board();
	virtual ~Board();
	virtual void constructBoard(); 
	static Board *getInstance();
	int getLevel();
	int getMovesLeft();
	int getScore();
	int getHighScore();
	
	void printBoard();
	static void cleanup();	
	


};



#endif
