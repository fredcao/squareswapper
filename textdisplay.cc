#include <iostream>

#include "square.h"
#include "textdisplay.h"

using namespace std;

// TextDisplay Constructor [1 argument]
// Creates a TextDisplay object with grid size of n

TextDisplay::TextDisplay(int n) : gridSize(n) {

	theDisplay = new char **[gridSize];	// Create a new array of char** on the heap

	// For loop to loop through each element in theDisplay

	for (int i = 0; i < gridSize; i++) {

		theDisplay[i] = new char*[gridSize];	// Creates a new array of char on the heap

		// For each char in theDisplay[i], create a new char array of length 3, with default char '_'

		for (int j = 0; j < gridSize; j++) {

			theDisplay[i][j] = new char[3];

			theDisplay[i][j][0] = '_';
			theDisplay[i][j][1] = '_';
			theDisplay[i][j][2] = '_';

		}

		// End for loop

	}

	// End for loop

	// For each of the squares, initialize the count to 0

	for (int i = 0; i < 5; i++) {

		colourCount[i] = 0;

	}

	// End for loop

}

// TextDisplay Destructor

TextDisplay::~TextDisplay() {

	// For each char[] in theDisplay array

	for (int i = 0; i < gridSize; i++) {

		delete [] theDisplay[i];

	}

	// End for

	delete [] theDisplay;	// Delete theDisplay array

}

// TextDisplay::notify(int r, int c, Square &sq)
// Given r, c, sq, updates theDisplay at coordinates (r, c) to a 3 char
// representation of sq, and updates the squareCounts

void TextDisplay::notify(int oldType, Square &sq) {
	
	int r = sq.getRow();
	int c = sq.getCol();
	int type = sq.getType();

	squareCount[oldType] --;

	theDisplay[r][c][0] = sq->locked() ? 'l' : '_';
	
	if (type == sq.BasicSquare) {
	
		theDisplay[r][c][1] = '_';

	}
	else if (type == sq.LateralSquare) {
	
		theDisplay[r][c][1] = 'h';

	}
	else if (type == sq.UprightSquare) {

		theDisplay[r][c][1] = 'v';

	}
	else if (type == sq.UnstableSquare) {

		theDisplay[r][c][1] = 'b';

	}
	else if (type == sq.PsychedelicSquare) {

		theDisplay[r][c][1] = 'p';

	}

	theDisplay[r][c][2] = sq.getColor() + '0';

	squareCount[type]++;	

}

// operator<<(ostream &out, const TextDisplay &td)
// Given out, td, prints out the grid

ostream &operator<<(ostream &out, const TextDisplay &td) {

	// For each row in td

	for (int i = 0; i < td.gridSize; i++) {

		// For each column in the ith row of td

		for (int j = 0; j < td.gridSize; j++) {

			cout << td.theDisplay[i][j][0] << td.theDisplay[i][j][1] << td.theDisplay[i][j][2] << " ";

		}

		// End for loop

		cout << endl;

	}

	// End for loop

	return out;

}
