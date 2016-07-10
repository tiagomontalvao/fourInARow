#ifndef PLAYER_H
#define PLAYER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Player {
public:

	int Nrows, Ncols;
	vector<int> height;
	vector<int> lastEnemyMoves;

	Player() {}
	~Player() {}
	Player (int _Nrows, int _Ncols);

	virtual int getMove(pair<int,int> lastMove);
	virtual string toString();

};

#endif