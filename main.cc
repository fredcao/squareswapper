
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

	if (!bi->textOnly()) {

		Xwindow *xw = new Xwindow(1000, 600);

		bi->setWindow(xw);

	}

	bi->startGame();

	cout << "Level: \t" << bi->getLevel() << endl;
	cout << "Score: \t" << bi->getScore() << endl;
	cout << "Moves Remaining: Infinite" << endl;
	cout << "Hi Score: " << bi->getHighScore() << endl;
	cout << "--------------------" << endl;
	bi->printBoard();
//	bi->swap(0, 0, -1);

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
			
				cout << "[HINT]: " << result[0] << " " << result[1] << " " << result[2] << " " << endl;

			}
			else {

				cout << "There are no possible moves, please scramble.";

			}

			delete [] result;

		}
		else if (cmd == "scramble") {


			int *result = bi->hint();

			if (result) {

				cout << "There exists at least one possible move." << endl;

			}
			else {
	
				bi->scramble();

			}

			delete result;

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

		cout << "Level: \t" << bi->getLevel() << endl;
		cout << "Score: \t" << bi->getScore() << endl;
		cout << "Moves Remaining: Infinite" << endl;
		cout << "Hi Score: " << bi->getHighScore() << endl;
		cout << "--------------------" << endl;
		bi->printBoard();



		getline(cin, input);

	}

	delete bi;

	return 0;

}
