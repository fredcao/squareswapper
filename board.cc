
#include <cstdlib>
#include "board.h"

using namespace std;

Board *Board::instance = NULL;	// Set initial value for static instance in Board

Board::Board() : boardSize(10), level(0), movesLeft(-1), score(0), highscore(0), td(NULL), xw(NULL) { }

Board::~Board() {

	for (int i = 0; i < boardSize; i++) {

	//	for (int j = 0; j < boardSize; j++) {

	//		delete board[i][j];

	//	}

		delete [] board[i];

	}

	delete [] board;

}

void Board::constructBoard() { }

void Board::clearBoard() {

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {
	
			delete board[i][j];

		}

	}

}

Board *Board::getInstance() {

	// If an instance doesn't exist yet, create one and call cleanup at exit	

	if (!instance) {

		instance = new Board();
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

void Board::printBoard() {
	
	cout << "Board print: " << endl;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

			cout << board[i][j]->getLocked() << board[i][j]->getType() << board[i][j]->getColour() << " " << endl;

		}

		cout << endl;

	}
	cout << "TD print: " << endl;
	cout << td;

}

void Board::cleanup() {

	delete instance;

}
