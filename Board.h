#pragma once
#include <vector>
#include <deque>
#include "Chessman.h"
#include "ZObrist-Defines.h"

class Board {
private:
	bool subcheck(char x, char y, char kings_x, char kings_y);
	
public:
	std::vector<char> board; //board[144]

	std::vector<Chessman> chessmen[2];
	char pawns[2], pieces[2]; //pieces without kings and promoted pawns

	unsigned __int64 zobrist;
	std::deque<unsigned __int64> history;

	char color_turn;
	char en_passant;

	unsigned short last_moving_chessman_coords = 0;

	void printTest();

	bool check(const Chessman* checking_chessman, char checking_x, char checking_y);
	bool supercheck(char checking_x, char checking_y);
	
	bool isEndgame();

	int assess();

	Board(std::vector<char> _board, std::vector<Chessman> white, std::vector<Chessman> black, char color, char en_passant);

	class Turn;
};