#ifndef HUMAN_H
#define HUMAN_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

#include "player.h"

class Human : public Player {
public:

	Human () {}
	Human (int _Nrows, int _Ncols);

	int getMove(pair<int,int> lastMove);

};

#endif