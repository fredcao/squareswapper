#include "uprightsquare.h"
using namespace std;

UprightSquare::UprightSquare(int row,int col,int colour=White,bool locked=false) {

	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 2;
	this->locked = locked;

}

UprightSquare::~UprightSquare(){}

void UprightSquare::draw() { }
void UprightSquare::notify() { }

