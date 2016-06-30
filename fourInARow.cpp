#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

#include "bot.h"
#include "player.h"
#include "grid.h"

int Nrows, Ncols;

int main() {
	int turn = 0;
	Nrows = 6; Ncols = 7;
	Bot bot(Nrows, Ncols);
	Player player(Nrows, Ncols);
	Grid grid(Nrows, Ncols);
	do {
		grid.printTable();
		if (turn == 1) {
			grid.makeMove(bot.getMove(grid.piece), turn);
		} else {
			grid.makeMove(player.getMove(grid.piece), turn);
		}
	} while (!grid.won());
	grid.printTable();
	printf("You %s!\n", turn ? "won" : "lost");
	return 0;
}