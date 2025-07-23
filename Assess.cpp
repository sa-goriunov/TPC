#include "Board.h"
#include "Assess-Defines.h"

int Board::assess() {
	
	if (!chessmen[WHITE_][0].enabled) return -_INFINITY_;
	if (!chessmen[BLACK_][1].enabled) return _INFINITY_;

	int res = 0;

	for (auto i : chessmen[0]) {
		if (i.enabled){
			res += value_of_chessman[i.id - 1];
			switch (i.id) {
			case PAWN:
				res += white_pawn_assess[estimate_coords(i.x, i.y)]; break;
			case KNIGHT:
				res += knight_assess[estimate_coords(i.x, i.y)]; break;
			case BISHOP:
				res += bishop_assess[estimate_coords(i.x, i.y)]; break;
			case ROOK: {
				char x = i.x - chessmen[BLACK_][0].x;
				char y = i.y - chessmen[BLACK_][0].y;
				res += rook_assess[check_coords(x, y)];
				break;
			}
			case QUEEN: {
				char x = i.x - chessmen[1][0].x;
				char y = i.y - chessmen[1][0].y;
				res += queen_assess[check_coords(x, y)];
				break;
			}
			case KING:
				if (isEndgame())
					res += late_king_assess[estimate_coords(i.x, i.y)];
				else
					res += early_king_assess[estimate_coords(i.x, i.y)];
				break;
			}
		}
	}

	for (auto i : chessmen[1]) {
		if (i.enabled) {
			res -= value_of_chessman[i.id - 1];
			switch (i.id) {
			case PAWN:
				res -= black_pawn_assess[estimate_coords(i.x, i.y)]; break;
			case KNIGHT:
				res -= knight_assess[estimate_coords(i.x, i.y)]; break;
			case BISHOP:
				res -= bishop_assess[estimate_coords(i.x, i.y)]; break;
			case ROOK: {
				char x = i.x - chessmen[WHITE_][0].x;
				char y = i.y - chessmen[WHITE_][0].y;
				res -= rook_assess[check_coords(x, y)];
				break;
			}
			case QUEEN: {
				char x = i.x - chessmen[WHITE_][0].x;
				char y = i.y - chessmen[WHITE_][0].y;
				res -= queen_assess[check_coords(x, y)];
				break;
			}
			case KING:
				if (isEndgame())
					res -= late_king_assess[estimate_coords(i.x, i.y)];
				else
					res -= early_king_assess[estimate_coords(i.x, i.y)];
				break;
			}
		}
	}

	return color_turn*res;
}