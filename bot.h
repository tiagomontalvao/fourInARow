#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

class Bot {
public:

	int Nrows, Ncols;
	vector<int> height;
	vector<int> lastEnemyMoves;

	Bot ();
	Bot (int _Nrows, int _Ncols);

	int getMove(pair<int,int> lastMove);

};


