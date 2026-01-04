#pragma once
#include <vector>
#include <string>
#include "Turn.h"

class Game {
private:
	friend int main();

	Board *__board__;

	int DEPTH = 6, MAX_DEPTH = 10;

	int8_t my_color;
	std::vector<Board::Turn> history;

	class GenerateMoves;
	class GenerateForcedMoves;

	int NegaScout(int alpha, int beta, int depth, int ply, Board *board);

	int forcedSearch(int alpha, int beta, int ply, Board *board);
public:

	Game(); //standart game

	//Game(int a);

	~Game();

	std::string play(std::string opponents_turn);

	void setColor(int8_t color) {
		my_color = color;
	}

	void setDepth(int depth) {
		DEPTH = depth;
	}

	void setMaxDepth(int max_depth) {
		MAX_DEPTH = max_depth;
	}
};