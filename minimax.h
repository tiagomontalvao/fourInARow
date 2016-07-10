#ifndef MINIMAX_H
#define MINIMAX_H

#include <cmath>
using namespace std;

#include <functional>
#include "grid.h"

#define INF 0x3f3f3f3f

class Minimax {
public:

	const int ERROR_SEQ = -1;
	const int maxLevel = 5;

	int sequence[16] =  { 0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};
	int pontuation[16] = {0, 1,  1,  4,   1,   5,   4, 100,    1,    2,    5,   10,    4,   10,  100,  INF};

	int turn, score, nextMove;
	Grid grid;

	Minimax ();
	Minimax (const Grid& _grid, int _turn);

	int calcScore(int turn);
	void printScore(int turn);
	int valueSequence(int value);
	int recurse(int level);

};

#endif
