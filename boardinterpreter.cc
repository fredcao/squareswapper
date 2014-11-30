
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "basicsquare.h"
#include "lateralsquare.h"
#include "uprightsquare.h"
#include "unstablesquare.h"
#include "psychedelicsquare.h"
#include "boardinterpreter.h"

using namespace std;

BoardInterpreter::BoardInterpreter() {




}

BoardInterpreter::~BoardInterpreter() {

}

void BoardInterpreter::remove(int r, int c) {

	cout << "Remove called" << endl;

	if (!board[r][c]->notify()) {
		board[r][c] = NULL;
	}

	//delete board[r][c];
}

void BoardInterpreter::dropFillTemp() {

	dropFill();

}

void BoardInterpreter::startGame() {

	delete instance;

//	draw();

	level = startLevel;

	cout << "Starting game at level ... " << level << endl;

	if (level == 0) {

		cout << "Create new BoardL0" << endl;
		instance = new BoardL0();

	}
	else if (level == 1) {

		instance = new BoardL1();

	}
	else if (level == 2) {

		instance = new BoardL2();

	}
	else {

		instance = new BoardL0();

	}

	atexit(cleanup);	

	instance->constructBoard();

	draw();

}	


void BoardInterpreter::swap(int x, int y, int z) {

	Square *temp = board[x][y];

	if (z == 0) {

		board[x][y] = board[x-1][y];
		board[x-1][y] = temp;

	}
	else if (z == 1) {

		board[x][y] = board[x+1][y];
		board[x+1][y] = temp;

	}
	else if (z == 2) {

		board[x][y] = board[x][y-1];
		board[x][y-1] = temp;

	}
	else if (z == 3) {

		board[x][y] = board[x][y+1];
		board[x][y+1] = temp;

	}

	int points;
	int newPoints = -1;
	int n = 1;
			
	while (newPoints != 0) {

		newPoints = 0;	

		//newPoints += matchL();
		//newPoints += match5();
		//newPoints += match4();
		//newPoints += match3();

		points += newPoints * static_cast<int>(pow(2, n));

		n++;

		cout << "Points earned in chain reaction (" << n << "): " << newPoints * pow(2, n) << endl;

		dropFill();

	}

	score += points;

	if (score > highscore) {

		highscore = score;

	}


	// 0 N
	// 2 W
	// 3 E
	// 1 S


}

int *BoardInterpreter::hint() {
	int curColour;
	int *ans = new int[3];
	for(int i=0;i<boardSize;i++){		//find horizontal row of two
		for(int j=0;j<boardSize-1;j++){
			curColour=board[i][j]->getColour();
			if(board[i][j+1]->getColour()==curColour){	//row of two, check six cases
				if(i-1>=0&&j-1>=0&&board[i-1][j-1]->getColour()==curColour){
					ans[0]=i-1;
					ans[1]=j-1;
					ans[2]=1;
					return ans;
				}
				if(i-1>=0&&j+2<=9&&board[i-1][j+2]->getColour()==curColour){
					ans[0]=i-1;
					ans[1]=j+2;
					ans[2]=1;
					return ans;
				}
				if(i+1<=9&&j-1>=0&&board[i+1][j-1]->getColour()==curColour){
					ans[0]=i+1;
					ans[1]=j-1;
					ans[2]=0;
					return ans;
				}
				if(i+1<=9&&j+2<=9&&board[i+1][j+2]->getColour()==curColour){
					ans[0]=i+1;
					ans[1]=j+2;
					ans[2]=0;
					return ans;
				}
				if(j-2>=0&&board[i][j-2]->getColour()==curColour){
					ans[0]=i;
					ans[1]=j-2;
					ans[2]=3;
					return ans;
				}
				if(j+3<=9&&board[i][j+3]->getColour()==curColour){
					ans[0]=i;
					ans[1]=j+3;
					ans[2]=2;
					return ans;
				}
			}
			if(i-1>=0&&j+2<=9&&board[i-1][j+1]->getColour()==curColour&&board[i][j+2]->getColour()==curColour){	//check horizontal triangle cases
				ans[0]=i-1;
				ans[1]=j+1;
				ans[2]=1;
				return ans;
			}
			if(i+1<=9&&j+2<=9&&board[i+1][j+1]->getColour()==curColour&&board[i][j+2]->getColour()==curColour){
				ans[0]=i+1;
				ans[1]=j+1;
				ans[2]=0;
				return ans;
			}
		}
	}
	for(int j=0;j<boardSize;j++){
		for(int i=0;i<boardSize-1;i++){
			curColour=board[i][j]->getColour();
			if(board[i+1][j]->getColour()==curColour){
				if(i-1>=0&&j-1>=0&&board[i-1][j-1]->getColour()==curColour){
					ans[0]=i-1;
					ans[1]=j-1;
					ans[2]=3;
					return ans;
				}
				if(i-1>=0&&j+1<=9&&board[i-1][j+1]->getColour()==curColour){
					ans[0]=i-1;
					ans[1]=j+1;
					ans[2]=2;
					return ans;
				}
				if(i+2<=9&&j-1>=0&&board[i+2][j-1]->getColour()==curColour){
					ans[0]=i+2;
					ans[1]=j-1;
					ans[2]=3;
					return ans;
				}
				if(i+2<=9&&j+1<=9&&board[i+2][j+1]->getColour()==curColour){
					ans[0]=i+2;
					ans[1]=j+1;
					ans[2]=2;
					return ans;
				}
				if(i-2>=0&&board[i-2][j]->getColour()==curColour){
					ans[0]=i-2;
					ans[1]=j;
					ans[2]=1;
					return ans;
				}
				if(i+3<=9&&board[i+3][j]->getColour()==curColour){
					ans[0]=i+3;
					ans[1]=j;
					ans[2]=0;
					return ans;
				}
			}
			if(i+2<=9&&j-1>=0&&board[i+1][j-1]->getColour()==curColour&&board[i+2][j]->getColour()==curColour){
				ans[0]=i+1;
				ans[1]=j-1;
				ans[2]=3;
				return ans;
			}
			if(i+2<=9&&j+1<=9&&board[i+1][j+1]->getColour()==curColour&&board[i+2][j]->getColour()==curColour){
				ans[0]=i+1;
				ans[1]=j+1;
				ans[2]=2;
				return ans;
			}
		}
	}
	return NULL;			

}

