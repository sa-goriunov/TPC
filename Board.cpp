#include "Board.h"

Board::Board(std::vector<int8_t> _board, std::vector<Chessman> white, std::vector<Chessman> black, int8_t color, uint8_t en_passant) {
	board = _board;
	chessmen[0] = white;
	chessmen[1] = black;
	color_turn = color;

	//TODO: Mt
	srand(42);
	zobrist = rand64();

	for (const auto i : chessmen[0]) {
		zobrist = zobrist xor KEY[i.id - 1][WHITE_][i.x];
	}

	for (const auto i : chessmen[1]) {
		zobrist = zobrist xor KEY[i.id - 1][BLACK_][i.x];
	}
}

bool Board::isEndgame() {
	return (pieces[WHITE_] + pieces[BLACK_]) <= 6;
}