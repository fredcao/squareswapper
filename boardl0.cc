#include <fstream>
#include "boardl0.h"

using namespace std;

BoardL0::BoardL0() : scoreNeeded(200)  {

	board = new Square** [boardSize];

	for (int i = 0; i < boardSize; i++) {

		board[i] = new Square* [boardSize];


	}

}

BoardL0::~BoardL0() {

	clearBoard();

	for (int i = 0; i < boardSize; i++) {

		delete [] board[i];

	}

	delete [] board;

}

void BoardL0::constructBoard() {


	if (startLevel == 0 && file.length() > 0) {

		readFile();
		return;

	}

	ifstream fs("sequence.txt");

	string input;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

			fs >> input;

			bool locked = (input.at(0) == 'l') ? true : false;
			char type = input.at(1);
			int colour = input.at(2) - '0';


			if (type == '_') {

				board[i][j] = new BasicSquare(i, j, colour, locked, xw);

			}
			else if (type == 'h') {
	
				board[i][j] = new LateralSquare(i, j, colour, locked, xw);

			}
			else if (type == 'v') {

				board[i][j] = new UprightSquare(i, j, colour, locked, xw);

			}
			else if (type == 'b') {
	
				board[i][j] = new UnstableSquare(i, j, colour, locked, xw);
	
			}
			else if (type == 'p') {
	
				board[i][j] = new PsychedelicSquare(i, j, colour, locked, xw);

			}
			
		}

	}

	fs >> colourInput;	// Get list of colours
	colourInputIndex = 0;


}

Square *BoardL0::getSquare(int r, int c) {

	int colour = colourInput.at(colourInputIndex) - '0';

	Square *temp;

	temp = new BasicSquare(r, c, colour, false, xw);

	colourInputIndex++;

	if (colourInputIndex == static_cast<int>(colourInput.length())) {

		colourInputIndex = 0;

	}

	return temp; 

}

int BoardL0::getScoreNeeded() {

	return scoreNeeded;

}
