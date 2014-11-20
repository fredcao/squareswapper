#include "basicsquare.h"
using namespace std;

BasicSquare::BasicSquare(int row,int col,int colour=White,bool locked=false):row(row),col(col),colour(colour),type(0),locked(locked){}

BasicSquare::~BasicSquare(){}

void BasicSquare::notify(){}

