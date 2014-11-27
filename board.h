#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
#include "textdisplay.h"
#include "window.h"
#include "PRNG.h"

class Board {

	protected:

	static Board *instance;

	static Square ***board;
	
	int boardSize;
	int level;
	int movesLeft;
	int score;
	int highscore;

	// Options set by user
	bool textOnlyFlag;
	int seed;
	std::string file;
	std::string colourInput;
	int colourInputIndex;
	int startLevel;


	Square **stack;

	TextDisplay *td;
	Xwindow *xw;

	// Private stuff
	public:			//TESTING, CHANGE BACK TO PROTECTED LATER
	void clearRow(int row);
	void clearCol(int col);
	void explode(int centerX, int centerY, int width);
	void clearColour(int colour);
	

	protected:
	
	virtual Square *getSquare(int r, int c);

	void doEffect(Square *sq, int width);

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
