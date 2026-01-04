#include "Turn.h"

#include <iostream>

void Board::Turn::operator()() {
	switch (castling) {
	case SHORT_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[116] = VOID;
			board->board[118] = KING;
			board->board[119] = VOID;
			board->board[117] = ROOK;
			board->chessmen[0][0].x += 2;
			board->chessmen[0][3].x -= 2;
			board->zobrist = board->zobrist xor KEY[KING - 1][WHITE_][116] xor KEY[KING - 1][WHITE_][118]
				xor KEY[ROOK - 1][WHITE_][119] xor KEY[ROOK - 1][WHITE_][117];
			board->history.push_front(board->zobrist);
			board->last_moving_chessman_coord = UNDEFINED;
		}
		else {
			board->board[4] = VOID;
			board->board[6] = BLACK * KING;
			board->board[7] = VOID;
			board->board[5] = BLACK * ROOK;
			board->chessmen[1][0].x += 2;
			board->chessmen[1][3].x -= 2;
			board->zobrist = board->zobrist xor KEY[KING - 1][BLACK_][4] xor KEY[KING - 1][BLACK_][6]
				xor KEY[ROOK - 1][BLACK_][7] xor KEY[ROOK - 1][BLACK_][5];
			board->history.push_front(board->zobrist);
			board->last_moving_chessman_coord = UNDEFINED;
		}
		break;
	case LONG_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[116] = VOID;
			board->board[114] = KING;
			board->board[112] = VOID;
			board->board[115] = ROOK;
			board->chessmen[0][0].x -= 2;
			board->chessmen[0][2].x += 3;
			board->zobrist = board->zobrist xor KEY[KING - 1][WHITE_][116] xor KEY[KING - 1][WHITE_][114]
				xor KEY[ROOK - 1][WHITE_][112] xor KEY[ROOK - 1][WHITE_][115];
			board->history.push_front(board->zobrist);
			board->last_moving_chessman_coord = UNDEFINED;
		}
		else {
			board->board[4] = VOID;
			board->board[2] = BLACK * KING;
			board->board[0] = VOID;
			board->board[3] = BLACK * KING;
			board->chessmen[1][0].x -= 2;
			board->chessmen[1][2].x += 3;
			board->zobrist = board->zobrist xor KEY[KING - 1][BLACK_][4] xor KEY[KING - 1][BLACK_][2]
				xor KEY[ROOK - 1][BLACK_][0] xor KEY[ROOK - 1][BLACK_][3];
			board->history.push_front(board->zobrist);
			board->last_moving_chessman_coord = UNDEFINED;
		}
		break;
	default:

		board->board[x_start] = VOID;
		board->zobrist = board->zobrist xor KEY[moved_chessman->id - 1][same(board->color_turn)][x_start];
		moved_chessman->x = x_finish;
		before_moved_chessman_coord = board->last_moving_chessman_coord;
		board->last_moving_chessman_coord = x_finish;
		if (promotion != VOID) {
			moved_chessman->id = promotion;
		}
		if (eaten_chessman != nullptr) {
			board->board[eaten_chessman->x] = VOID;
			eaten_chessman->enabled = false;
			if (eaten_chessman->id == PAWN) board->pawns[invert(board->color_turn)]--;
			else board->pieces[invert(board->color_turn)]--;
			board->zobrist = board->zobrist 
				xor KEY[eaten_chessman->id - 1][invert(board->color_turn)][eaten_chessman->x];
		}
		board->board[x_finish] = (board->color_turn * moved_chessman->id);
		board->zobrist = board->zobrist xor KEY[moved_chessman->id - 1][same(board->color_turn)][x_finish];
		board->history.push_front(board->zobrist);
	}
	board->en_passant = en_passant;
	board->color_turn *= -1;
}

void Board::Turn::unmake() {
	board->color_turn *= -1;
	board->en_passant = before_en_passant;

	switch (castling) {
	case SHORT_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[119] = ROOK_NM;
			board->board[118] = VOID;
			board->board[116] = KING_NM;
			board->board[117] = VOID;
			board->chessmen[0][0].x -= 2;
			board->chessmen[0][3].x += 2;
			board->zobrist = board->zobrist xor KEY[KING - 1][WHITE_][116] xor KEY[KING - 1][WHITE_][118]
				xor KEY[ROOK - 1][WHITE_][117] xor KEY[ROOK - 1][WHITE_][119];
			board->history.pop_front();
		}
		else {
			board->board[7] = BLACK * ROOK_NM;
			board->board[6] = VOID;
			board->board[4] = BLACK * KING_NM;
			board->board[5] = VOID;
			board->chessmen[1][0].x -= 2;
			board->chessmen[1][3].x += 2;
			board->zobrist = board->zobrist xor KEY[KING - 1][BLACK_][4] xor KEY[KING - 1][BLACK_][6]
				xor KEY[ROOK - 1][BLACK_][7] xor KEY[ROOK - 1][BLACK_][5];
			board->history.pop_front();
		}
		break;
	case LONG_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[116] = KING_NM;
			board->board[114] = VOID;
			board->board[112] = ROOK_NM;
			board->board[115] = VOID;
			board->chessmen[0][0].x += 2;
			board->chessmen[0][2].x -= 3;
			board->zobrist = board->zobrist xor KEY[KING - 1][WHITE_][116] xor KEY[KING - 1][WHITE_][114]
				xor KEY[ROOK - 1][WHITE_][112] xor KEY[ROOK - 1][WHITE_][115];
			board->history.pop_front();
		}
		else {
			board->board[4] = BLACK * KING_NM;
			board->board[2] = VOID;
			board->board[0] = BLACK * ROOK_NM;
			board->board[3] = VOID;
			board->chessmen[1][0].x += 2;
			board->chessmen[1][2].x -= 3;
			board->zobrist = board->zobrist xor KEY[KING - 1][BLACK_][4] xor KEY[KING - 1][BLACK_][2]
				xor KEY[ROOK - 1][BLACK_][0] xor KEY[ROOK - 1][BLACK_][3];
			board->history.pop_front();
		}
		break;
	default:

		board->zobrist = board->zobrist xor KEY[moved_chessman->id - 1][same(board->color_turn)][x_finish];
		if (promotion != VOID) {
			moved_chessman->id = PAWN;
		}
		board->board[x_start] = moved_chessman_id;
		moved_chessman->x = x_start;
		board->last_moving_chessman_coord = before_moved_chessman_coord;
		if (eaten_chessman != nullptr) {
			board->board[eaten_chessman->x] = (int8_t)(-board->color_turn * eaten_chessman->id);
			eaten_chessman->enabled = true;
			if (eaten_chessman->id == PAWN) board->pawns[same(board->color_turn)]++;
			else board->pieces[same(board->color_turn)]++;
			board->zobrist = board->zobrist
				xor KEY[eaten_chessman->id - 1][invert(board->color_turn)][eaten_chessman->x];
		}
		board->board[x_finish] = finish_id;
		board->zobrist = board->zobrist xor KEY[moved_chessman->id - 1][same(board->color_turn)][x_start];
		board->history.pop_front();
	}
}