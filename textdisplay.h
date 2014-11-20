#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <iostream>
#include <sstream>
#include "square.h"


class TextDisplay {
	
	char ***theDisplay;	// The n x n display
	const int gridSize; 	// size of the grid (n)

	/*
	 * The following field helps track how the game as progressed
	 * The field should track how much Squares of the grid are of each color
	 * Whenever a Square changes type, the corresponding square count should
	 * be updated.
	 */
	int squareCount[5];

	public:

	TextDisplay(int n);	// One arg constructor where the parameter is the gridSize
	~TextDisplay();		// Destructor

	/*
   	 * The TextDisplay is an observer of each Square. Squares call notify to 
   	 * update the (r,c) location to be sq
   	 */
  	void notify(int oldType, Square &sq);  

	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

};

#endif
