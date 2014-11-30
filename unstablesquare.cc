#include "unstablesquare.h"
using namespace std;

UnstableSquare::UnstableSquare(int row,int col,int colour,bool locked, Xwindow *xw) {

	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 3;
	this->locked = locked;

}

UnstableSquare::~UnstableSquare(){}

void UnstableSquare::draw() {


	xw->drawRectangle(row, col, len, len, colour, locked, type);

}
void UnstableSquare::print() {

	if (locked) {

		cout << "l";

	}
	else {

		cout << "_";

	}

	cout << "b";
	cout << colour;

}
bool UnstableSquare::notify() {

	if (locked) {

		locked = false;
		draw();
		return true;

	}
	else {

		colour = Black;
		draw();

		delete this;
		return false;
	
	}
	// Else do stuff and notify textdisplay and Xwindow


}


