#include "player.h"

Player::Player (int _Nrows, int _Ncols) {
	Nrows = _Nrows;
	Ncols = _Ncols;
	height.resize(Ncols, 0);
}

int Player::getMove(pair<int,int> lastMove) {
	if (lastMove != make_pair(-1,-1)) {
		int lastCol = lastMove.second;
		lastEnemyMoves.push_back(lastCol);
		height[lastCol]++;
	}
	int move;
	scanf("%d", &move);
	while (height[move] >= Nrows and (move < 0 or move >= Ncols)) {
		printf("Invalid move. Pick a number in the range [%d, %d]\n", 1, Ncols);
		scanf("%d", &move);
	}
	height[move]++;
	return move;
}

