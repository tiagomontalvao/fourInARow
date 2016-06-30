#include "bot.h"

Bot::Bot (int _Nrows, int _Ncols) {
	srand(time(NULL));
	Nrows = _Nrows;
	Ncols = _Ncols;
	height.resize(Ncols, 0);
}

int Bot::getMove(pair<int,int> lastMove) {
	int lastCol = -1;
	if (lastMove != make_pair(-1,-1)) {
		lastCol = lastMove.second;
		lastEnemyMoves.push_back(lastCol);
		height[lastCol]++;
	}
	srand(time(NULL));
	int move;
	do { 
		if (lastCol == -1) {
			move = rand()%Ncols;
		} else {
			move = rand()%3 + lastCol-1;
			if (move < 0) move = 0;
			if (move >= Ncols) move = Ncols;
		}
	} while (height[move] >= Nrows);
	height[move]++;
	return move+1;
}

