#include "Board.h"
#include "Assess-Defines.h"

int Board::assess() {
	
//	if (!chessmen[WHITE_][0].enabled) return -_INFINITY_;
//	if (!chessmen[BLACK_][1].enabled) return _INFINITY_;

	int res = 0;

	for (auto i : chessmen[0]) {
		if (i.enabled){
			res += value_of_chessman[i.id];
			switch (i.id) {
			case PAWN:
				res += white_pawn_assess[i.x]; break;
			case KNIGHT:
				res += knight_assess[i.x]; break;
			case BISHOP:
				res += bishop_assess[i.x]; break;
			case ROOK: {
				int8_t x = i.x - chessmen[BLACK_][0].x;
				res += rook_assess[check_coord(x)];
				break;
			}
			case QUEEN: {
				int8_t x = i.x - chessmen[1][0].x;
				res += queen_assess[check_coord(x)];
				break;
			}
			case KING:
				if (isEndgame())
					res += late_king_assess[i.x];
				else
					res += early_king_assess[i.x];
				break;
			}
		}
	}

	for (auto i : chessmen[1]) {
		if (i.enabled) {
			res -= value_of_chessman[i.id];
			switch (i.id) {
			case PAWN:
				res -= black_pawn_assess[i.x]; break;
			case KNIGHT:
				res -= knight_assess[i.x]; break;
			case BISHOP:
				res -= bishop_assess[i.x]; break;
			case ROOK: {
				int8_t x = i.x - chessmen[WHITE_][0].x;
				res -= rook_assess[check_coord(x)];
				break;
			}
			case QUEEN: {
				int8_t x = i.x - chessmen[WHITE_][0].x;
				res -= queen_assess[check_coord(x)];
				break;
			}
			case KING:
				if (isEndgame())
					res -= late_king_assess[i.x];
				else
					res -= early_king_assess[i.x];
				break;
			}
		}
	}

	return color_turn*res;
}