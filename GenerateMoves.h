#pragma once
#include "Turn.h"

class Board::GenerateMoves {
private:
	std::vector<Turn> turns;

	void operator()(Board *board, char en_passant);

	//~GenerateMoves();

	friend int main();
};

class Board::GenerateForcedMoves {
private:
	std::vector<Turn> turns;

	void operator()(Board* board);
};