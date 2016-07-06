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

	enum sequence {one, twoInARow, threeInARow, twoSplit, threeSplit};
	int pont[5] = {1, 2, 3, 4, 5};

	int Nrows, Ncols, score;
	vector<vector<int>> grid;

	Minimax ();
	Minimax (const Grid& grid);

	void calcScore(int turn);

};

#endif