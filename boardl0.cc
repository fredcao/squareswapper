#include <fstream>
#include "boardl0.h"

using namespace std;

BoardL0::BoardL0() {

	board = new Square** [boardSize];

	for (int i = 0; i < boardSize; i++) {

		board[i] = new Square* [boardSize];

	}

	cout << "[Board Initialized: Level 0]" << endl;	


}

BoardL0::~BoardL0() {

	cout << "BoardL0 constructor called" << endl;

	clearBoard();

	for (int i = 0; i < boardSize; i++) {

	//	for (int j = 0; j < boardSize; j++) {

	//		delete board[i][j];

	//	}

		delete [] board[i];

	}

	delete [] board;
	//delete td;
	//delete xw;
}

void BoardL0::constructBoard() {

	ifstream fs("sequence.txt");

	string input;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

		fs >> input;

		bool locked = (input.at(0) == 'l') ? true : false;
		char type = input.at(1);
		int colour = input.at(2) - '0';

		// cout << locked << type << colour << "     ";


		if(type == '_'){
		//	cout << "BS ";
			board[i][j] = new BasicSquare(i,j,colour,locked);
		}
		else if(type == 'h'){

		//	cout << "LS";
			board[i][j] = new LateralSquare(i,j,colour,locked);
		}
		else if(type == 'v'){
		//	cout << "US";
			board[i][j] = new UprightSquare(i,j,colour,locked);
		}
		else if(type == 'b'){

		//	cout << "SS";
			board[i][j] = new UnstableSquare(i,j,colour,locked);
		}
		else if(type == 'p'){

		//	cout << "PS";
			board[i][j] = new PsychedelicSquare(i,j,colour,locked);
		}


		//Ignore this for now
		//board[i][j]->notifyTD();
		//board[i][j]->draw();
		

		}

		// cout << endl;

	}

	fs >> colourInput;	// Get list of colours
	colourInputIndex = 0;


}

Square *BoardL0::getSquare(int r, int c) {

	int colour = colourInput.at(colourInputIndex) - '0';

	Square *temp;

	temp = new BasicSquare(r, c, colour, false);

	colourInputIndex++;

	if (colourInputIndex == static_cast<int>(colourInput.length())) {

		colourInputIndex = 0;

	}

	return temp; 

}
