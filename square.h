#ifndef __SQUARE_H__
#define __SQUARE_H__

class Square{
	protected:
	int row,col,colour,type;
	bool locked;
	void draw();
	public:
	enum { BasicSquare = 0; LateralSquare; UprightSquare; UnstableSquare; PsychedelicSquare }
	enum { White = 0, Red, Green, Blue }
	Square();
	virtual ~Square();
	int getRow();
	int getCol();
	int getColour();
	int getType();
	bool getLocked;
	virtual void notify() = 0;
};

#endif
