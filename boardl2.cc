#include "boardl2.h"

using namespace std;

BoardL2::BoardL2() {

	board = new Square** [boardSize];

	for (int i = 0; i < boardSize; i++) {

		board[i] = new Square* [boardSize];

	}

	cout << "[Board Initialized: Level 2]" << endl;

	// Empty
	


}

BoardL2::~BoardL2() {

	cout << "BoardL2 destructor called" << endl;

	clearBoard();

	for (int i = 0; i < boardSize; i++) {

		delete [] board[i];

	}

	delete [] board;

}

void BoardL2::constructBoard() {

	clearBoard();

	if (startLevel == 2 && file.length() > 0) {

		readFile();

		// Only read once

		file = "";

		return;

	}

	int colour;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

			colour = getRand(0, 3);

			board[i][j] = new BasicSquare(i, j, colour, false, xw);

		}

	}

	int lockedCount = 0;

	while (lockedCount < 20) {

		int x = getRand(0, 9);
		int y = getRand(0, 9);

		if (!board[x][y]->getLocked()) {

			int colour = board[x][y]->getColour();

			delete board[x][y];
			
			board[x][y] = new BasicSquare(x, y, colour, true, xw);

			board[x][y]->setWindow(xw);

			lockedCount++;

		}

	}

}

Square *BoardL2::getSquare(int r, int c) {

	Square *temp;

	bool lock;

	int colour;

	lock = (getRand(1, 10) <= 2) ? true : false;

	if (file.length() > 0 && colourInput.length() > 0) {

		colour = colourInput.at(colourInputIndex) - '0';

		colourInputIndex++;

		if (colourInputIndex == static_cast<int>(colourInput.length())) {

			colourInputIndex = 0;

		}

	}
	else {

		colour = getRand(0, 3);

	}

	temp = new BasicSquare(r, c, colour, lock, xw);

	return temp;
	

}
