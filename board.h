#ifndef __BOARD_H__
#define __BOARD_H__

class Board {

	// Private stuff


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
	
	enum { BasicSquare = 0; LateralSquare; UprightSquare; UnstableSquare; PsychedelicSquare }




};



#endif
