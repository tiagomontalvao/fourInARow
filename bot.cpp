#include "bot.h"

Bot::Bot (int _Nrows, int _Ncols) : Player(_Nrows, _Ncols) {}

int Bot::getMove(pair<int,int> lastMove) {
	int lastCol = -1;
	if (lastMove != make_pair(-1,-1)) {
		lastCol = lastMove.second;
		lastEnemyMoves.push_back(lastCol);
		height[lastCol]++;
	}
	int move;
	do { 
		if (lastCol == -1) {
			move = rand()%Ncols;
			continue;
		}

		// Código responsável pela IA do bot
		// ----------- início --------------
		
		move = rand()%3 + lastCol-1;
		if (move < 0) move = 0;
		if (move >= Ncols) move = Ncols;

		// ------------ fim ----------------

	} while (height[move] >= Nrows);
	height[move]++;
	return move+1;
}

string Bot::toString() {
	return "Bot";
}
