#include "minimax.h"
#include <cmath>
using namespace std;

Minimax::Minimax () {
	score = 0;
}

Minimax::Minimax (const Grid& _grid) {
	score = 0;
	Nrows = _grid.Nrows;
	Ncols = _grid.Ncols;
	grid = _grid.grid;
}

void Minimax::calcScore(int player) {
	// player: 0 ou 1
	// grid:   1 ou 2
	score = 0;
	int enemy = 2-player;

	// horizontal
	for (int i = 0; i < Nrows; i++) {
		for (int j = 0; j < Ncols-3; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid[i][j+k] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid[i][j+k] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			score += valueSequence(dentroDaMascara);
		}
	}

	// vertical
	for (int i = 0; i < Nrows-3; i++) {
		for (int j = 0; j < Ncols; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid[i+k][j] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid[i+k][j] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			score += valueSequence(dentroDaMascara);
		}
	}

	// diagonal downright
	for (int i = 0; i < Nrows-3; i++) {
		for (int j = 0; j < Ncols-3; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid[i+k][j+k] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid[i+k][j+k] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			score += valueSequence(dentroDaMascara);
		}
	}

	// diagonal downleft
	for (int i = 3; i < Nrows; i++) {
		for (int j = 0; j < Ncols-3; j++) {
			int dentroDaMascara = 0;
			for (int k = 0; k < 4; k++) {
				if (grid[i-k][j+k] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				if (grid[i-k][j+k] == player + 1){
				    dentroDaMascara += pow(10,(3-k));
				}
			}
			// mexer no peso
			score += valueSequence(dentroDaMascara);
	    }
	}
}


int Minimax::valueSequence(int value) {
    for (int i = 0; i < 16; i++){
        if (value == sequence[i]){
            return pontuation[i];
        }
    }
    return 999999; //Return ERROR   
}
void Minimax::printScore(int turn) {
    printf("Player: %d", turn+1);
    /*for(int i = 0; i < 16; i++){
        printf("%d ", sequence[i]);
    }*/
    puts("");
    printf("%d\n", score);
    puts("--------");
}
