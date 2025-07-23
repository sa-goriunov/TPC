#include "Game.h"

Game::Game() {
	std::vector<char> start_board = {

	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE, BLACK*ROOK_NM, BLACK*KNIGHT, BLACK*BISHOP, BLACK*QUEEN, BLACK*KING_NM, BLACK*BISHOP, BLACK*KNIGHT, BLACK*ROOK_NM, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,    BLACK*PAWN,   BLACK*PAWN,   BLACK*PAWN,  BLACK*PAWN,    BLACK*PAWN,   BLACK*PAWN,   BLACK*PAWN,    BLACK*PAWN, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,    WHITE*PAWN,   WHITE*PAWN,   WHITE*PAWN,  WHITE*PAWN,    WHITE*PAWN,   WHITE*PAWN,   WHITE*PAWN,    WHITE*PAWN, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE, WHITE*ROOK_NM, WHITE*KNIGHT, WHITE*BISHOP, WHITE*QUEEN, WHITE*KING_NM, WHITE*BISHOP, WHITE*KNIGHT, WHITE*ROOK_NM, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	};

	std::vector<Chessman> white = {
		{KING, 4, 0 }, { QUEEN, 3, 0 }, { ROOK, 0, 0 }, { ROOK, 7, 0 },
		{BISHOP, 2, 0}, {BISHOP, 5, 0}, {KNIGHT, 1, 0}, {KNIGHT, 6, 0},
		{PAWN, 0, 1}, {PAWN, 1, 1}, {PAWN, 2, 1}, {PAWN, 3, 1},
		{PAWN, 4, 1}, {PAWN, 5, 1}, {PAWN, 6, 1}, {PAWN, 7, 1}
	};

	std::vector<Chessman> black = {
		{KING, 4, 7}, {QUEEN, 3, 7}, {ROOK, 0, 7}, {ROOK, 7, 7},
		{BISHOP, 2, 7}, {BISHOP, 5, 7}, {KNIGHT, 1, 7}, {KNIGHT, 6, 7},
		{PAWN, 0, 6}, {PAWN, 1, 6}, {PAWN, 2, 6}, {PAWN, 3, 6},
		{PAWN, 4, 6}, {PAWN, 5, 6}, {PAWN, 6, 6}, {PAWN, 7, 6}
	};

	Board* ptr = new Board(start_board, white, black, WHITE, -1);
	__board__ = ptr;

	__board__->pawns[WHITE_] = 8;
	__board__->pawns[BLACK_] = 8;
	__board__->pieces[WHITE_] = 7;
	__board__->pieces[BLACK_] = 7;
}

Game::~Game()
{
	delete __board__;
}
/*
Game::Game(int a) {
	std::vector<char> start_board = {

	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,  BLACK*QUEEN,        VOID,          VOID,         VOID,         VOID,    BLACK*KING, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,    BLACK*PAWN,         VOID,         VOID,        VOID,          VOID,         VOID, BLACK*BISHOP,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,   BLACK*PAWN,    BLACK*PAWN, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,   WHITE*PAWN,        VOID,          VOID,         VOID, WHITE*KNIGHT,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,    WHITE*ROOK,   WHITE*PAWN,         VOID,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,    WHITE*PAWN,         VOID,         VOID,  BLACK*ROOK,          VOID,         VOID,         VOID,    WHITE*PAWN, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,   WHITE*QUEEN,         VOID,         VOID,        VOID,          VOID,         VOID,   WHITE*KING,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
	};

	std::vector<Chessman> white = {
		{KING, 6, 1 }, { QUEEN, 0, 1 }, { ROOK, 4, 3 }, {KNIGHT, 6, 4},
		{PAWN, 0, 2}, {PAWN, 2, 4}, {PAWN, 5, 3}, {PAWN, 7, 2}, /**/
	/*	{PAWN, 0, 6}, {PAWN, 1, 6}, {PAWN, 2, 6}, {PAWN, 3, 6},
		{PAWN, 4, 6}, {PAWN, 5, 6}, {PAWN, 6, 6}, {PAWN, 7, 6}
	};

	std::vector<Chessman> black = {
		{KING, 7, 7}, {QUEEN, 2, 7}, {ROOK, 3, 2}, {BISHOP, 6, 6},
		{PAWN, 0, 6}, {PAWN, 6, 5}, {PAWN, 7, 5}, /**//*{PAWN, 5, 5},
		{PAWN, 0, 6}, {PAWN, 1, 6}, {PAWN, 2, 6}, {PAWN, 3, 6},
		{PAWN, 4, 6}, {PAWN, 5, 6}, {PAWN, 6, 6}, {PAWN, 7, 6}
	};

	for (int i = 8; i < NUMBER_OF_CHESSMEN; i++){
		white[i].enabled = false;
		black[i].enabled = false;
	}
	black[7].enabled = false;

	Board* ptr = new Board(start_board, white, black, WHITE, -1);
	__board__ = ptr;

	__board__->pawns[WHITE_] = 4;
	__board__->pawns[BLACK_] = 3;
	__board__->pieces[WHITE_] = 3;
	__board__->pieces[BLACK_] = 3;
}
*/