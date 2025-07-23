#include "Board.h"

bool Board::subcheck(char x, char y, char checking_x, char checking_y) {
	char dx, dy;
	if (x != checking_x) { dx = (x - checking_x) / abs(x - checking_x); }
	else { dx = 0; }
	if (y != checking_y) { dy = (y - checking_y) / abs(y - checking_y); }
	else { dy = 0; }

	bool tmp = true;
	for (int i = 1; i < std::max(abs(x - checking_x), abs(y - checking_y)); i++) {
		tmp = tmp && (board[coords(checking_x + i * dx, checking_y + i * dy)] == VOID);
		if (not(tmp)) return tmp;
	}

	return tmp;
}

bool Board::check(const Chessman* checking_chessman, char checking_x, char checking_y) {
	char x = checking_chessman->x - checking_x;
	char y = checking_chessman->y - checking_y;

	switch (checking_chessman->id) {

	case PAWN: if (color_turn == BLACK) {
				  return WHITE_PAWN_CHECK[check_coords(x, y)];
				}
			   else {
				  return BLACK_PAWN_CHECK[check_coords(x, y)];
				}

	case KNIGHT: return KNIGHT_CHECK[check_coords(x, y)];

	case BISHOP: if (BISHOP_CHECK[check_coords(x, y)]) {
		return subcheck(checking_chessman->x, checking_chessman->y, checking_x, checking_y);
	}

	case ROOK: if (ROOK_CHECK[check_coords(x, y)]) {
		return subcheck(checking_chessman->x, checking_chessman->y, checking_x, checking_y);
	}

	case QUEEN: if (QUEEN_CHECK[check_coords(x, y)]) {
		return subcheck(checking_chessman->x, checking_chessman->y, checking_x, checking_y);
	}

	case KING: return KING_CHECK[check_coords(x, y)];

	default: return false;
	}
}

bool Board::supercheck(char checking_x, char checking_y) {
	bool res = false;
	for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
		if (res) { break; }
		else {
			Chessman *tmp = &chessmen[invert(color_turn)][i];
			res = tmp->enabled && check(tmp, checking_x, checking_y); 
	}
	}
	return res;
}