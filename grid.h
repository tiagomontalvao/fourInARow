#ifndef GRID_H
#define GRID_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unistd.h>
using namespace std;

#define BLU   "\x1B[34m"
#define RED   "\x1B[31m"
#define YEL   "\x1B[33m"
#define BGBLU "\x1B[44;37m"
#define BGYEL "\x1B[43;37m"
#define RESET "\x1B[0m"

class Grid {
public:

	int Nrows, Ncols;
	char nome1[16], nome2[16];
	vector<int> height;
	vector<vector<int>> grid;
	vector<int> lastEnemyMoves;
	pair<int,int> piece;

	Grid ();
	Grid (int _Nrows, int _Ncols);
	Grid (int _Nrows, int _Ncols, const char *nome1, const char* nome2);

	void printTable(int turn);
	bool won(int turn, int draw);
	void makeMove(int mov, int turn, int draw);
	void printWinningTable(int row, int col, int drow, int dcol, int turn);

};

#endif
