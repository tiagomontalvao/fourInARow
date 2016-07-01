#include "fourInARow.h"

FourInARow::FourInARow () {
	turn = 0;
}
FourInARow::FourInARow (int _turn) {
	turn = _turn;
}

void FourInARow::startMessage() {
	system("clear");
	puts("Choose one:");
	puts("(1): Human vs Human");
	puts("(2): Human vs Bot");
	puts("(3): Bot vs Human");
	puts("(4): Bot vs Bot");
	puts("(5): Exit");
}


void FourInARow::startGame() {
	int optionChoosen;
	
	startMessage();
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
	
	grid = Grid(Nrows, Ncols);
	do {
		grid.printTable();
		if (turn == 0) {
			grid.makeMove(player1->getMove(grid.piece), turn);
		} else {
			grid.makeMove(player2->getMove(grid.piece), turn);
		}
	} while (!grid.won());
	grid.printTable();
	printf("You %s!\n", turn ? "won" : "lost");

}