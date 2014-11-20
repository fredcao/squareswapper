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
void UnstableSquare::notify() { }

