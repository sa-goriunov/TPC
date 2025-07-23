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
					if ((board->board[coords(tmp->x, tmp->y + 1)] == VOID) && (tmp->y != 6))
						if ((tmp->y == 1) && (board->board[coords(tmp->x, tmp->y + 2)] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y + 2, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y + 1, board));
						}
						else { turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y + 1, board)); }
				}
				else {
					if ((board->board[coords(tmp->x, tmp->y - 1)] == VOID) && (tmp->y != 1))
						if ((tmp->y == 6) && (board->board[coords(tmp->x, tmp->y - 2)] == VOID)) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y - 2, board));
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y - 1, board));
						}
						else { turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x, tmp->y - 1, board)); }
				
				}
				break;

			case KNIGHT:
				for (auto i : knight_moves) {
					char tmp2 = board->board[coords(tmp->x + i[0], tmp->y + i[1])];
					if(tmp2 == VOID)
						turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + i[0], tmp->y + i[1], board));
				}
				break;

			case BISHOP:
				for (auto i : bishop_moves) {
					bool clear_line = true; char j = 1;
					while (clear_line) {
						char tmp2 = board->board[coords(tmp->x + j * i[0], tmp->y + j * i[1])];
						if (tmp2 == VOID) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + j * i[0], tmp->y + j * i[1], board));
							j++;
						}
						else {
							clear_line = false;
						}
					}
				}
				break;

			case ROOK:
				for (auto i : rook_moves) {
					bool clear_line = true; char j = 1;
					while (clear_line) {
						char tmp2 = board->board[coords(tmp->x + j * i[0], tmp->y + j * i[1])];
						if(tmp2 == VOID) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + j * i[0], tmp->y + j * i[1], board));
							j++;
						}
						else {
							clear_line = false;
						}
					}
				}
				break;

			case QUEEN:
				for (auto i : queen_moves) {
					bool clear_line = true; char j = 1;
					while (clear_line) {
						char tmp2 = board->board[coords(tmp->x + j * i[0], tmp->y + j * i[1])];
						if (tmp2 == VOID) {
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + j * i[0], tmp->y + j * i[1], board));
							j++;
						}
						else {
								clear_line = false;
							}
					}
				}
				break;

			case KING:
				for (auto i : king_moves) {
						char tmp2 = board->board[coords(tmp->x + i[0], tmp->y + i[1])];
						if(tmp2 == VOID)
							turns.push_back(Board::Turn(tmp, tmp->x, tmp->y, tmp->x + i[0], tmp->y + i[1], board));
				}
				if (color == WHITE_) {
					if ((board->board[114] == KING_NM) && (board->board[117] == ROOK_NM) &&
						(board->board[115] == VOID) && (board->board[116] == VOID)
						&& board->supercheck(4, 0) && board->supercheck(5, 0)) {
						turns.push_back(Board::Turn(SHORT_CASTLING, board));
					}
					if ((board->board[114] == KING_NM) && (board->board[110] == ROOK_NM) &&
						(board->board[111] == VOID) && (board->board[112] == VOID) && (board->board[113] == VOID)
						&& board->supercheck(4, 0) && board->supercheck(3, 0)) {
						turns.push_back(Board::Turn(LONG_CASTLING, board));
					}
				}
				else {
					if ((board->board[30] == BLACK*KING_NM) && (board->board[33] == BLACK*ROOK_NM) &&
						(board->board[31] == VOID) && (board->board[32] == VOID)
						&& board->supercheck(4, 7) && board->supercheck(5, 7)) {
						turns.push_back(Board::Turn(SHORT_CASTLING, board));
					}
					if ((board->board[30] == BLACK * KING_NM) && (board->board[26] == BLACK * ROOK_NM) &&
						(board->board[27] == VOID) && (board->board[28] == VOID) && (board->board[29] == VOID)
						&& board->supercheck(4, 7) && board->supercheck(3, 7)) {
						turns.push_back(Board::Turn(LONG_CASTLING, board));
					}
				}
				break;
			}

	}
}