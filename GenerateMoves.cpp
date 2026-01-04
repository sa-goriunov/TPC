#include "GenerateMoves.h"
#include "Generate-Defines.h"

void Game::GenerateMoves::operator()() {
	char color = same(board->color_turn);
	for (int i = 0; i < NUMBER_OF_CHESSMEN; i++) {
		Chessman* tmp = &board->chessmen[color][i];
		if (tmp->enabled)
			switch (tmp->id) {

			case PAWN:
				if (color == WHITE_) {
					if ((board->board[(uint8_t)(tmp->x - 16)] == VOID) && (tmp->x > 23))
						if ((tmp->x >= 96) && (board->board[tmp->x - 32] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 32, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 16, board));
						}
						else turns.push_back(Board::Turn(tmp, tmp->x, tmp->x - 16, board));
				}
				else {
					if ((board->board[(uint8_t)(tmp->x + 16)] == VOID) && (tmp->x < 96))
						if ((tmp->x <= 23) && (board->board[(uint8_t)(tmp->x + 32)] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 32, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 16, board));
						}
						else turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + 16, board));
				
				}
				break;

			case KNIGHT:
				for (int8_t i : knight_moves) {
					int8_t tmp2 = board->board[(uint8_t)(tmp->x + i)];
					if(tmp2 == VOID)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + i, board));
				}
				break;

			case BISHOP:
				for (int8_t i : bishop_moves) {
					bool clear_line = true; int8_t j = 1;
					while (clear_line) {
						int8_t tmp2 = board->board[(uint8_t)(tmp->x + j * i)];
						if (tmp2 == VOID) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + j * i, board));
							j++;
						}
						else {
							clear_line = false;
						}
					}
				}
				break;

			case ROOK:
				for (int8_t i : rook_moves) {
					bool clear_line = true; int8_t j = 1;
					while (clear_line) {
						int8_t tmp2 = board->board[(uint8_t)(tmp->x + j * i)];
						if(tmp2 == VOID) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + j * i, board));
							j++;
						}
						else {
							clear_line = false;
						}
					}
				}
				break;

			case QUEEN:
				for (int8_t i : queen_moves) {
					bool clear_line = true; char j = 1;
					while (clear_line) {
						char tmp2 = board->board[(uint8_t)(tmp->x + j * i)];
						if (tmp2 == VOID) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + j * i, board));
							j++;
						}
						else {
								clear_line = false;
							}
					}
				}
				break;

			case KING:
				for (int8_t i : king_moves) {
						int8_t tmp2 = board->board[(uint8_t)(tmp->x + i)];
						if(tmp2 == VOID)
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->x + i, board));
				}
				if (color == WHITE_) {
					if ((board->board[116] == KING_NM) && (board->board[119] == ROOK_NM) &&
						(board->board[117] == VOID) && (board->board[118] == VOID)
						&& !board->supercheck(116) && !board->supercheck(117)) {
						turns.push_back(Board::Turn(SHORT_CASTLING, board));
					}
					if ((board->board[116] == KING_NM) && (board->board[112] == ROOK_NM) &&
						(board->board[113] == VOID) && (board->board[114] == VOID) && (board->board[115] == VOID)
						&& !board->supercheck(116) && !board->supercheck(115)) {
						turns.push_back(Board::Turn(LONG_CASTLING, board));
					}
				}
				else {
					if ((board->board[4] == BLACK*KING_NM) && (board->board[7] == BLACK*ROOK_NM) &&
						(board->board[5] == VOID) && (board->board[6] == VOID)
						&& !board->supercheck(4) && !board->supercheck(5)) {
						turns.push_back(Board::Turn(SHORT_CASTLING, board));
					}
					if ((board->board[4] == BLACK * KING_NM) && (board->board[0] == BLACK * ROOK_NM) &&
						(board->board[1] == VOID) && (board->board[2] == VOID) && (board->board[3] == VOID)
						&& !board->supercheck(4) && !board->supercheck(3)) {
						turns.push_back(Board::Turn(LONG_CASTLING, board));
					}
				}
				break;
			}

	}
}