#ifndef FOURINAROW_H
#define FOURINAROW_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unistd.h>
using namespace std;

#include "player.h"
#include "human.h"
#include "bot.h"
#include "grid.h"

class FourInARow {
public:

	int turn;
	Grid grid;
	Player *player1, *player2;

	static const int Nrows = 6;
	static const int Ncols = 7;

	FourInARow ();
	FourInARow (int _turn);

	void startMessage();
	void startGame();

};

#endif