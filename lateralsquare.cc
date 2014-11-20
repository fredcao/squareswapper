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
void LateralSquare::notify(){ }

