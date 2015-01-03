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
	static int levelScore;
	static int highscore;


	// Options set by user
	static bool textOnlyFlag;
	static int seed;
	static bool seeded;
	static std::string file;
	static std::string colourInput;
	static int colourInputIndex;
	static int startLevel;


	Square **stack;

	TextDisplay *td;
	static Xwindow *xw;

	int clearRow(int row);
	int clearCol(int col);
	int explode(int centerX, int centerY, int width);
	int clearColour(int colour);
	

	void readFile();
	int getRand(int x, int y);
	Square *makeSquare(int r, int c, int type, int colour, bool locked);
	virtual Square *getSquare(int r, int c);
	int doEffect(Square *sq, int width);
	int dropSquare(int currentRow, int col);
	void dropFill();
	int countLocked();
	void clearBoard();
	void draw();

	public:

	Board();
	virtual ~Board();
	virtual void constructBoard();
	static Board *getInstance();
	int getLevel();
	int getMovesLeft();
	int getScore();
	virtual int getScoreNeeded();
	int getHighScore();
	void setDisplay(TextDisplay *td);
	void setWindow(Xwindow *xw);
		
	void printBoard();
	static void cleanup();	
	


};



#endif
