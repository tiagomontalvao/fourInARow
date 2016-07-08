#ifndef MINIMAX_H
#define MINIMAX_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unistd.h>
using namespace std;

#include "grid.h"

class Minimax {
public:

	int sequence[16] = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};
	int pontuation[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
	int pont[5] = {1, 2, 3, 4, 5};

	int Nrows, Ncols, score;
	vector<vector<int>> grid;

	Minimax ();
	Minimax (const Grid& grid);

	void calcScore(int turn);
	void printScore(int turn);
	int valueSequence(int value);

};

#endif
