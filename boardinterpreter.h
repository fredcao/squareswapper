#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "board.h"
#include "boardl0.h"
#include "boardl1.h"
#include "boardl2.h"

class BoardInterpreter : public Board {


	// Private stuff
	public: // TEmp
	void match3();
	void match4();
	void match5();
	void matchL();

	public:

	BoardInterpreter();
	~BoardInterpreter();

	void startGame();

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
