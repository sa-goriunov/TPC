#include "Sort-Defines.h"
#include "Turn.h"
#include <string>

Board::Turn::Turn(std::string turn, Board* _board) {
	board = _board;
	before_en_passant = _board->en_passant;
	if ((turn == "O-O") || (turn == "o-o") || (turn == "0-0")) castling = SHORT_CASTLING;
	else if ((turn == "O-O-O") || (turn == "o-o-o") || (turn == "0-0-0")) castling = LONG_CASTLING;
	else {
		x_start = (turn[0] - 'a') + 16*('8' - turn[1]);
		x_finish = (turn[2] - 'a') + 16*('8' - turn[3]);

		int color = same(board->color_turn);
		for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
			Chessman *tmp = &board->chessmen[color][i];
			if ((tmp->x == x_start) && (tmp->enabled)) {
				moved_chessman = tmp; break;
			}}

		moved_chessman_id = board->board[x_start];
		finish_id = board->board[x_finish];

		if(moved_chessman->id == PAWN){
			if (((x_start >= 96) && (x_finish <= 71) && (x_finish >= 64)) || ((x_start <= 23) && (x_finish <= 55) && (x_finish >= 48))) { en_passant = x_finish; }
			else if ((x_finish >= 112) || (x_finish <= 7)) {
					switch (turn[4]) {
					case 'Q': promotion = QUEEN; break;
					case 'q': promotion = QUEEN; break;
					case 'R': promotion = ROOK; break;
					case 'r': promotion = ROOK; break;
					case 'B': promotion = BISHOP; break;
					case 'b': promotion = BISHOP; break;
					case 'N': promotion = KNIGHT; break;
					case 'n': promotion = KNIGHT; break;
					default: promotion = VOID;
					}
		}}

		eaten_chessman = findEatenChessman(finish_id, x_finish);

	}
}

Board::Turn::Turn(Chessman* _moved_chessman, uint8_t x_st, uint8_t x_fn, Board* _board) {
	board = _board;
	moved_chessman = _moved_chessman;
	moved_chessman_id = board->board[x_st];
	x_start = x_st;
	x_finish = x_fn;

	finish_id = board->board[x_finish];

	if ((moved_chessman->id == PAWN) &&
		(((x_start >= 96) && (x_finish <= 71) && (x_finish >= 64)) || ((x_start <= 23) && (x_finish <= 55) && (x_finish >= 48))))
	{ en_passant = x_finish; }

	before_en_passant = _board->en_passant;

	eaten_chessman = findEatenChessman(finish_id, x_finish);

	if(eaten_chessman == nullptr){
		switch (moved_chessman->id) {
		case PAWN:
			if (board->color_turn == WHITE)
				estimate_difference = white_pawn_estimate[x_fn] - white_pawn_estimate[x_st];
			else
				estimate_difference = black_pawn_estimate[x_fn] - black_pawn_estimate[x_st];
			break;
		case KNIGHT:
			estimate_difference = knight_estimate[x_fn] - knight_estimate[x_st];
			break;
		case BISHOP:
			estimate_difference = bishop_estimate[x_fn] - bishop_estimate[x_st];
			break;
		case ROOK: {
			uint8_t opponents_kings_x = board->chessmen[invert(board->color_turn)][0].x;
			uint8_t x1 = x_st - opponents_kings_x;
			uint8_t x2 = x_fn - opponents_kings_x;
			estimate_difference = rook_estimate[check_coord(x2)] - rook_estimate[check_coord(x1)];
			break;}
		case QUEEN: {
			uint8_t opponents_kings_x = board->chessmen[invert(board->color_turn)][0].x;
			uint8_t x1 = x_st - opponents_kings_x;
			uint8_t x2 = x_fn - opponents_kings_x;
			estimate_difference = queen_estimate[check_coord(x2)] - queen_estimate[check_coord(x1)];
			break;}
		case KING:
			if(board->isEndgame())
				estimate_difference = late_king_estimate[x_fn] - late_king_estimate[x_st];
			else
				estimate_difference = early_king_estimate[x_fn] - early_king_estimate[x_st];
			break;
		default: estimate_difference = 0;
		}
	}
	else {
		estimate_difference = eaten_chessman->id - moved_chessman->id;
	}
}

Board::Turn::Turn(Chessman* _moved_chessman, uint8_t x_st, uint8_t x_fn, int8_t _promotion, Board* _board) {
	board = _board;
	moved_chessman = _moved_chessman;
	moved_chessman_id = board->board[x_st];
	x_start = x_st;
	x_finish = x_fn;
	before_en_passant = _board->en_passant;
	promotion = _promotion;

	finish_id = board->board[x_finish];

	eaten_chessman = findEatenChessman(finish_id, x_finish);
	
	estimate_difference = _promotion;
}

Board::Turn::Turn(uint8_t _castling, Board* _board) {
	board = _board;
	castling = _castling;
	before_en_passant = _board->en_passant;

	switch (castling) {
	case SHORT_CASTLING: estimate_difference = 20; break;
	case LONG_CASTLING: estimate_difference = 15; break;
	default: estimate_difference = 0;
	}
}

Chessman* Board::Turn::findEatenChessman(uint8_t id, uint8_t x) {
	char color = invert(board->color_turn);
	if (id != VOID) {
		for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
			Chessman* tmp = &board->chessmen[color][i];
			if ((tmp->x == x_finish) && (tmp->enabled)) {
				return tmp;
			}}
	} else if ((moved_chessman->id == PAWN) && (abs(x_start - before_en_passant) == 1) && (abs(x_finish - before_en_passant) == 16)) {
		for (int i = 8; i < NUMBER_OF_CHESSMEN; i++) {
			Chessman* tmp = &board->chessmen[color][i];
			if ((abs(x_finish - tmp->x) == 16) && (tmp->enabled)) {
				return tmp;
			}}
	}
	else { return nullptr; }

	return nullptr;
}

const std::string names[] =
{  "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",	"", "", "", "", "", "", "", "",
   "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",	"", "", "", "", "", "", "", "",
   "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",	"", "", "", "", "", "", "", "",
   "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",	"", "", "", "", "", "", "", "",
   "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",	"", "", "", "", "", "", "", "",
   "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",	"", "", "", "", "", "", "", "",
   "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",	"", "", "", "", "", "", "", "",
   "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",	"", "", "", "", "", "", "", "" };

std::string Board::Turn::name() {
	std::string name = "";

	switch (castling) {
	case 1: name = "O-O"; break;
	case 2: name = "O-O-O"; break;
	default:
		switch (moved_chessman->id) {
		case 1: name += "P"; break;
		case 2: name += "N"; break;
		case 3: name += "B"; break;
		case 4: name += "R"; break;
		case 5: name += "Q"; break;
		case 6: name += "K"; break;
		}

		name += names[x_start];
		name += names[x_finish];

		switch (promotion) {
		case VOID: break;
		case QUEEN:  name += 'Q'; name[0] = 'P'; break;
		case BISHOP: name += 'B'; name[0] = 'P'; break;
		case KNIGHT: name += 'N'; name[0] = 'P'; break;
		case ROOK:   name += 'R'; name[0] = 'P'; break;
		default: break;
		}
	}
	return name;
}

bool Board::Turn::isCheck() {
	if (castling != UNDEFINED) return false;

	return board->check(moved_chessman, board->chessmen[same(board->color_turn)][0].x);
}