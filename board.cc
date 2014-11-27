
#include <cstdlib>
#include "board.h"

using namespace std;

Board *Board::instance = NULL;	// Set initial value for static instance in Board
Square ***Board::board = NULL;
//int Board::level = 0;
//int Board::movesLeft = -1;
//int Board::highscore = 0;

Board::Board() : boardSize(10), level(0), movesLeft(-1), score(0), highscore(0),
	textOnlyFlag(false), startLevel(0), td(NULL), xw(NULL) { 

	/*

	board = new Square**[boardSize];

	
	for (int i = 0; i < boardSize; i++) {

		board[i] = new Square *[boardSize];

		for (int j = 0; j < boardSize; j++) {

			//board[i][j] = new BasicSquare();
	
		}

	
	}

	cout << "[Board Initialized]" << endl;

	*/

}

Board::~Board() {

	clearBoard();

	for (int i = 0; i < boardSize; i++) {

	//	for (int j = 0; j < boardSize; j++) {

	//		delete board[i][j];

	//	}

		delete [] board[i];

	}

	delete [] board;
	delete td;
	delete xw;

}

// [ PUBLIC METHODS ]

void Board::clearBoard() {

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {
	
			delete board[i][j];

		}

	}

}

void Board::constructBoard() {
/*	for (int i = 0; i < boardSize; i++) {

		board[i] = new Square *[boardSize];

		for (int j = 0; j < boardSize; j++) {

			//board[i][j] = new BasicSquare();
	
		}

	}*/

}

Square *Board::getSquare(int r, int c) {

	return instance->getSquare(r, c);
	
}

Board *Board::getInstance() {

	// If an instance doesn't exist yet, create one and call cleanup at exit	

	if (!instance) {

		instance = new Board();
/*
		if (level == 0) {

			instance = new BoardL0();

		}
		else if (level == 1) {
		
			instance = new BoardL1();
		
		}
		else if (level == 2) {

			instance = new BoardL2();

		}
		else {

			instance = new Board();

		}*/

		atexit(cleanup);

	}

	// End if

	return instance;	// Returns instance, a pointer to the instance of the ScoreBoard

}

int Board::getLevel() {

	return level;

}

int Board::getMovesLeft() {

	return movesLeft;

}

int Board::getScore() {

	return score;

}

int Board::getHighScore() {

	return highscore;

}

void Board::setDisplay(TextDisplay *td) {
	
	this->td = td;

}
void Board::setWindow(Xwindow *xw) {

	this->xw = xw;

}

void Board::printBoard() {
	
	cout << "Board print: " << endl;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {


			if (board[i][j]) {

				board[i][j]->print();

				cout << " ";

			}
			else {

				cout << "    ";

			}
/*

			if (board[i][j]->getLocked()) {

				cout << "l" << endl;
	
			}
			else {

				cout << "_" << endl;

			}

			cout << board[i][j

*/			//board[i][j]->getType() << board[i][j]->getColour() << " ";

		}

		cout << endl;

	}
	cout << "TD print: " << endl;
//	cout << td;

}

void Board::cleanup() {

	delete instance;

}

// [ PROTECTED AND PRIVATE METHODS ]


void Board::clearRow(int row) {

	// Remember board is 2D array of Square *
	// I.e. board[i][j] is a Square *

	// For clearRow, you're given the row number
	// You must call notify on each Square in board[i][j] if the pointer is not NULL
	// IMPORTANT: WHEN USING A LOOP, PLEASE CHECK THAT THE POINTER IS NOT NULL

	// Err it seems like I did this for you already :P

	for (int j = 0; j < boardSize; j++) {
	
		if (board[row][j]) {

			if(!board[row][j]->notify()){
				board[row][j]=NULL;
			}

		}

	}
			

}

// TODO [KCXUE]: Implement clearCol

void Board::clearCol(int col) {

	// Same idea as clearRow, except for columns
	for(int i = 0; i < boardSize; i++) {

		if(board[i][col]) {

			if(!board[i][col]->notify()){
				board[i][col]=NULL;
			}

		}

	}

}



void Board::explode(int centerX, int centerY, int width) {


	// This one is a bit more complicated
	// You're given centerX and centerY, and width
	// You must notify all the squares in a width x width square with center (centerX, centerY)
	// For example, if centerX = 3, cetnerY = 3, width = 3
	// Then you'd have to notify (if the pointer is not null)
	// board[2][2], board[2][3], board[2][4]
	// board[3][2], board[3][3], board[3][4]
	// board[4][2], board[4][3], board[4][4]

	// This one is more tedious since you have to ensure that you don't go out of bounds
	// I.e. consider when centerX or centerY is 0 or boardSize (edges and corners of the board)
	int r = width/2;
	for(int i = max(0,centerX-r); i < min(boardSize, centerX+r+1);i++){
		for(int j = max(0,centerY-r); j < min(boardSize, centerY+r+1);j++){
			if(board[i][j]){
				if(!board[i][j]->notify()){
					board[i][j]=NULL;
				}
			}
		}
	}
}

void Board::clearColour(int colour) {

	// Given a colour, search through the whole board array and notify all Squares of colour
	// Of course, must check that the pointer isn't null before checking the colour
		
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize;j++){
			if(board[i][j] && board[i][j]->getColour()==colour){
				if(!board[i][j]->notify()){
					board[i][j]=NULL;
				}
			}
		}
	}
}

void Board::doEffect(Square *sq, int width = 3) {

	int type = sq->getType();

	switch (type) {


		case Square::BasicSquare:

			sq->notify();
			// Do nothing
			break;

		case Square::LateralSquare:

			clearRow(sq->getRow());
			// clearRow
			break;

		case Square::UprightSquare:
			
			clearCol(sq->getCol());
			//clearCol
			break;

		case Square::UnstableSquare:

			explode(sq->getRow(), sq->getCol(), width);
			//explode
			break;

		case Square::PsychedelicSquare:

			clearColour(sq->getColour());

			// clearColour

			break;

		default:

			break;

	}


}

int Board::dropSquare(int currentRow, int col) {

	currentRow--;

	while ((currentRow >= 0) && (board[currentRow][col] == NULL)) {

		currentRow--;

	}

	return currentRow;

}

void Board::dropFill() {

	for (int j = 0; j < boardSize; j++) {

		for (int i = boardSize - 1; i >= 0; i--) {

			if (board[i][j] == NULL) {

				int nextSq = dropSquare(i, j);

				if (nextSq >= 0) {

					board[i][j] = board[nextSq][j];
					board[nextSq][j] = NULL;

				}
				else {

					board[i][j] = getSquare(i, j);
					// Fill with new random square
					// TODO: implement this

				}

			}

		}

	}
			

}




