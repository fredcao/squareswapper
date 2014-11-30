#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>
#include "textdisplay.h"
#include "window.h"

class Square{
	protected:
	int row,col,colour,type;
	bool locked;

	TextDisplay *td;
	Xwindow *xw;

	int len;

	virtual void draw() = 0;
	public:
	enum { BasicSquare = 0, LateralSquare, UprightSquare, UnstableSquare, PsychedelicSquare };
	enum { White = 0, Red, Green, Blue, Black, Tan };
	Square();
	virtual ~Square();
	int getRow();
	int getCol();
	int getColour();
	int getType();
	bool getLocked();
	void setDisplay(TextDisplay *td);
	void setWindow(Xwindow *xw);
	
	virtual void print();
	virtual bool notify() = 0;
};

#endif
