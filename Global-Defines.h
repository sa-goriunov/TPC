#pragma once
#include <cstdint>

constexpr int8_t WHITE = 1;
constexpr int8_t BLACK = -1;

enum Pieces : int8_t {
KING = 6,
QUEEN = 5,
ROOK = 4,
BISHOP = 3,
KNIGHT = 2,
PAWN = 1,
VOID = 0,
KING_NM = 16,  //not moved
ROOK_NM = 14,  //not moved;
OUTSIDE = 42
};

constexpr uint8_t SHORT_CASTLING = 1;
constexpr uint8_t LONG_CASTLING = 2;

constexpr uint8_t NUMBER_OF_CHESSMEN = 16;

constexpr uint8_t UNDEFINED = 255;

inline int8_t invert(int8_t color) {
	return (-color & (uint8_t)2) >> 1;
}

inline int8_t same(int8_t color) {
	return (color & (uint8_t)2) >> 1;
}