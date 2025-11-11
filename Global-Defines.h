#pragma once

constexpr int8_t WHITE = 1;
constexpr int8_t BLACK = -1;

enum Pieces {
KING = (int8_t)6,
QUEEN = (int8_t)5,
ROOK = (int8_t)4,
BISHOP = (int8_t)3,
KNIGHT = (int8_t)2,
PAWN = (int8_t)1,
VOID = (int8_t)0,
KING_NM = (int8_t)16,  //not moved
ROOK_NM = (int8_t)14,  //not moved;
OUTSIDE = (int8_t)42
};

constexpr uint8_t SHORT_CASTLING = 1;
constexpr uint8_t LONG_CASTLING = 2;

constexpr uint8_t NUMBER_OF_CHESSMEN = 16;

//TODO:  0&88
inline int coords(char x, char y){
	return (9 - (int)y) * 12 + (int)x + 2;
}

inline int8_t invert(uint8_t color) {
	return (-color & (uint8_t)2) >> 1;
}

inline int8_t same(uint8_t color) {
	return (color & (uint8_t)2) >> 1;
}