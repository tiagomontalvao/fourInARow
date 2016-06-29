#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

#include "bot.h"

Bot::Bot (int _Nrows, int _Ncols) {
	Nrows = _Nrows;
	Ncols = _Ncols;
	height.resize(Ncols, 0);
}

int Bot::getMove(pair<int,int> lastMove) {
	int lastCol = lastMove.second;
	lastEnemyMoves.push_back(lastCol);
	height[lastCol]++;
	srand(time(NULL));
	int move;
	do { 
		move = rand()%3 + lastCol-1;
	} while (height[move] >= Nrows);
	height[move]++;
	return move+1;
}

