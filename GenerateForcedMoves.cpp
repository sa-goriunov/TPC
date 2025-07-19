#include "GenerateMoves.h"
#include "Generate-Defines.h"

void Game::GenerateForcedMoves::operator()() {
	char color = same(board->color_turn);
	for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
		Chessman* tmp = &board->chessmen[color][i];
		if(tmp->enabled)
			switch (tmp->id) {

			case PAWN:
				if (color == WHITE_) {
					if ((tmp->y == 6) && (board->board[coords(tmp->x, tmp->y + 1)] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y + 1, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y + 1, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y + 1, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y + 1, KNIGHT, board));
						}
					if (board->board[coords(tmp->x + 1, tmp->y + 1)] < 0)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + 1, tmp->y + 1, board));
					if (board->board[coords(tmp->x - 1, tmp->y + 1)] < 0)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x - 1, tmp->y + 1, board));
					if (board->en_passant > -1) {
						if ((tmp->x + 1 == board->en_passant) && (board->board[coords(tmp->x + 1, tmp->y)] == BLACK * PAWN)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + 1, tmp->y + 1, board));
						}
						else if ((tmp->x - 1 == board->en_passant) && (board->board[coords(tmp->x - 1, tmp->y)] == BLACK * PAWN)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x - 1, tmp->y + 1, board));
						}
					}
				}
				else {
					if ((tmp->y == 1)&&(board->board[coords(tmp->x, tmp->y - 1)] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y - 1, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y - 1, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y - 1, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y - 1, KNIGHT, board));
						}
					if ((board->board[coords(tmp->x + 1, tmp->y - 1)] > 0) && (board->board[coords(tmp->x + 1, tmp->y - 1)] != OUTSIDE))
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + 1, tmp->y - 1, board));
					if ((board->board[coords(tmp->x - 1, tmp->y - 1)] > 0) && (board->board[coords(tmp->x - 1, tmp->y - 1)] != OUTSIDE))
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x - 1, tmp->y - 1, board));
					if (board->en_passant > -1) {
						if ((tmp->x + 1 == board->en_passant) && (board->board[coords(tmp->x + 1, tmp->y)] == PAWN)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + 1, tmp->y - 1, board));
						}
						else if ((tmp->x - 1 == board->en_passant) && (board->board[coords(tmp->x - 1, tmp->y)] == PAWN)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x - 1, tmp->y - 1, board));
						}
					}
				}
				break;

			case KNIGHT:
				for (auto i : knight_moves) {
					char tmp2 = board->board[coords(tmp->x + i[0], tmp->y + i[1])];
					if ((tmp2 != OUTSIDE) && (board->color_turn * tmp2 < 0))
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + i[0], tmp->y + i[1], board));
				}
				break;

			case BISHOP:
				for (auto i : bishop_moves) {
					bool clear_line = true; char j = 1;
					while (clear_line) {
						char tmp2 = board->board[coords(tmp->x + j * i[0], tmp->y + j * i[1])];
						switch (tmp2) {
						case OUTSIDE:
							clear_line = false; break;
						case VOID: 
							j++; break;
						default:
							if (board->color_turn * tmp2 < 0) {
								turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + j * i[0], tmp->y + j * i[1], board));
								clear_line = false;
								break;
							}
							else {
								clear_line = false;
								break;
							}
						}
					}
				}
				break;

			case ROOK:
				for (auto i : rook_moves) {
					bool clear_line = true; char j = 1;
					while (clear_line) {
						char tmp2 = board->board[coords(tmp->x + j * i[0], tmp->y + j * i[1])];
						switch (tmp2) {
						case OUTSIDE: clear_line = false; break;
						case VOID:
							j++;
							break;
						default:
							if (board->color_turn * tmp2 < 0) {
								turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + j * i[0], tmp->y + j * i[1], board));
								clear_line = false;
								break;
							}
							else {
								clear_line = false;
								break;
							}
						}
					}
				}
				break;

			case QUEEN:
				for (auto i : queen_moves) {
					bool clear_line = true; char j = 1;
					while (clear_line) {
						char tmp2 = board->board[coords(tmp->x + j * i[0], tmp->y + j * i[1])];
						switch (tmp2) {
						case OUTSIDE: clear_line = false; break;
						case VOID:
							j++;
							break;
						default:
							if (board->color_turn * tmp2 < 0) {
								turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + j * i[0], tmp->y + j * i[1], board));
								clear_line = false;
								break;
							}
							else {
								clear_line = false;
								break;
							}
						}
					}
				}
				break;

			case KING:
				for (auto i : king_moves) {
					char tmp2 = board->board[coords(tmp->x + i[0], tmp->y + i[1])];
					if ((tmp2 != OUTSIDE) && (board->color_turn * tmp2 < 0)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + i[0], tmp->y + i[1], board));
					}
				}
				break;

			}
	}
}