#include "fourInARow.h"

FourInARow::FourInARow () {
	nPieces = 0;
	turn = 1;
}
FourInARow::FourInARow (int _turn) {
	nPieces = 0;
	turn = _turn;
}

void FourInARow::startMessage() {
	if (nPieces == 0) system("clear");
	puts("Choose one:");
	puts("(1): Human vs Human");
	puts("(2): Human vs Bot");
	puts("(3): Bot vs Human");
	puts("(4): Bot vs Bot");
	puts("(5): Exit");
}

bool FourInARow::finished(Grid& grid, int turn) {
	return (grid.won(turn, 1) or nPieces == Nrows*Ncols);
}

void FourInARow::startGame() {
	srand(time(NULL));
	int optionChoosen;
	
	while (true) {
		startMessage();
		scanf("%d", &optionChoosen);
		while (optionChoosen < 1 or optionChoosen > 5) {
			startMessage();
			printf("Invalid option. Choose a number in the range [1,5]: ");
			scanf("%d", &optionChoosen);
		}
		
		scanf("%*c");
		switch (optionChoosen) {
			case 1:
				player[0] = new Human(0, Nrows, Ncols);
				player[1] = new Human(1, Nrows, Ncols);
				printf("Nome #1: "); scanf("%s", nome1);
				printf("Nome #2: "); scanf("%s", nome2);
				break;
			case 2:
				player[0] = new Human(0, Nrows, Ncols);
				player[1] = new Bot(1, Nrows, Ncols);
				printf("Nome #1: "); scanf("%s", nome1);
				strcpy(nome2, "Bot");
				break;
			case 3:
				player[0] = new Bot(0, Nrows, Ncols);
				player[1] = new Human(1, Nrows, Ncols);
				strcpy(nome1, "Bot");
				printf("Nome #2: "); scanf("%s", nome2);
				break;
			case 4:
				player[0] = new Bot(0, Nrows, Ncols);
				player[1] = new Bot(1, Nrows, Ncols);
				strcpy(nome1, "Bot #1");
				strcpy(nome2, "Bot #2");
				break;
			case 5:
				return;
		}
		
		nPieces = 0;
		grid = Grid(Nrows, Ncols, nome1, nome2);
		printf("meh\n"); fflush(stdout);
		do {
			turn = 1 - turn;
			grid.printTable(turn);
			grid.makeMove(player[turn]->getMove(grid.piece), turn, 1);
			nPieces++;
		} while (!finished(grid, turn));
		grid.printTable(turn);
		
		if (!grid.won(turn, 0)) {
			puts("It's a tie\n");
		} else {
			if (turn == 0)
				printf(BLU "%s won!\n\n" RESET, nome1);
			else
				printf(YEL "%s won!\n\n" RESET, nome2);
		}
	}
}
