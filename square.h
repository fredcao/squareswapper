#ifndef __SQUARE_H__
#define __SQUARE_H__

class Square{
	protected:
	int colour,row,col,type;
	bool locked;
	public:
	enum { BasicSquare = 0; LateralSquare; UprightSquare; UnstableSquare; PsychedelicSquare }
	enum { White = 0, Red, Green, Blue }
	Square();
	virtual ~Square();
	int getColour();
	int getRow();
	int getCol();
	int getType();
	bool getLocked;
	virtual void notify() = 0;
};

#endif
