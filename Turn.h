#pragma once
#include "Board.h"

class Board::Turn {
private:
	char moved_chessman_id = 0;
	char x_start = 0;
	char y_start = 0;
	char x_finish = 0;
	char y_finish = 0;
	char finish_id = 0;

	Chessman* moved_chessman = nullptr;
	Chessman* eaten_chessman = nullptr;

	char castling = 0;
	char en_passant = -1;
	char before_en_passant = -1;
	unsigned short before_moved_chessman_coords = 0;
	char promotion = 0;
	char estimate_difference = 0;

	Board* board = nullptr;

	Chessman* findEatenChessman(char id, char x, char y);

public:
	Turn(std::string turn, Board* _board);
	
	Turn(Chessman* _moved_chessman, char x_st, char y_st, char x_fn, char y_fn, Board* _board);

	Turn(Chessman* _moved_chessman, char x_st, char y_st, char x_fn, char y_fn, char _promotion, Board* _board);

	Turn(char _castling, Board* _board);

	void operator()();

	void unmake();

	bool isCheck();

	unsigned short eaten_coords() {
		if (eaten_chessman != nullptr)
			return coords(eaten_chessman->x, eaten_chessman->y);
		else return 10000;  //nothing was eaten
	}

	std::string name(); 

	bool operator < (const Turn &turn);

	friend int main();
};
