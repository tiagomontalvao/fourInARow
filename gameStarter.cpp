#include "bot.h"
#include "human.h"
#include "player.h"
#include "grid.h"
#include "fourInARow.h"

int main() {
	srand(time(NULL));
	FourInARow game;
	game.startGame();
	return 0;
}
