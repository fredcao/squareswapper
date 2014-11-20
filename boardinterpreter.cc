// TODO: Include all the special square header files

#include "boardinterpreter.h"

using namespace std;

BoardInterpreter::BoardInterpreter() : textOnly(false), startLevel(0) {





}

BoardInterpreter::~BoardInterpreter() {


}


void BoardInterpreter::swap(int x, int y, int z) {


}

int *BoardInterpreter::hint() {


}

void BoardInterpreter::scramble() {


}

void BoardInterpreter::levelUp() {




}

void BoardInterpreter::levelDown() {



}


void BoardInterpreter::restart() {



}

void setTextOnly(bool textOnly) {

	this->textOnly = textOnly;

}

void setSeed(int seed) {

	this->seed = seed;

}

void setFile(string file) {

	this->file = file;

	ifstream fs(file);

	string input;

	for (int i = 0; i < boardSize; i++) {

		for (int j = 0; j < boardSize; j++) {

		fs >> input;

		bool locked = (s.at(0) == 'l') ? true : false;
		char type = s.at(1);
		int color = s.at(2) - '0';


		// input will be of the three char format

		// E.g. lv3

		/*

			Create new Square on the heap depending on the type (use if statement) 
			You need parameters:

			1) Row (i)
			2) Column (j)
			3) Colour
			4) Locked

		*/

		// Format: board[i][j] = new _____Square(...);

		//Ignore this for now
		//board[i][j]->notifyTD();
		//board[i][j]->draw();
				
		
		

		}

	}

}

void setStartLevel(int startLevel) {

	this->startLevel = startLevel;

}


bool BoardInterpreter::textOnly() {

	return textOnly;

}
