#include "unstablesquare.h"
using namespace std;

UnstableSquare::UnstableSquare(int row,int col,int colour=White,bool locked=false):row(row),col(col),colour(colour),type(3),locked(locked){}

UnstableSquare::~UnstableSquare(){}

void UnstableSquare::notify(){}

