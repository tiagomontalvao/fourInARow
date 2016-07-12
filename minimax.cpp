#include "minimax.h"
#include <algorithm>

Minimax::Minimax () {
	score = 0;
}

Minimax::Minimax (const Grid& _grid, int _turn) {
	score = 0;
	grid = _grid;
	turn = _turn;
}

int Minimax::calcScore(int player) {
	// player: 0 ou 1
	// grid:   1 ou 2
	int scoreRetornado = 0;
	int enemy = 2-player;

	// horizontal
	for (int i = 0; i < grid.Nrows; i++) {
		for (int j = 0; j < grid.Ncols-3; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid.grid[i][j+k] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid.grid[i][j+k] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			scoreRetornado += valueSequence(dentroDaMascara);
		}
	}

	// vertical
	for (int i = 0; i < grid.Nrows-3; i++) {
		for (int j = 0; j < grid.Ncols; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid.grid[i+k][j] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid.grid[i+k][j] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			scoreRetornado += valueSequence(dentroDaMascara);
		}
	}

	// diagonal downright
	for (int i = 0; i < grid.Nrows-3; i++) {
		for (int j = 0; j < grid.Ncols-3; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid.grid[i+k][j+k] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid.grid[i+k][j+k] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			scoreRetornado += valueSequence(dentroDaMascara);
		}
	}

	// diagonal downleft
	for (int i = 3; i < grid.Nrows; i++) {
		for (int j = 0; j < grid.Ncols-3; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid.grid[i-k][j+k] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid.grid[i-k][j+k] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			scoreRetornado += valueSequence(dentroDaMascara);
	    }
	}
	return scoreRetornado;
}

int Minimax::valueSequence(int value) {
    for (int i = 0; i < 16; i++){
        if (value == sequence[i]){
            return pontuation[i];
        }
    }
    return ERROR_SEQ; //Return ERROR   
}

void Minimax::printScore(int player) {
    printf("Player: %d", player);
    /*for(int i = 0; i < 16; i++){
        printf("%d ", sequence[i]);
    }*/
    puts("");
    printf("%d\n", score);
    puts("--------");
}

int Minimax::recurse(int level) {
	int ret = (level&1) ? INF: -INF;
	if (level == maxLevel)
		return 2*calcScore(turn) - 3*calcScore(1-turn);
	if (level > maxLevel)
		return -ret;
	function<int(int,int)> cmp = [level] (int a, int b) -> int {
		return (level&1) ? min(a,b) : max(a,b);
	};
	int player = 1 + (turn ^ (level&1));
	int move = -1, rec;
	for (int i = 0; i < grid.Ncols; i++) {
		if (grid.height[i] == grid.Nrows) continue;
		grid.grid[grid.Nrows-1-grid.height[i]++][i] = player;
		rec = recurse(level+1);
		ret = cmp(ret, rec);
		if (ret == rec)
			move = i;
		grid.grid[grid.Nrows-1- --grid.height[i]][i] = 0;
	}
	if (level == 0) {
		nextMove = move+1;
		// printf("move: %d\n", move+1);
	}
	// printf("%d %d\n", ret, cmp(1, 2));
	return ret;
}