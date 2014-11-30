#include "uprightsquare.h"
using namespace std;

UprightSquare::UprightSquare(int row, int col, int colour, bool locked, Xwindow *xw) {

	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 2;
	this->locked = locked;
	this->xw = xw;
	draw();

}

UprightSquare::~UprightSquare(){}

void UprightSquare::draw() {

	if (xw) {

		xw->drawRectangle(col * len, row * len, len, len, colour, locked, type);
	}

}
void UprightSquare::print() {

	if (locked) {

		cout << "l";

	}
	else {

		cout << "_";

	}

	cout << "v";
	cout << colour;

}
bool UprightSquare::notify() {

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

