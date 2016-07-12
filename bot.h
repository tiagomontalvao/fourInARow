#ifndef BOT_H
#define BOT_H

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#include "player.h"

class Bot : public Player {
public:

	Bot () {}
	Bot (int _Nrows, int _Ncols);

	int getMove(pair<int,int> lastMove);
	string toString();

};

#endif