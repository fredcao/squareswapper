
#include <iostream>
#include <fstream>

#include "boardinterpreter.h"

using namespace std;

int main() {


	BoardInterpreter *bi = new BoardInterpreter();

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
		else if (cmd == "info" || cmd == "debug") {

			// For debugging purposes

		}

		// Process options

		ss >> option;

		while (!ss.eof()) {

			if (option == "-text") {

				bi->setTextOnly(true);

			}
			else if (option == "-seed") {

				int seed;
				
				ss >> seed;
			
				bi->setSeed(seed);

			}
			else if (option == "-scriptfile") {

				string fileName;

				ss >> fileName;

				bi->setFile(fileName);

			}
			else if (option == "-startlevel") {

				int level;

				ss >> level;

				bi->setStartLevel(level);

			}

			ss >> option;

		}

		getline(cin, input);

	}


	return 0;

}
