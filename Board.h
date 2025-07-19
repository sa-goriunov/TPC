#pragma once
#include <vector>
#include <deque>
#include "Chessman.h"
#include "ZObrist-Defines.h"

class Board {
public:
	std::vector<char> board; //board[144]

	std::vector<Chessman> chessmen[2];

	unsigned __int64 zobrist;
	std::deque<unsigned __int64> history; // ????

	char color_turn;
	char en_passant;

	unsigned short last_moving_chessman_coords = 0; //not really usefull information. Its only use is in sorting moves for GenerateMoves

	void printTest();

	Board(std::vector<char> _board, std::vector<Chessman> white, std::vector<Chessman> black, char color, char en_passant);

	class Turn;
};