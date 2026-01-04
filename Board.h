#pragma once
#include <vector>
#include <deque>
#include "Chessman.h"
#include "ZObrist-Defines.h"

class Board {
private:
	bool subcheck(uint8_t x, uint8_t kings_x);
	
public:
	std::vector<int8_t> board; //board[144]

	std::vector<Chessman> chessmen[2];
	uint8_t pawns[2], pieces[2]; //pieces without kings and promoted pawns

	unsigned __int64 zobrist;
	std::deque<unsigned __int64> history;

	int8_t color_turn;
	uint8_t en_passant = UNDEFINED;

	uint8_t last_moving_chessman_coord = UNDEFINED;

	void printTest();

	bool check(const Chessman* checking_chessman, uint8_t checking_x);
	bool supercheck(uint8_t checking_x);
	
	bool isEndgame();

	int assess();

	Board(std::vector<int8_t> _board, std::vector<Chessman> white, std::vector<Chessman> black, int8_t color, uint8_t en_passant);

	class Turn;
};