#pragma once
#include "Game.h"

class Game::GenerateMoves {
private:
	std::vector<Board::Turn> turns;

	Board *board;
	friend int main();
public:
	void operator()();

	void pick(int iteration);

	GenerateMoves(Board *_board) {
		board = _board;
	}
};

class Game::GenerateForcedMoves {
private:
	std::vector<Board::Turn> turns;

	Board *board;
	friend int main();
public:
	void pick(int iteration);

	void operator()();

	GenerateForcedMoves(Board *_board) {
		board = _board;
	}
};