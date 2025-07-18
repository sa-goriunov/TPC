#pragma once
#include <vector>

const static char knight_moves[][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

const static char bishop_moves[][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

const static char rook_moves[][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

const static char queen_moves[][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

const static char king_moves[][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };