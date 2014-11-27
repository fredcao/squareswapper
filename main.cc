
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "boardinterpreter.h"

using namespace std;

int main(int argc, char* argv[]) {

	BoardInterpreter *bi = new BoardInterpreter();

	for (int i = 1; i < argc; i++) {


		// Process options

		string arg = argv[i];


		if (arg == "-text") {

			bi->setTextOnly(true);

		}
		else if (arg == "-seed") {

			i++;

			bi->setSeed(atoi(argv[i]));

		}
		else if (arg == "-scriptfile") {

			i++;
			
			bi->setFile(argv[i]);

		}
		else if (arg == "-startlevel") {

			i++;
		
			bi->setStartLevel(atoi(argv[i]));

		}


	}

	bi->startGame();

	string input;

	getline(cin, input);

	string cmd;
	string option;

	while (!cin.eof()) {

		istringstream ss(input);

		ss >> cmd;

		if (cmd == "swap") {

			int x;
			int y;
			int z;

			ss >> x;
			ss >> y;
			ss >> z;

			bi->swap(x, y, z);

		}
//Testing for special math functions, remove later
		else if (cmd == "clearRow"){
			int row;
			ss >> row;
			bi->clearRow(row);
		}
		else if(cmd == "clearCol"){
			int col;
			ss >> col;
			bi->clearCol(col);
		}
		else if(cmd == "explode"){
			int x;
			int y;
			int width;
			ss >> x;
			ss >> y;
			ss >> width;
			bi->explode(x,y,width);
		}
		else if(cmd == "clearColour"){
			int colour;
			ss>>colour;
			bi->clearColour(colour);
		}
		else if(cmd == "match3"){
			bi->match3();
		}	
			
		else if (cmd == "hint") {

			int *result = bi->hint();

			if (result) {
			
				cout << "Hint: " << result[0] << " " << result[1] << " " << result[2] << " " << endl;

			}
			else {

				cout << "No possible moves";

			}

		}
		else if (cmd == "scramble") {

			if (bi->hint()) {

				cout << "There exists at least one possible move." << endl;

			}
			else {
	
				bi->scramble();

			}

		}
		else if (cmd == "levelup") {

			bi->levelUp();
	
		}
		else if (cmd == "leveldown") {

			bi->levelDown();
		
		}
		else if (cmd == "restart") {

			bi->restart();
		
		}
		else if (cmd == "print") {

			bi->printBoard();

		}
		else if (cmd == "remove") {

			// TEMPORARY TESTING THING NEED TO DELETE LATER

			int r;
			int c;

			ss >> r;
			ss >> c;

			bi->remove(r, c);	
	
		}
		else if (cmd == "dropfill") {


			bi->dropFillTemp();
			// TEMPORARY TESTING THING NEED TO DELETE LATER

		}
		else if (cmd == "info" || cmd == "debug") {

			// For debugging purposes

		}



		getline(cin, input);

	}

//	bi->endGame();
//	delete bi->getInstance();
//	Board::cleanup();
	delete bi;

	return 0;

}
