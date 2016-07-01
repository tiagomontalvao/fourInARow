#include "player.h"

Player::Player (int _Nrows, int _Ncols) {
	Nrows = _Nrows;
	Ncols = _Ncols;
	height.resize(Ncols, 0);
}

int Player::getMove(pair<int,int> lastMove) {
	return 1;
}

