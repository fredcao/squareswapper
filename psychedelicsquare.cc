#include "psychedelicsquare.h"
using namespace std;

PsychedelicSquare::PsychedelicSquare(int row,int col,int colour=White,bool locked=false):row(row),col(col),colour(colour),type(4),locked(locked){}

PsychedelicSquare::~PsychedelicSquare(){}

void PsychedelicSquare::notify(){}