void BoardInterpreter::scramble() {


}

void BoardInterpreter::levelUp() {




}

void BoardInterpreter::levelDown() {



}


void BoardInterpreter::restart() {



}

void BoardInterpreter::setTextOnly(bool textOnly) {

	this->textOnlyFlag = textOnly;

}

void BoardInterpreter::setSeed(int seed) {

	this->seed = seed;

}

void BoardInterpreter::setFile(string file) {

	this->file = file;

}

void BoardInterpreter::setStartLevel(int startLevel) {

	this->startLevel = startLevel;

}


bool BoardInterpreter::textOnly() {

	return textOnlyFlag;

}

void BoardInterpreter::match3() {

// Find horizontal and vertical matches of 3
 // Notify the squares that are part of the match
 // Call doEffect(sq) for each square that are part of the match

         int curColour;
         for(int i=0;i < boardSize; i++){        //checking horizontal matches
                 for(int j=0;j < boardSize-2; j++){
                         if(!(board[i][j]&&board[i][j+1]&&board[i][j+2])){           //checking that not null
                                 continue;
                         }
                         curColour=board[i][j]->getColour();
                         if(board[i][j+1]->getColour()==curColour && board[i][j+2]->getColour()==curColour){
                                 if(board[i][j])doEffect(board[i][j],3);
                                 if(board[i][j+1])doEffect(board[i][j+1],3);
                                 if(board[i][j+2])doEffect(board[i][j+2],3); 
                                 j+=3;
                         }
                 }
         }
         for(int j=0;j<boardSize;j++){           //checking vertical matches
                 for(int i=0;i<boardSize-2;i++){
                         if(!(board[i][j]&&board[i+1][j]&&board[i+2][j])){
                                 continue;
                         }
                         curColour=board[i][j]->getColour();
                         if(board[i+1][j]->getColour()==curColour && board[i+2][j]->getColour()==curColour){
                                 if(board[i][j])doEffect(board[i][j],3);
                                 if(board[i+1][j])doEffect(board[i+1][j],3);
                                 if(board[i+2][j])doEffect(board[i+2][j],3);
                                 i+=3;
                         }
                 }
         }
}

void BoardInterpreter::match4() {

// Same thing as match3 except with 4
	int curColour;
        for(int i=0;i<boardSize;i++){
                for(int j=0;j<boardSize-3;j++){
                        if(!(board[i][j]&&board[i][j+1]&&board[i][j+2]&&board[i][j+3])){
                                continue;
                        }
                        curColour=board[i][j]->getColour();
                        if(board[i][j+1]->getColour()==curColour && board[i][j+2]->getColour()==curColour && board[i][j+3]->getColour()==curColour){
                                if(board[i][j])doEffect(board[i][j],5);
                                if(board[i][j+1])doEffect(board[i][j+1],5);
                                if(board[i][j+2])doEffect(board[i][j+2],5);
                                if(board[i][j+3])doEffect(board[i][j+3],5);
                                j+=4;
                        }
                }
        }
        for(int j=0;j<boardSize;j++){
                for(int i=0;i<boardSize-3;i++){
                        if(!(board[i][j]&&board[i+1][j]&&board[i+2][j]&&board[i+3][j])){
                                continue;
                        }
                        curColour=board[i][j]->getColour();
                        if(board[i+1][j]->getColour()==curColour && board[i+2][j]->getColour()==curColour && board[i+3][j]->getColour()==curColour){
                                if(board[i][j])doEffect(board[i][j],5);
                                if(board[i+1][j])doEffect(board[i+1][j],5);
                                if(board[i+2][j])doEffect(board[i+2][j],5);
                                if(board[i+3][j])doEffect(board[i+3][j],5);
                                i+=4;
                        }
                }
        }
}

