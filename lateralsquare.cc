#include "lateralsquare.h"
using namespace std;

LateralSquare::LateralSquare(int row,int col,int colour=White,bool locked=false):row(row),col(col),colour(colour),type(1),locked(locked){}

LateralSquare::~LateralSquare(){}

void LateralSquare::notify(){}

