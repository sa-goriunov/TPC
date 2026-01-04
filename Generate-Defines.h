#pragma once
#include <vector>
#include <cstdint>

const int8_t knight_moves[] = { 14, -14, 18, -18, 31, -31, 33, -33 };

const int8_t bishop_moves[] = { 15, -15, 17, -17 };

const int8_t rook_moves[] = { 1, -1, 16, -16 };

const int8_t queen_moves[] = { 1, -1, 15, -15, 16, -16, 17, -17 };

const int8_t king_moves[] = { 1, -1, 15, -15, 16, -16, 17, -17 };



/*const uint8_t knight_moves[] = { 14, -14, 18, -18, 31, -31, 33, -33 };

const uint8_t bishop_moves[] = { 15, 241, 17, 239 };

const uint8_t rook_moves[] = { 1, -1, 16, -16 };

const uint8_t queen_moves[] = { 1, 255, 15, 241, 16, 240, 17, 239 };

const uint8_t king_moves[] = { 1, 255, 15, 241, 16, 240, 17, 239 };*/