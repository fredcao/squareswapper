#include <fstream>
#include <cstdlib>

#include "board.h"

using namespace std;

Board *Board::instance = NULL;	// Set initial value for static instance in Board
Square ***Board::board = NULL;
int Board::boardSize = 10;
int Board::level = 0;
int Board::movesLeft = -1;
int Board::score = 0;
int Board::levelScore = 0;
int Board::highscore = 0;
bool Board::textOnlyFlag = false;
int Board::seed = -1;
bool Board::seeded = false;
string Board::file = "";
string Board::colourInput = "";
int Board::colourInputIndex = 0;
int Board::startLevel = 0;
Xwindow *Board::xw = NULL;

Board::Board() : td(NULL) { 

}

Board::~Board() {


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

}

void Board::readFile() {


	ifstream fs(file.c_str());

	string input;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

		fs >> input;

		bool locked = (input.at(0) == 'l') ? true : false;
		char type = input.at(1);
		int colour = input.at(2) - '0';

		if(type == '_'){
			board[i][j] = new BasicSquare(i,j,colour,locked, xw);
		}
		else if(type == 'h'){
			board[i][j] = new LateralSquare(i,j,colour,locked, xw);
		}
		else if(type == 'v'){
			board[i][j] = new UprightSquare(i,j,colour,locked, xw);
		}
		else if(type == 'b'){
			board[i][j] = new UnstableSquare(i,j,colour,locked, xw);
		}
		else if(type == 'p'){
			board[i][j] = new PsychedelicSquare(i,j,colour,locked, xw);
		}

		}


	}

	fs >> colourInput;

	if (fs.eof()) {

		fs.clear();

	}

}

int Board::getRand(int x, int y) {

	if (!seeded) {

		if (seed == -1) {

			srand(time(NULL));

		}
		else {

			srand(seed);

		}

		seeded = true;

	}

	return x + rand() % (y - x + 1);


}

Square *Board::makeSquare(int r, int c, int type, int colour, bool locked) {

	Square *temp;

	if (type == Square::BasicSquare) {

		temp = new BasicSquare(r, c, colour, locked, xw);

	}
	else if (type == Square::LateralSquare) {

		temp = new LateralSquare(r, c, colour, locked, xw);

	}
	else if (type == Square::UprightSquare) {

		temp = new UprightSquare(r, c, colour, locked, xw);

	}
	else if (type == Square::UnstableSquare) {

		temp = new UnstableSquare(r, c, colour, locked, xw);

	}
	else if (type == Square::PsychedelicSquare) {

		temp = new PsychedelicSquare(r, c, colour, locked, xw);

	}


	return temp;

}

Square *Board::getSquare(int r, int c) {

	return instance->getSquare(r, c);
	
}

Board *Board::getInstance() {

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

int Board::getScoreNeeded() {
	return instance->getScoreNeeded();

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
	

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {


			if (board[i][j]) {

				board[i][j]->print();

				cout << " ";

			}
			else {

				cout << "    ";

			}

		}

		cout << endl;

	}

}

void Board::cleanup() {

	delete instance;
	instance = NULL;


}

// [ PROTECTED AND PRIVATE METHODS ]


int Board::clearRow(int row) {

	int sqCount = 0;

	for (int j = 0; j < boardSize; j++) {
	
		if (board[row][j]) {

			if (board[row][j]->getType() != Square::LateralSquare) {

				sqCount += doEffect(board[row][j], 3);

			}
			else {

				sqCount++;

				if (!board[row][j]->notify()) {

					board[row][j] = NULL;

				}
			}

		}

	}
			

	return sqCount;

}

int Board::clearCol(int col) {

	int sqCount = 0;

	for (int i = 0; i < boardSize; i++) {

		if (board[i][col]) {
	
			if (board[i][col]->getType() != Square::UprightSquare) {
	
				sqCount += doEffect(board[i][col], 3);
	
			}
			else {

				sqCount++;

				if (!board[i][col]->notify()) {

					board[i][col] = NULL;

				}

			}

		}

	}

	return sqCount;

}

int Board::explode(int centerX, int centerY, int width) {

	int sqCount = 0;

	int r = width / 2;

	for (int i = max(0, centerX-r); i < min(boardSize, centerX+r+1); i++) {

		for (int j = max(0, centerY-r); j < min(boardSize, centerY+r+1); j++) {

			if (board[i][j]) {

				if (i == centerX && j == centerY) {

					sqCount++;

					if (!board[i][j]->notify()) {

						board[i][j]=NULL;

					}
				}
				else {

					sqCount += doEffect(board[i][j], 3);

				}

			}

		}

	}

	return sqCount;
}

int Board::clearColour(int colour) {

	int sqCount = 0;		

	for (int i = 0; i < boardSize; i++){

		for (int j = 0; j < boardSize; j++) {

			if (board[i][j] && board[i][j]->getColour() == colour) {

				if (board[i][j]->getType() != Square::PsychedelicSquare) {

					sqCount += doEffect(board[i][j], 3);

				}
				else{

					sqCount++;

					if (!board[i][j]->notify()) {

						board[i][j] = NULL;

					}

				}
				

			}

		}

	}

	return sqCount;
}

int Board::doEffect(Square *sq, int width = 3) {

	if (sq->getLocked()) {

		sq->notify();

		return 1;
	}

	int row = sq->getRow();
	int col = sq->getCol();
	int type = sq->getType();

	switch (type) {


		case Square::BasicSquare:		

			if (!sq->notify()) {

				board[row][col] = NULL;

			}

			return 1;
			// Do nothing
			break;

		case Square::LateralSquare:

			return clearRow(sq->getRow());
			// clearRow
			break;

		case Square::UprightSquare:
			
			return clearCol(sq->getCol());
			//clearCol
			break;

		case Square::UnstableSquare:

			return explode(sq->getRow(), sq->getCol(), width);
			//explode
			break;

		case Square::PsychedelicSquare:

			return clearColour(sq->getColour());

			// clearColour

			break;

		default:

			break;

	}

	return 0;

}

int Board::dropSquare(int currentRow, int col) {

	currentRow--;

	while ((currentRow >= 0) && (board[currentRow][col] == NULL)) {

		currentRow--;

	}

	return currentRow;

}

void Board::dropFill() {

	bool prevLocked = false;

	for (int j = 0; j < boardSize; j++) {

		for (int i = boardSize - 1; i >= 0; i--) {

			if (board[i][j] == NULL) {

				int nextSq = dropSquare(i, j);

				if (nextSq >= 0) {

					delete board[i][j];

					int type = board[nextSq][j]->getType();
					int colour = board[nextSq][j]->getColour();
					int locked = prevLocked;
					prevLocked = board[nextSq][j]->getLocked();
				
					delete board[nextSq][j];
					
					board[i][j] = makeSquare(i, j, type, colour, locked);
					board[nextSq][j] = NULL;

				}
				else {

					board[i][j] = getSquare(i, j);

				}

			}

		}

	}
			

}

int Board::countLocked() {

	int count = 0;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

			if (board[i][j] && board[i][j]->getLocked()) {
	
				count++;

			}

		}

	}

	return count;

}

void Board::draw() {

 	if (xw) {

		xw->drawString(700, 50, level, score, highscore, movesLeft);


	}
}
