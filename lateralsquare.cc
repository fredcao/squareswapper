#include "lateralsquare.h"
using namespace std;

LateralSquare::LateralSquare(int row,int col,int colour=White,bool locked=false) {

	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 1;
	this->locked = locked;
}

LateralSquare::~LateralSquare(){}

void LateralSquare::draw() { }
void LateralSquare::print() {

	if (locked) {

		cout << "l";

	}
	else {

		cout << "_";

	}

	cout << "h";
	cout << colour;

}
bool LateralSquare::notify(){

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



