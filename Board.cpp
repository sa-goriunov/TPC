#include "Board.h"

Board::Board(std::vector<int8_t> _board, std::vector<Chessman> white, std::vector<Chessman> black, int8_t color, uint8_t en_passant) {
	board = _board;
	chessmen[WHITE_] = white;
	chessmen[BLACK_] = black;
	color_turn = color;

	zobrist = START_KEY;

	for (const auto i : chessmen[WHITE_]) {
		zobrist = zobrist xor KEY[i.id - 1][WHITE_][i.x];
	}

	for (const auto i : chessmen[BLACK_]) {
		zobrist = zobrist xor KEY[i.id - 1][BLACK_][i.x];
	}
}

bool Board::isEndgame() {
	return (pieces[WHITE_] + pieces[BLACK_]) <= 6;
}