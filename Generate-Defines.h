#pragma once
#include <vector>

const char knight_moves[][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

const char bishop_moves[][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

const char rook_moves[][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

const char queen_moves[][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

const char king_moves[][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };