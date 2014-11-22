#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "board.h"

class BoardInterpreter : public Board {


	// Private stuff

	bool textOnlyFlag;
	int seed;
	std::string file;
	int startLevel;

	void match3();
	void match4();
	void match5();
	void matchL();

	public:

	BoardInterpreter();
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
	void setFile(std::string file);
	void setStartLevel(int startLevel);
	
	bool textOnly();

	// Temporary functions need to delete after
	void remove(int r, int c);

	void dropFillTemp();
};

#endif
