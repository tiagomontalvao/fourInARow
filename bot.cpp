#include "bot.h"

Bot::Bot (int _player, int _Nrows, int _Ncols) : Player(_player, _Nrows, _Ncols) {
	grid = Grid(_Nrows, _Ncols);
}

int Bot::getMove(pair<int,int> lastMove) {
	if (lastMove != make_pair(-1,-1)) {
		grid.makeMove(lastMove.second+1, 1-player, 0);
	}
	Minimax minimax(grid, player);
	minimax.recurse(0);
	int move = minimax.nextMove;
	grid.printTable(player);
	grid.makeMove(move, player, 0);
	return move;
}

string Bot::toString() {
	return "Bot";
}
