#ifndef GRID_H
#define GRID_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unistd.h>
using namespace std;

#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

class Grid {
public:

	int Nrows, Ncols;
	vector<int> height;
	vector<vector<int>> grid;
	vector<int> lastEnemyMoves;
	pair<int,int> piece = {-1,-1};

	Grid ();
	Grid (int _Nrows, int _Ncols);

	void printTable(int turn);
	bool won();
	void makeMove(int mov, int turn);

};

#endif