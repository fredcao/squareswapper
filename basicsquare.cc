#include "basicsquare.h"

using namespace std;

BasicSquare::BasicSquare(int row,int col,int colour=White,bool locked=false) {
	
	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 0;
	this->locked = locked;

}

BasicSquare::~BasicSquare(){}

void BasicSquare::draw() { }
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

		return true;

	}
	else {

		delete this;
		return false;

	}
	
	

	// Else do stuff and notify textdisplay and Xwindow

}

