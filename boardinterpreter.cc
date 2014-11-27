#include <iostream>
#include <fstream>
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
#include "boardinterpreter.h"

using namespace std;

BoardInterpreter::BoardInterpreter() {




}

BoardInterpreter::~BoardInterpreter() {


}

void BoardInterpreter::remove(int r, int c) {

	cout << "Remove called" << endl;

	if (!board[r][c]->notify()) {
		board[r][c] = NULL;
	}

	//delete board[r][c];
}

void BoardInterpreter::dropFillTemp() {

	dropFill();

}

void BoardInterpreter::startGame() {

	delete instance;

	level = startLevel;

	cout << "Starting game at level ... " << level << endl;

	if (level == 0) {

		instance = new BoardL0();

	}
	else if (level == 1) {

		instance = new BoardL1();

	}
	else if (level == 2) {

		instance = new BoardL2();

	}
	else {

		instance = new BoardL0();

	}

	instance->constructBoard();

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

void BoardInterpreter::match3() {

// Find horizontal and vertical matches of 3
// Notify the squares that are part of the match
// Call doEffect(sq) for each square that are part of the match
	
	int curColour;
	for(int i=0;i < boardSize; i++){	//checking horizontal matches
		for(int j=0;j < boardSize-2; j++){
			if(!(board[i][j]&&board[i][j+1]&&board[i][j+2])){	//checking that not null
				continue;
			}
			curColour=board[i][j]->getColour();
			if(board[i][j+1]->getColour()==curColour && board[i][j+2]->getColour()==curColour){
				board[i][j]->notify();
				board[i][j+1]->notify();
				board[i][j+2]->notify();
				j+=3;
			}
		}
	}
	for(int j=0;j<boardSize;j++){		//checking vertical matches
		for(int i=0;i<boardSize-2;i++){
			if(!(board[i][j]&&board[i+1][j]&&board[i+2][j])){
				continue;
			}
			curColour=board[i][j]->getColour();
			if(board[i+1][j]->getColour()==curColour && board[i+2][j]->getColour()==curColour){
				board[i][j]->notify();
				board[i+1][j]->notify();
				board[i+2][j]->notify();
				i+=3;
			}
		}
	}
}

void BoardInterpreter::match4() {

// Same thing as match3 except with 4

}

void BoardInterpreter::match5() {

// Same thing as match4 except...
// Really this is match 5 or more as matching for example 10 gives you the same result

}

void BoardInterpreter::matchL() {

// Same thing as match5 except actually an L instead of line

}
