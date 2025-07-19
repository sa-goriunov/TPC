#include "GenerateMoves.h"

bool Board::Turn::operator > (const Turn& turn) {
	if (eaten_chessman != nullptr) {
		if (turn.eaten_chessman != nullptr) {
			if (eaten_chessman->id != turn.eaten_chessman->id)
				return (eaten_chessman->id > turn.eaten_chessman->id);
			else
				return (moved_chessman->id < turn.moved_chessman->id);
		}
		else return true;
	}
	else {
		if (turn.eaten_chessman != nullptr) return false;
		else return true; // !!!!! requires to be written
	}
}

void Game::GenerateMoves::sortMoves(Board* board) {

}