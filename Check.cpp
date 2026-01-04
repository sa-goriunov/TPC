#include "Board.h"

bool Board::subcheck(uint8_t x, uint8_t checking_x) {
	int8_t X = abs((int8_t)checking_x - (int8_t)x), dx;
	if (X < 8) dx = 1;
	else
		if (X % 16 == 0) dx = 16;
		else if (X % 16 > 8) dx = 15;
		else dx = 17;
	dx *= (uint8_t)((int8_t)(checking_x - x) / X);

	bool tmp = true;
	for (int i = 1; i < abs(X / dx); i++) {
		tmp = tmp && (board[x + i * dx] == VOID);
		if (not(tmp)) return tmp;
	}

	return tmp;
}

bool Board::check(const Chessman* checking_chessman, uint8_t checking_x) {
	int8_t x = checking_chessman->x - checking_x;

	switch (checking_chessman->id) {

	case PAWN: if (color_turn == BLACK) {
				  return WHITE_PAWN_CHECK[check_coord(x)];
				}
			   else {
				  return BLACK_PAWN_CHECK[check_coord(x)];
				}

	case KNIGHT: return KNIGHT_CHECK[check_coord(x)];

	case BISHOP: if (BISHOP_CHECK[check_coord(x)]) {
		return subcheck(checking_chessman->x, checking_x);
	}	else return false;

	case ROOK: if (ROOK_CHECK[check_coord(x)]) {
		return subcheck(checking_chessman->x, checking_x);
	}	else return false;

	case QUEEN: if (QUEEN_CHECK[check_coord(x)]) {
		return subcheck(checking_chessman->x, checking_x);
	}	else return false;

	case KING: return KING_CHECK[check_coord(x)];

	default: return false;
	}
}

bool Board::supercheck(uint8_t checking_x) {
	bool res = false;
	for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
		if (res) { break; }
		else {
			Chessman *tmp = &chessmen[invert(color_turn)][i];
			res = tmp->enabled && check(tmp, checking_x); 
	}
	}
	return res;
}