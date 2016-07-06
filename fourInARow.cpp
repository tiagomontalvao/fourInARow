#include "fourInARow.h"

FourInARow::FourInARow () {
	nPieces = 0;
	turn = 0;
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

bool FourInARow::finished(Grid& grid) {
	return (grid.won() or nPieces == Nrows*Ncols);
}

void FourInARow::startGame() {
	srand(time(NULL));
	int optionChoosen;
	
	while (true) {
		startMessage();
		scanf("%d", &optionChoosen);
		while (optionChoosen < 1 or optionChoosen > 5) {
			startMessage();
			printf("Invalid option. Choose a number in the range [1,4]: ");
			scanf("%d", &optionChoosen);
		}
		
		scanf("%*c");
		switch (optionChoosen) {
			case 1:
				player1 = new Human(Nrows, Ncols);
				player2 = new Human(Nrows, Ncols);
				printf("Nome #1: "); scanf("%s", nome1);
				printf("Nome #2: "); scanf("%s", nome2);
				break;
			case 2:
				player1 = new Human(Nrows, Ncols);
				player2 = new Bot(Nrows, Ncols);
				printf("Nome #1: "); scanf("%s", nome1);
				strcpy(nome2, "Bot");
				break;
			case 3:
				player1 = new Bot(Nrows, Ncols);
				player2 = new Human(Nrows, Ncols);
				strcpy(nome1, "Bot");
				printf("Nome #2: "); scanf("%s", nome2);
				break;
			case 4:
				player1 = new Bot(Nrows, Ncols);
				player2 = new Bot(Nrows, Ncols);
				strcpy(nome1, "Bot #1");
				strcpy(nome2, "Bot #2");
				break;
			case 5:
				return;
		}
		
		nPieces = 0;
		grid = Grid(Nrows, Ncols);
		do {
			turn = 1 - turn;
			grid.printTable(turn, nome1, nome2);
			if (turn == 0) {
				grid.makeMove(player1->getMove(grid.piece), turn, nome1, nome2);
			} else {
				grid.makeMove(player2->getMove(grid.piece), turn, nome1, nome2);
			}
			nPieces++;
		} while (!finished(grid));
		grid.printTable(turn, nome1, nome2);
		
		if (!grid.won()) {
			puts("It's a tie\n");
		} else {	
			if (turn == 0)
				printf(BLU "%s won!\n\n" RESET, nome1);
			else
				printf(YEL "%s won!\n\n" RESET, nome2);
		}
	}
}