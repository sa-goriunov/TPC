#include "GenerateMoves.h"
#include "Generate-Defines.h"

#include <iostream>

void Game::GenerateForcedMoves::operator()() {
	char color = same(board->color_turn);
	for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
		Chessman* tmp = &board->chessmen[color][i];
		if(tmp->enabled)
			switch (tmp->id) {

			case PAWN:
				if (color == WHITE_) {
					if ((tmp->x <= 23) && (board->board[(uint8_t)(tmp->x - 16)] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 16, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 16, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 16, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 16, KNIGHT, board));
					}
					if (board->board[(uint8_t)(tmp->x - 15)] < 0) {
						if (tmp->x <= 23) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 15, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 15, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 15, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 15, KNIGHT, board));
						} else turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 15, board));
					}
					if (board->board[(uint8_t)(tmp->x - 17)] < 0) {
						if (tmp->x <= 23) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 17, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 17, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 17, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 17, KNIGHT, board));
						} else turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 17, board));
					}
					if (tmp->x + 1 == board->en_passant)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 15, board));
					if (tmp->x - 1 == board->en_passant)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 17, board));
				}
				else {
					if ((tmp->x >= 96) && (board->board[(uint8_t)(tmp->x + 16)] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 16, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 16, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 16, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 16, KNIGHT, board));
					}
					if ((board->board[(uint8_t)(tmp->x + 17)] > 0) && (board->board[(uint8_t)(tmp->x + 17)] != OUTSIDE)){
						if (tmp->x >= 96) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 17, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 17, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 17, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 17, KNIGHT, board));
						} else turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 17, board));
					}
					if ((board->board[(uint8_t)(tmp->x + 15)] > 0) && (board->board[(uint8_t)(tmp->x + 15)] != OUTSIDE)) {
						if (tmp->x >= 96) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 15, QUEEN, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 15, ROOK, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 15, BISHOP, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 15, KNIGHT, board));
						} else turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 15, board));
					}
					if (tmp->x + 1 == board->en_passant)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 17, board));
					if (tmp->x - 1 == board->en_passant)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 15, board));
				}
				break;

			case KNIGHT:
				for (int8_t i : knight_moves) {
					int8_t tmp2 = board->board[(uint8_t)(tmp->x + i)];
					if ((tmp2 != OUTSIDE) && (board->color_turn * tmp2 < 0))
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + i, board));
				}
				break;

			case BISHOP:
				for (int8_t i : bishop_moves) {
					bool clear_line = true; int8_t j = 1;
					while (clear_line) {
						int8_t tmp2 = board->board[(uint8_t)(tmp->x + j * i)];
						switch (tmp2) {
						case OUTSIDE: clear_line = false; break;
						case VOID: j++; break;
						default:
							if (board->color_turn * tmp2 < 0) {
								turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + j * i, board));
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
				for (int8_t i : rook_moves) {
					bool clear_line = true; int8_t j = 1;
					while (clear_line) {
						int8_t tmp2 = board->board[(uint8_t)(tmp->x + j * i)];
						switch (tmp2) {
						case OUTSIDE: 
							clear_line = false; break;
						case VOID: j++; break;
						default:
							if (board->color_turn * tmp2 < 0) {
								turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + j * i, board));
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
				for (int8_t i : queen_moves) {
					bool clear_line = true; int8_t j = 1;
					while (clear_line) {
						int8_t tmp2 = board->board[(uint8_t)(tmp->x + j * i)];
						switch (tmp2) {
						case OUTSIDE: clear_line = false; break;
						case VOID: j++; break;
						default:
							if (board->color_turn * tmp2 < 0) {
								turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + j * i, board));
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
				for (int8_t i : king_moves) {
					int8_t tmp2 = board->board[(uint8_t)(tmp->x + i)];
					if ((tmp2 != OUTSIDE) && (board->color_turn * tmp2 < 0)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + i, board));
					}
				}
				break;

			}
	}
}