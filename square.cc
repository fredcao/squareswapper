#include "square.h"
using namespace std;

Square::Square() : len(60) {}
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

void Square::setDisplay(TextDisplay *td) {
	
	this->td = td;

}
void Square::setWindow(Xwindow *xw) {

	this->xw = xw;

}

void Square::print() {

	if (locked) {

		cout << "l";

	}
	else {

		cout << "_";

	}

	cout << type;
	cout << colour;

}

	
bool Square::notify(){

	return false;

}
