#ifndef __SQUARE_H__
#define __SQUARE_H__

class Square{

	public:
	enum { BasicSquare = 0; LateralSquare; UprightSquare; UnstableSquare; PsychedelicSquare }
	virtual ~Square();
	virtual int getColour() = 0;
	virtual int getRow() = 0;
	virtual int getCol() = 0;
	virtual int getType() = 0;
	virtual void notify() = 0;
};

#endif
