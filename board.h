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
	
	static int boardSize;
	static int level;
	static int movesLeft;
	static int score;
	static int highscore;

	// Options set by user
	static bool textOnlyFlag;
	static int seed;
	static std::string file;
	static std::string colourInput;
	static int colourInputIndex;
	static int startLevel;


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

	void readFile();
	
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
