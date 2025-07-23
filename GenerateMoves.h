#pragma once
#include "Game.h"

class Game::GenerateMoves {
private:
	Board *board;
	friend int main();
public:
	void operator()();

	std::vector<Board::Turn> turns;

	void pick(int iteration);

	GenerateMoves(Board *_board) {
		board = _board;
	}
};

class Game::GenerateForcedMoves {
private:
	

	Board *board;
	friend int main();
public:
	void pick(int iteration);

	std::vector<Board::Turn> turns;

	void operator()();

	GenerateForcedMoves(Board *_board) {
		board = _board;
	
	}
};