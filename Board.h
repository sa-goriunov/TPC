#pragma once
#include <vector>
#include <deque>
#include <string>
#include "Chessman.h"
#include "ZObrist-Defines.h"

class Board {
private:
	std::vector<char> board; //board[144]

	std::vector<Chessman> chessmen[2];

	unsigned __int64 zobrist;
	std::deque<unsigned __int64> history;
	char color_turn;

	Board(std::vector<char> _board, std::vector<Chessman> white, std::vector<Chessman> black, char color);

public:
	void printTest();

	class Turn;
	class GenerateMoves;
	class GenerateForcedMoves;

	friend class Game;
	friend bool check(const Chessman* checking_chessman, char checking_x, char checking_y, 
										char color_of_checking_party, const Board* board);
	friend bool subcheck(char x, char y, char kings_x, char kings_y, const Board* board);
	friend bool supercheck(char checking_x, char checking_y, char color_of_checking_party, Board* board);
	friend int main();
};