void BoardInterpreter::match5() {

// Same thing as match4 except...
// Really this is match 5 or more as matching for example 10 gives you the same result
	int curColour;
        int count = 1;
        for(int i=0;i<boardSize;i++){
                for(int j=0;j<boardSize-4;j++){         //horizontal
                        if(board[i][j]){
                                curColour = board[i][j]->getColour();
                                for(int k=j+1;k<boardSize;k++){
                                        if(!(board[i][k]&&board[i][k]->getColour()==curColour)){
                                                break;
                                        }
                                        count++;
                                }
                                if(count>=5){           //minimum 5 in  row
                                        for(int k=j;k<j+count;k++){
                                                if(board[i][k])doEffect(board[i][k],5);
                                        }
                                        j+=5;
                                }
                                count=1;
                        }
                }
        }
        for(int j=0;j<boardSize;j++){
                for(int i=0;i<boardSize-4;i++){
                        if(board[i][j]){
                                curColour=board[i][j]->getColour();
                                for(int k=i+1;k<boardSize;k++){
                                        if(!(board[k][j]&&board[k][j]->getColour()==curColour)){
                                                break;
                                        }
                                        count++;
                                }
                                if(count>=5){
                                        for(int k=i;k<i+count;k++){
                                                if(board[k][j])doEffect(board[k][j],5);
                                        }
                                        i+=5;
				 }
                                count=1;
                        }
                }
        }
}

void BoardInterpreter::matchL() {

	int curColour;  // Same thing as match5 except actually an L instead of line
        for(int i=0;i<boardSize;i++){
                for(int j=0;j<boardSize-2;j++){
                        if(!(board[i][j]&&board[i][j+1]&&board[i][j+2])){
                                continue;
                        }
                        curColour=board[i][j]->getColour();
                        if(board[i][j+1]->getColour()==curColour&&board[i][j+2]->getColour()==curColour){       //found horizontal match of 3
                                if(i>1){
                                        if(board[i-1][j]&&board[i-2][j]&&board[i-1][j]->getColour()==curColour&&board[i-2][j]->getColour()==curColour){
                                                if(board[i][j])doEffect(board[i][j],5);
                                                if(board[i][j+1])doEffect(board[i][j+1],5);
                                                if(board[i][j+2])doEffect(board[i][j+2],5);
                                                if(board[i-1][j])doEffect(board[i-1][j],5);
                                                if(board[i-2][j])doEffect(board[i-2][j],5);
                                                j+=3;
                                        }
                                        else if(board[i-1][j+2]&&board[i-2][j+2]&&board[i-1][j+2]->getColour()==curColour&&board[i-2][j+2]->getColour()==curColour){
                                                if(board[i][j])doEffect(board[i][j],5);
                                                if(board[i][j+1])doEffect(board[i][j+1],5);
                                                if(board[i][j+2])doEffect(board[i][j+2],5);
                                                if(board[i-1][j+2])doEffect(board[i-1][j+2],5);
                                                if(board[i-2][j+2])doEffect(board[i-2][j+2],5);
                                                j+=3;
                                        }
                                }
				 if(i<8){
                                        if(board[i+1][j]&&board[i+2][j]&&board[i+1][j]->getColour()==curColour&&board[i+2][j]->getColour()==curColour){
                                                if(board[i][j])doEffect(board[i][j],5);
                                                if(board[i][j+1])doEffect(board[i][j+1],5);
                                                if(board[i][j+2])doEffect(board[i][j+2],5);
                                                if(board[i+1][j])doEffect(board[i+1][j],5);
                                                if(board[i+2][j])doEffect(board[i+2][j],5);
                                                j+=3;
                                        }
                                        else if(board[i+1][j+2]&&board[i+2][j+2]&&board[i+1][j+2]->getColour()==curColour&&board[i+2][j+2]->getColour()==curColour){
                                                if(board[i][j])doEffect(board[i][j],5);
                                                if(board[i][j+1])doEffect(board[i][j+1],5);
                                                if(board[i][j+2])doEffect(board[i][j+2],5);
                                                if(board[i+1][j+2])doEffect(board[i+1][j+2],5);
                                                if(board[i+2][j+2])doEffect(board[i+2][j+2],5);
                                                j+=3;
                                        }
                                }
                        }
                }
        }
}
