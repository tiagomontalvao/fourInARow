#ifndef FOURINAROW_H
#define FOURINAROW_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unistd.h>
using namespace std;

#include "player.h"
#include "human.h"
#include "bot.h"
#include "grid.h"
#include "minimax.h"

class FourInARow {
public:

	int turn, nPieces;
	Grid grid;
	Player *player1, *player2;
	char nome1[16], nome2[16];

	static const int Nrows = 6;
	static const int Ncols = 7;

	FourInARow ();
	FourInARow (int _turn);

	void startMessage();
	void startGame();
	bool finished(Grid& grid);

};

#endif
