#include "uprightsquare.h"
using namespace std;

UprightSquare::UprightSquare(int row,int col,int colour=White,bool locked=false):row(row),col(col),colour(colour),type(2),locked(locked){}

UprightSquare::~UprightSquare(){}

void UprightSquare::notify(){}

