#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "board.h"

class BoardInterpreter : public Board {


	// Private stuff

	bool textOnly;
	int seed;
	string file;
	int startLevel;

	public:

	BoardInterpreter(bool textOnly, int seed, string file, int startLevel);
	~BoardInterpreter();

	void swap(int x, int y, int z);
	int *hint();
	void scramble();
	void levelUp();
	void levelDown();
	void restart();

	// Setting options

	void setTextOnly(bool textOnly);
	void setSeed(int seed);
	void setFile(string file);
	void setStartLevel(int startLevel);
	
	bool textOnly();

};

#endif
