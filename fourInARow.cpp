#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

#include "bot.h"

#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

int Nrows, Ncols, row, col;

void printTable(vector<vector<int>>& grid) {
	if (system("CLS")) system("clear");
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
				row = i;
				col = j;
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
	puts("");
}

bool won(vector<vector<int>>& grid, pair<int,int> piece) {
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
	//downright
	for (int i = 1; i <= 3; i++) {
		if (row-i < 0 or col+i >= Ncols or grid[row-i][col+i] != cara) break;
		qtd[2]++;
	}
	//upleft
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or col-i < 0 or grid[row+i][col-i] != cara) break;
		qtd[3]++;
	}
	//upright
	for (int i = 1; i <= 3; i++) {
		if (row+i >= Nrows or col+i >= Ncols or grid[row+i][col+i] != cara) break;
		qtd[3]++;
	}
	for (int i = 0; i < 4; i++) {
		if (qtd[i] >= 3) {
			printf("%d %d\n", i, qtd[i]);
			return true;
		}
	}
	return false;
} 

void makeMove(vector<vector<int>>& grid, vector<int>& height, int mov, int& turn, pair<int,int>& move) {
	mov--;
	if (height[mov] == Nrows or mov < 0 or mov >= Ncols) {
		printf("Invalid move of bot #%d\n", turn+1);
		exit(0);
	}
	move = make_pair(Nrows-1-height[mov], mov);
	grid[Nrows-1-height[mov]++][mov] = turn ? 2 : 1;
	turn = 1 - turn;
}

int main() {
	int mov, turn = 0;
	pair<int,int> piece;
	srand(time(NULL));
	Nrows = 6; Ncols = 7;
	vector<vector<int>> grid(Nrows, vector<int>(Ncols));
	vector<int> height(Ncols, 0);
	Bot bot1(Nrows, Ncols);
	do {
		printTable(grid);
		if (turn == 1) {
			printf("meh\n");
			makeMove(grid, height, bot1.getMove(piece), turn, piece);
		} else {
			scanf("%d", &mov);
			makeMove(grid, height, mov, turn, piece);
		}
	} while (!won(grid, piece));
	printTable(grid);
	puts("Yey!");
	return 0;
}