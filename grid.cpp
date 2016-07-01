#include "grid.h"

Grid::Grid() {
	Nrows = 6;
	Ncols = 7;
	height.resize(Ncols, 0);
	grid.resize(Nrows, vector<int>(Ncols, 0));
	piece = make_pair(-1,-1);
}

Grid::Grid (int _Nrows, int _Ncols) {
	// mudar 
	Nrows = _Nrows;
	Ncols = _Ncols;
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
				printf(BLU " %c " RESET "|", 'O');
			} else if (grid[i][j] == 2) {
				printf(YEL " %c " RESET "|", 'O');
			} else {
				printf("   |");
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
		printf(BLU "Player 1 " RESET);
	else
		printf("Player 1 ");
	for (int i = 0; i < Ncols-4; i++)
		printf("    ");

	if (turn == 1)
		printf(YEL "Player 2 " RESET);
	else
		printf("Player 2 ");
	puts("\n");
}


bool Grid::won() {
	vector<int> qtd(8, 0);
	int row = piece.first, col = piece.second, cara = grid[row][col];
	//left
	for (int i = 1; i <= 3; i++) {
		if (row-i < 0 or grid[row-i][col] != cara) break;
		qtd[0]++;
	}
	//right
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or grid[row+i][col] != cara) break;
		qtd[0]++;
	}
	//up
	for (int i = 1; i <= 3; i++) {
		if (col-i < 0 or grid[row][col-i] != cara) break;
		qtd[1]++;
	}
	//down
	for (int i = 1; i <= 3; i++) {
		if (col+i >= Ncols or grid[row][col+i] != cara) break;
		qtd[1]++;
	}
	//downleft
	for (int i = 1; i <= 3; i++) {
		if (row-i < 0 or col-i < 0 or grid[row-i][col-i] != cara) break;
		qtd[2]++;
	}
	//upright
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or col+i >= Ncols or grid[row+i][col+i] != cara) break;
		qtd[2]++;
	}
	//downright
	for (int i = 1; i <= 3; i++) {
		if (row-i < 0 or col+i >= Ncols or grid[row-i][col+i] != cara) break;
		qtd[3]++;
	}
	//upleft
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or col-i < 0 or grid[row+i][col-i] != cara) break;
		qtd[3]++;
	}
	for (int i = 0; i < 4; i++) {
		if (qtd[i] >= 3) {
			return true;
		}
	}
	return false;
}

void Grid::makeMove(int mov, int turn) {
	mov--;
	if (height[mov] == Nrows or mov < 0 or mov >= Ncols) {
		printf("Invalid move of player #%d\n", turn+1);
		exit(0);
	}
	for (int i = 0; i <= Nrows-1-height[mov]; i++) {
		grid[i][mov] = turn ? 2 : 1;
		printTable(turn);
		usleep(60000);		
		grid[i][mov] = 0;
	}
	piece = make_pair(Nrows-1-height[mov], mov);
	grid[Nrows-1-height[mov]++][mov] = turn ? 2 : 1;
}