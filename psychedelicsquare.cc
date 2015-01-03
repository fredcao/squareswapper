#include "psychedelicsquare.h"
using namespace std;

PsychedelicSquare::PsychedelicSquare(int row,int col, int colour, bool locked, Xwindow *xw) {

	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 4;
	this->locked = locked;
	this->xw = xw;
	draw();

}

PsychedelicSquare::~PsychedelicSquare(){

	colour = Black;

	draw();

}

void PsychedelicSquare::draw() {

	if (xw) {
		xw->drawRectangle(col * len, row * len, len, len, colour, locked, type);

	}

}

void PsychedelicSquare::print() {

	if (locked) {

		cout << "l";

	}
	else {

		cout << "_";

	}

	cout << "p";
	cout << colour;

}

bool PsychedelicSquare::notify() {

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

}

