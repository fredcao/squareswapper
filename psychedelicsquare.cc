#include "psychedelicsquare.h"
using namespace std;

PsychedelicSquare::PsychedelicSquare(int row,int col,int colour=White,bool locked=false) {

	this->row = row;
	this->col = col;
	this->colour = colour;
	this->type = 4;
	this->locked = locked;

}

PsychedelicSquare::~PsychedelicSquare(){}

void PsychedelicSquare::draw() { }
void PsychedelicSquare::notify() { }

