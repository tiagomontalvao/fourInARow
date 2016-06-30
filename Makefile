all: Makefile fourInARow.cpp grid.cpp player.cpp bot.cpp
	g++ -std=c++11 -Wall -Werror -Wformat=0 -Wno-unused-but-set-variable -o fourInARow fourInARow.cpp grid.cpp player.cpp bot.cpp

clean:
	rm -f *.o fourInARow