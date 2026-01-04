#pragma once
#include "Board.h"

class Board::Turn {
private:
	uint8_t moved_chessman_id = 0;
	uint8_t x_start = 0;
	uint8_t x_finish = 0;
	uint8_t finish_id = 0;

	Chessman* moved_chessman = nullptr;
	Chessman* eaten_chessman = nullptr;

	uint8_t castling = UNDEFINED;
	uint8_t en_passant = UNDEFINED;
	uint8_t before_en_passant = UNDEFINED;
	uint8_t before_moved_chessman_coord = UNDEFINED;
	int8_t promotion = VOID;
	int estimate_difference = 0;

	Board* board = nullptr;

	Chessman* findEatenChessman(uint8_t id, uint8_t x);

public:
	Turn(std::string turn, Board* _board);
	
	Turn(Chessman* _moved_chessman, uint8_t x_st, uint8_t x_fn, Board* _board);

	Turn(Chessman* _moved_chessman, uint8_t x_st, uint8_t x_fn, int8_t _promotion, Board* _board);

	Turn(uint8_t _castling, Board* _board);

	void operator()();

	void unmake();

	bool isCheck();

	uint8_t eaten_coord() {
		if (eaten_chessman != nullptr)
			return eaten_chessman->x;
		else return UNDEFINED;  //nothing was eaten
	}

	std::string name(); 

	bool operator < (const Turn &turn);

	friend int main();
};
