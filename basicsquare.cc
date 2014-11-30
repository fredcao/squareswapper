#include "basicsquare.h"

using namespace std;

BasicSquare::BasicSquare(int row,int col,int colour, bool locked, Xwindow *xw) {
	
	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 0;
	this->locked = locked;
	this->xw = xw;
	draw();

}

BasicSquare::~BasicSquare(){
	colour = Black;
	draw();
}

void BasicSquare::draw() {

	if (xw) {
//	cout << "[BSquare] Xw: " << xw << endl;

		xw->drawRectangle(col * len, row * len, len, len, colour, locked, type);

	}

}
void BasicSquare::print() {

	if (locked) {

		cout << "l";

	}
	else {

		cout << "_";

	}

	cout << "_";
	cout << colour;

}

bool BasicSquare::notify() {

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

