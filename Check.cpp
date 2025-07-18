#include "Board.h"

bool subcheck(char x, char y, char kings_x, char kings_y, const Board* board) {
	char dx, dy;
	if (x != kings_x) { dx = (x - kings_x) / abs(x - kings_x); }
	else { dx = 0; }
	if (y != kings_y) { dy = (y - kings_y) / abs(y - kings_y); }
	else { dy = 0; }

	bool tmp = true;
	for (int i = 1; i < std::max(abs(x - kings_x), abs(y - kings_y)); i++) {
		tmp = tmp && (board->board[coords(kings_x + i * dx, kings_y + i * dy)] == VOID);
		if (not(tmp)) return tmp;
	}

	return tmp;
}

bool check(const Chessman* checking_chessman, char checking_x, char checking_y, char color_of_checking_party, const Board* board) {
	char x = checking_chessman->x - checking_x;
	char y = checking_chessman->y - checking_y;

	switch (checking_chessman->id) {

	case PAWN: if (color_of_checking_party == WHITE) {
		return WHITE_PAWN_CHECK[check_coords(x, y)];
	}
			 else {
		return BLACK_PAWN_CHECK[check_coords(x, y)];
	}

	case KNIGHT: return KNIGHT_CHECK[check_coords(x, y)];

	case BISHOP: if (BISHOP_CHECK[check_coords(x, y)]) {
		return subcheck(checking_chessman->x, checking_chessman->y, checking_x, checking_y, board);
	}

	case ROOK: if (ROOK_CHECK[check_coords(x, y)]) {
		return subcheck(checking_chessman->x, checking_chessman->y, checking_x, checking_y, board);
	}

	case QUEEN: if (QUEEN_CHECK[check_coords(x, y)]) {
		return subcheck(checking_chessman->x, checking_chessman->y, checking_x, checking_y, board);
	}

	case KING: return KING_CHECK[check_coords(x, y)];

	default: return false;
	}
}

bool supercheck(char checking_x, char checking_y, char color_of_checking_party, Board* board) {
	bool res = false;
	for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
		if (res) { break; }
		else {
			Chessman* tmp = &board->chessmen[same(color_of_checking_party)][i];
			res = tmp->enabled && check(tmp, checking_x, checking_y, color_of_checking_party, board); 
	}
	}
	return res;
}