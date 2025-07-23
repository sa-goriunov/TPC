#include "Sort-Defines.h"
#include "Turn.h"

Board::Turn::Turn(std::string turn, Board* _board) {
	board = _board;
	before_en_passant = _board->en_passant;
	if ((turn == "O-O") || (turn == "o-o") || (turn == "0-0")) castling = SHORT_CASTLING;
	else if ((turn == "O-O-O") || (turn == "o-o-o") || (turn == "0-0-0")) castling = LONG_CASTLING;
	else {
		x_start = turn[0] - 'a';
		y_start = turn[1] - '1';
		x_finish = turn[2] - 'a';
		y_finish = turn[3] - '1';

		int color = same(board->color_turn);
		for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
			Chessman *tmp = &board->chessmen[color][i];
			if ((tmp->x == x_start) && (tmp->y == y_start) && (tmp->enabled)) {
				moved_chessman = tmp; break;
			}}

		moved_chessman_id = board->board[coords(x_start, y_start)];
		finish_id = board->board[coords(x_finish, y_finish)];

		if(moved_chessman->id == PAWN){
			if (((y_start == 1) && (y_finish == 3)) || ((y_start == 6) && (y_finish == 4))) { en_passant = x_finish; }
			else if ((y_finish == 0) || (y_finish == 7)) {
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

		eaten_chessman = findEatenChessman(finish_id, x_finish, y_finish);

	}
}

Board::Turn::Turn(Chessman* _moved_chessman, char x_st, char y_st, char x_fn, char y_fn, Board* _board) {
	board = _board;
	moved_chessman = _moved_chessman;
	moved_chessman_id = board->board[coords(x_st, y_st)];
	x_start = x_st;
	y_start = y_st;
	x_finish = x_fn;
	y_finish = y_fn;

	finish_id = board->board[coords(x_finish, y_finish)];

	if ((moved_chessman->id == PAWN) && (((y_start == 1) && (y_finish == 3)) || ((y_start == 6) && (y_finish == 4)))) en_passant = x_finish;
	before_en_passant = _board->en_passant;

	eaten_chessman = findEatenChessman(finish_id, x_finish, y_finish);

	if(eaten_chessman == nullptr){
		switch (moved_chessman->id) {
		case PAWN:
			if (board->color_turn == WHITE)
				estimate_difference = white_pawn_estimate[estimate_coords(x_fn, y_fn)] - white_pawn_estimate[estimate_coords(x_st, y_st)];
			else
				estimate_difference = black_pawn_estimate[estimate_coords(x_fn, y_fn)] - black_pawn_estimate[estimate_coords(x_st, y_st)];
			break;
		case KNIGHT:
			estimate_difference = knight_estimate[estimate_coords(x_fn, y_fn)] - knight_estimate[estimate_coords(x_st, y_st)];
			break;
		case BISHOP:
			estimate_difference = bishop_estimate[estimate_coords(x_fn, y_fn)] - bishop_estimate[estimate_coords(x_st, y_st)];
			break;
		case ROOK: {
			char opponents_kings_x = board->chessmen[invert(board->color_turn)][0].x;
			char opponents_kings_y = board->chessmen[invert(board->color_turn)][0].y;
			char x1 = x_st - opponents_kings_x; char y1 = y_st - opponents_kings_y;
			char x2 = x_fn - opponents_kings_x; char y2 = y_fn - opponents_kings_y;
			estimate_difference = rook_estimate[check_coords(x2, y2)] - rook_estimate[check_coords(x1, y1)];
			break;}
		case QUEEN: {
			char opponents_kings_x = board->chessmen[invert(board->color_turn)][0].x;
			char opponents_kings_y = board->chessmen[invert(board->color_turn)][0].y;
			char x1 = x_st - opponents_kings_x; char y1 = y_st - opponents_kings_y;
			char x2 = x_fn - opponents_kings_x; char y2 = y_fn - opponents_kings_y;
			estimate_difference = queen_estimate[check_coords(x2, y2)] - queen_estimate[check_coords(x1, y1)];
			break;}
		case KING:
			if(board->isEndgame())
				estimate_difference = late_king_estimate[estimate_coords(x_fn, y_fn)] - late_king_estimate[estimate_coords(x_st, y_st)];
			else
				estimate_difference = early_king_estimate[estimate_coords(x_fn, y_fn)] - early_king_estimate[estimate_coords(x_st, y_st)];
			break;
		default: estimate_difference = 0;
		}
	}
	else {
		estimate_difference = eaten_chessman->id - moved_chessman->id;
	}
}

Board::Turn::Turn(Chessman* _moved_chessman, char x_st, char y_st, char x_fn, char y_fn, char _promotion, Board* _board) {
	board = _board;
	moved_chessman = _moved_chessman;
	moved_chessman_id = board->board[coords(x_st, y_st)];
	x_start = x_st;
	y_start = y_st;
	x_finish = x_fn;
	y_finish = y_fn;
	before_en_passant = _board->en_passant;
	promotion = _promotion;

	finish_id = board->board[coords(x_finish, y_finish)];

	eaten_chessman = findEatenChessman(finish_id, x_finish, y_finish);
	
	estimate_difference = _promotion;
}

Board::Turn::Turn(char _castling, Board* _board) {
	board = _board;
	castling = _castling;
	before_en_passant = _board->en_passant;

	switch (castling) {
	case SHORT_CASTLING: estimate_difference = 20; break;
	case LONG_CASTLING: estimate_difference = 15; break;
	default: estimate_difference = 0;
	}
}

Chessman* Board::Turn::findEatenChessman(char id, char x, char y) {
	char color = invert(board->color_turn);
	if (id != VOID) {
		for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
			Chessman* tmp = &board->chessmen[color][i];
			if ((tmp->x == x_finish) && (tmp->y == y_finish) && (tmp->enabled)) {
				return tmp;
			}}
	} else if ((moved_chessman->id == PAWN) && (x_start != x_finish)) {
		for (int i = 8; i < NUMBER_OF_CHESSMEN; i++) {
			Chessman* tmp = &board->chessmen[color][i];
			if ((x_finish == tmp->x) && (((y_finish - 1) == tmp->y) || ((y_finish + 1) == tmp->y)) && (tmp->enabled)) {
				return tmp;
			}}
	}
	else { return nullptr; }

	return nullptr;
}

std::string Board::Turn::name() {
	std::string name = "";

	switch (castling) {
	case 1: name = "_O-O_"; break;
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

		name += (x_start + 'a');
		name += (y_start + '1');
		name += (x_finish + 'a');
		name += (y_finish + '1');

		switch (promotion) {
		case VOID: break;
		case QUEEN: name += 'Q'; break;
		case BISHOP: name += 'B'; break;
		case KNIGHT: name += 'N'; break;
		case ROOK: name += 'R'; break;
		}
	}
	return name;
}

bool Board::Turn::isCheck() {
	if (castling != 0) return false;

	return board->check(moved_chessman, board->chessmen[same(board->color_turn)][0].x, board->chessmen[same(board->color_turn)][0].y);
}