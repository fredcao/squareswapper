#include "square.h"
using namespace std;

Square::Square(){}
Square::~Square(){}
int Square::getRow(){
	return row;
}
int Square::getCol(){
	return col;
}
int Square::getColour(){
        return colour;
}

int Square::getType(){
	return type;
}
bool Square::getLocked(){
	return locked;
}
void Square::notify(){}