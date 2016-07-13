#ifndef BOT_H
#define BOT_H

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#include "player.h"
#include "minimax.h"

class Bot : public Player {
public:

	Grid grid;

	Bot () {}
	Bot (int _player, int _Nrows, int _Ncols);

	int getMove(pair<int,int> lastMove);
	string toString();

};

#endif