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


	void clearRow(int row);
	void clearCol(int col);
	void explode(int centerX, int centerY, int width);
	void clearColour(int colour);

	int dropSquare(int currentRow, int col);
	void dropFill();

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
	void setDisplay(TextDisplay *td);
	void setWindow(Xwindow *xw);
		
	void printBoard();
	static void cleanup();	
	


};



#endif
