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
	int optionChoosen;
	
	while (true) {
		startMessage();
		srand(time(NULL));
		scanf("%d", &optionChoosen);
		while (optionChoosen < 1 or optionChoosen > 5) {
			startMessage();
			printf("Invalid option. Choose a number in the range [1,4]: ");
			scanf("%d", &optionChoosen);
		}
		
		switch (optionChoosen) {
			case 1:
				player1 = new Human(Nrows, Ncols);
				player2 = new Human(Nrows, Ncols);
				break;
			case 2:
				player1 = new Human(Nrows, Ncols);
				player2 = new Bot(Nrows, Ncols);
				break;
			case 3:
				player1 = new Bot(Nrows, Ncols);
				player2 = new Human(Nrows, Ncols);
				break;
			case 4:
				player1 = new Bot(Nrows, Ncols);
				player2 = new Bot(Nrows, Ncols);
				break;
			case 5:
				return;
		}
		
		nPieces = 0;
		grid = Grid(Nrows, Ncols);
		do {
			grid.printTable(turn);
			if (turn == 0) {
				grid.makeMove(player1->getMove(grid.piece), turn);
			} else {
				grid.makeMove(player2->getMove(grid.piece), turn);
			}
			nPieces++;
			turn = 1 - turn;
		} while (!finished(grid));
		grid.printTable(turn);
		
		if (nPieces == Nrows*Ncols) {
			puts("It's a tie\n");
		} else {	
			// for (int i = 0; i < )
			printf("Player %d won!\n\n", 2-turn);
		}
	}
}