#pragma once

constexpr auto WHITE = (char)1;
constexpr auto BLACK = (char)-1;

enum Pieces {
KING = (char)6,
QUEEN = (char)5,
ROOK = (char)4,
BISHOP = (char)3,
KNIGHT = (char)2,
PAWN = (char)1,
VOID = (char)0,
KING_NM = (char)16,  //not moved
ROOK_NM = (char)14,  //not moved;
OUTSIDE = (char)42
};

constexpr auto SHORT_CASTLING = 1;
constexpr auto LONG_CASTLING = 2;

constexpr auto NUMBER_OF_CHESSMEN = 16;

//TODO:  0&88
inline int coords(char x, char y){
	return (9 - (int)y) * 12 + (int)x + 2;
}

inline char invert(char color) {
	return (color + 1) / 2;
}

inline char same(char color) {
	return (-color + 1) / 2;
}