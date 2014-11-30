#include "boardl1.h"

using namespace std;

BoardL1::BoardL1() : count5(1) {

	cout << "Ctor" << endl;

	board = new Square** [boardSize];

	for (int i = 0; i < boardSize; i++) {

		board[i] = new Square* [boardSize];

	}

	cout << "[Board Initialized: Level 1]" << endl;

}

BoardL1::~BoardL1() {

	cout << "BoardL1 destructor called" << endl;

	clearBoard();

	for (int i = 0; i < boardSize; i++) {

		delete [] board[i];

	}

	delete [] board;

}

void BoardL1::constructBoard() {

	clearBoard();

	if (startLevel == 1 && file.length() > 0) {

		cout << "Read file" << endl;

		readFile();

		cout << "File read" << endl;

		return;

	}

	cout << "Before generation" << endl;

	int num;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

			num = getRand(1, 12);

			if (num <= 4) {

				board[i][j] = new BasicSquare(i, j, Square::White, false, xw);

			}
			else if (num <= 8) {

				board[i][j] = new BasicSquare(i, j, Square::Red, false, xw);

			}
			else if (num <= 10) {

				board[i][j] = new BasicSquare(i, j, Square::Green, false, xw);

			}
			else {

				board[i][j] = new BasicSquare(i, j, Square::Blue, false, xw);

			}

			board[i][j]->setWindow(xw);

		}

	}

	cout << "After generation" << endl;

	// Pick 20 squares to make special

	int countSpecial = 0;

	while (countSpecial < 10) {

		int x = getRand(0, 9);
		int y = getRand(0, 9);

		if (board[x][y]->getType() == Square::BasicSquare) {

			int colour = board[x][y]->getColour();

			num = getRand(1, 4);
			
			delete board[x][y];

			switch (num) {


				case 1:

					board[x][y] = new LateralSquare(x, y, colour, false, xw);
					break;

				case 2:

					board[x][y] = new UprightSquare(x, y, colour, false, xw);
					break;
				case 3:

					board[x][y] = new UnstableSquare(x, y, colour, false, xw);
					break;

				case 4:

					board[x][y] = new PsychedelicSquare(x, y, colour, false, xw);
					break;

				default:

					break;

			}

			countSpecial++;

		}

	

	}

	cout << "After making special squares." << endl;

	// Temporary implementation

}

Square *BoardL1::getSquare(int r, int c) {



	Square *temp;

	int num;
	int colour;

	num = getRand(1, 12);

	if (colourInput.length() > 0) {

		colour = colourInput.at(colourInputIndex) - '0';

		colourInputIndex++;

		if (colourInputIndex == static_cast<int>(colourInput.length())) {

			colourInputIndex = 0;

		}

	}
	else if (num <= 4) {

		colour = Square::White;

	}
	else if (num <= 8) {

		colour = Square::Red;

	}
	else if (num <= 10) {

		colour = Square::Green;
	
	}
	else {

		colour = Square::Blue;

	}


	if (count5 == 5) {

		num = getRand(1, 4);

		switch (num) {

			case 1:

				temp = new LateralSquare(r, c, colour, false, xw);
				break;

			case 2:

				temp = new UprightSquare(r, c, colour, false, xw);
				break;

			case 3:

				temp = new UnstableSquare(r, c, colour, false, xw);
				break;

			case 4:

				temp = new PsychedelicSquare(r, c, colour, false, xw);
				break;

			default:

				break;

		}

		count5 = 1;

	}
	else {

		temp = new BasicSquare(r, c, colour, false, xw);

		count5++;
				
	}

	return temp;

}
