#include "unstablesquare.h"
using namespace std;

UnstableSquare::UnstableSquare(int row,int col,int colour=White,bool locked=false) {

	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 3;
	this->locked = locked;

}

UnstableSquare::~UnstableSquare(){}

void UnstableSquare::draw() { }
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
		return true;

	}
	else {
		delete this;
		return false;
	
	}
	// Else do stuff and notify textdisplay and Xwindow


}


