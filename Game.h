#pragma once
#include <vector>
#include <string>
#include "Turn.h"

class Board;

class Game {
private:
	friend int main();

	Board *__board__;

	class GenerateMoves;
	class GenerateForcedMoves;
public:

	Game(); //standart game

	~Game();

	std::string play(std::string opponents_turn);
};