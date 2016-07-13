#include "grid.h"

Grid::Grid() {
	Nrows = 6;
	Ncols = 7;
	height.resize(Ncols, 0);
	grid.resize(Nrows, vector<int>(Ncols, 0));
	piece = make_pair(-1,-1);
}

Grid::Grid (int _Nrows, int _Ncols) {
	Nrows = _Nrows;
	Ncols = _Ncols;
	height.resize(Ncols, 0);
	grid.resize(Nrows, vector<int>(Ncols, 0));
	piece = make_pair(-1,-1);
}

Grid::Grid (int _Nrows, int _Ncols, const char *_nome1, const char *_nome2) {
	Nrows = _Nrows;
	Ncols = _Ncols;
	strcpy(nome1, _nome1);
	strcpy(nome2, _nome2);
	height.resize(Ncols, 0);
	grid.resize(Nrows, vector<int>(Ncols, 0));
	piece = make_pair(-1,-1);
}

void Grid::printTable(int turn) {
	system("clear");
	printf("+");
	for (int i = 0; i < Ncols; i++)
		printf("---+");
	puts("");

	for (int i = 0; i < Nrows; i++) {
		printf("|");
		for (int j = 0; j < Ncols; j++) {
			if (grid[i][j] == 1) {
				printf(BLU " O " RESET "|");
			} else if (grid[i][j] == 2) {
				printf(YEL " O " RESET "|");
			} else if (grid[i][j] == 3) {
				printf(BGBLU " O " RESET "|");
			} else if (grid[i][j] == 4) {
				printf(BGYEL " O " RESET "|");
			} else {
				printf("   |");
				// printf(" %d |", grid[i][j]);
			}
		}
		printf("\n+");
		for (int j = 0; j < Ncols; j++) {
			printf("---+");
		}
		puts("");
	}

	printf("-");
	for (int i = 0; i < Ncols; i++)
		printf(" %d -", i+1);
	puts("\n");
	if (turn == 0)
		printf(BLU "%-14s " RESET, nome1);
	else
		printf("%-14s ", nome1);

	if (turn == 1)
		printf(YEL "%14s" RESET, nome2);
	else
		printf("%14s", nome2);
	puts("\n");
}


bool Grid::won(int turn, int draw) {
	vector<int> qtd(8, 0);
	int row = piece.first, col = piece.second, cara = grid[row][col];
	//left
	for (int i = 1; i <= 3; i++) {
		if (row-i < 0 or grid[row-i][col] != cara) break;
		qtd[0]++;
		if (qtd[0] == 3) {
			if (draw) printWinningTable(row-i, col, 1, 0, turn);
			return true;
		}
	}
	//right
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or grid[row+i][col] != cara) break;
		qtd[0]++;
		if (qtd[0] == 3) {
			if (draw) printWinningTable(row+i, col, -1, 0, turn);
			return true;
		}
	}
	//up
	for (int i = 1; i <= 3; i++) {
		if (col-i < 0 or grid[row][col-i] != cara) break;
		qtd[1]++;
		if (qtd[1] == 3) {
			if (draw) printWinningTable(row, col-i, 0, 1, turn);
			return true;
		}
	}
	//down
	for (int i = 1; i <= 3; i++) {
		if (col+i >= Ncols or grid[row][col+i] != cara) break;
		qtd[1]++;
		if (qtd[1] == 3) {
			if (draw) printWinningTable(row, col+i, 0, -1, turn);
			return true;
		}
	}
	//downleft
	for (int i = 1; i <= 3; i++) {
		if (row-i < 0 or col-i < 0 or grid[row-i][col-i] != cara) break;
		qtd[2]++;
		if (qtd[2] == 3) {
			if (draw) printWinningTable(row-i, col-i, 1, 1, turn);
			return true;
		}
	}
	//upright
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or col+i >= Ncols or grid[row+i][col+i] != cara) break;
		qtd[2]++;
		if (qtd[2] == 3) {
			if (draw) printWinningTable(row+i, col+i, -1, -1, turn);
			return true;
		}
	}
	//downright
	for (int i = 1; i <= 3; i++) {
		if (row-i < 0 or col+i >= Ncols or grid[row-i][col+i] != cara) break;
		qtd[3]++;
		if (qtd[3] == 3) {
			if (draw) printWinningTable(row-i, col+i, 1, -1, turn);
			return true;
		}
	}
	//upleft
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or col-i < 0 or grid[row+i][col-i] != cara) break;
		qtd[3]++;
		if (qtd[3] == 3) {
			if (draw) printWinningTable(row+i, col-i, -1, 1, turn);
			return true;
		}
	}
	return false;
}

void Grid::makeMove(int mov, int turn, int draw) {
	mov--;
	if (height[mov] == Nrows or mov < 0 or mov >= Ncols) {
		printf("Invalid move of player #%d\n", turn+1);
		exit(0);
	}
	if (draw) {
		for (int i = 0; i <= Nrows-1-height[mov]; i++) {
			grid[i][mov] = turn ? 2 : 1;
			printTable(turn);
			usleep(60000);		
			grid[i][mov] = 0;
		}
	}
	piece = make_pair(Nrows-1-height[mov], mov);
	grid[Nrows-1-height[mov]++][mov] = turn ? 2 : 1;
}

void Grid::printWinningTable(int row, int col, int drow, int dcol, int turn) {
	int winner = grid[row][col];
	for (int i = 0; i < 6; i++) {
		for (int k = 0; k < 4; k++) {
			grid[row+drow*k][col+dcol*k] = (i&1) ? winner : winner+2;
			printTable(turn);
			usleep(30000);		
		}
	}
}