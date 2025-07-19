#pragma once
#include "Game.h"

class Game::GenerateMoves {
private:
	std::vector<Board::Turn> turns;

	void sortMoves(Board *board);

	friend int main();
public:
	void operator()(Board *board);
	
};

class Game::GenerateForcedMoves {
private:
	std::vector<Board::Turn> turns;

public:
	void operator()(Board *board);
};