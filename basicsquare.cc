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
void BasicSquare::notify(){ }

