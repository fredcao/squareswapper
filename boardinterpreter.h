#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

class BoardInterpreter : public Board {


	// Private stuff


	public:

	BoardInterpreter(bool textOnly, int seed, string file, int startLevel);
	~BoardInterpreter();

	void swap(int x, int y, int z);
	int *hint();
	void scramble();
	void levelUp();
	void levelDown();
	void restart();
	
	bool textOnly();

};

#endif
