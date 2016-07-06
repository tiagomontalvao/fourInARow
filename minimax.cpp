#include "minimax.h"

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
	int enemy = 2-player;

	// horizontal
	for (int i = 0; i < Nrows; i++) {
		for (int j = 0; j < Ncols-3; j++) {
			int dentroDaMascara = 0;
			for (int k = j; k < j+4; k++) {
				if (grid[i][k] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				dentroDaMascara++;
			}
			// mexer no peso
			score += dentroDaMascara;
		}
	}

	// vertical
	for (int i = 0; i < Nrows-3; i++) {
		for (int j = 0; j < Ncols; j++) {
			int dentroDaMascara = 0;
			for (int k = i; k < i+4; k++) {
				if (grid[k][j] == enemy) {
					dentroDaMascara = 0;
					break;
				}
				dentroDaMascara++;
			}
			// mexer no peso
			score += dentroDaMascara;
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
				dentroDaMascara++;
			}
			// mexer no peso
			score += dentroDaMascara;
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
				dentroDaMascara++;
			}
			// mexer no peso
			score += dentroDaMascara;
		}
	}
	printf("%d\n", score);
}