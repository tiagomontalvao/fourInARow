#include "player.h"

Player::Player (int _player, int _Nrows, int _Ncols) {
	player = _player;
	Nrows = _Nrows;
	Ncols = _Ncols;
	height.resize(Ncols, 0);
}

int Player::getMove(pair<int,int> lastMove) {
	return 1;
}

string Player::toString() {
	return "Player";
}
