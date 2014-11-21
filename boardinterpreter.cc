#include <iostream>
#include <fstream>
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
#include "boardinterpreter.h"

using namespace std;

BoardInterpreter::BoardInterpreter() : textOnlyFlag(false), startLevel(0) {





}

BoardInterpreter::~BoardInterpreter() {


}


void BoardInterpreter::swap(int x, int y, int z) {


}

int *BoardInterpreter::hint() {

	return new int[0];

}

void BoardInterpreter::scramble() {


}

void BoardInterpreter::levelUp() {




}

void BoardInterpreter::levelDown() {



}


void BoardInterpreter::restart() {



}

void BoardInterpreter::setTextOnly(bool textOnly) {

	this->textOnlyFlag = textOnly;

}

void BoardInterpreter::setSeed(int seed) {

	this->seed = seed;

}

void BoardInterpreter::setFile(string file) {

	this->file = file;

	ifstream fs(file.c_str());

	string input;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

		fs >> input;

		bool locked = (input.at(0) == 'l') ? true : false;
		char type = input.at(1);
		int colour = input.at(2) - '0';


		if(type == '_'){
			board[i][j] = new BasicSquare(i,j,colour,locked);
		}
		else if(type == 'h'){
			board[i][j] = new LateralSquare(i,j,colour,locked);
		}
		else if(type == 'v'){
			board[i][j] = new UprightSquare(i,j,colour,locked);
		}
		else if(type == 'b'){
			board[i][j] = new UnstableSquare(i,j,colour,locked);
		}
		else if(type == 'p'){
			board[i][j] = new PsychedelicSquare(i,j,colour,locked);
		}


		//Ignore this for now
		//board[i][j]->notifyTD();
		//board[i][j]->draw();
				
		
		

		}

	}

}

void BoardInterpreter::setStartLevel(int startLevel) {

	this->startLevel = startLevel;

}


bool BoardInterpreter::textOnly() {

	return textOnlyFlag;

}
