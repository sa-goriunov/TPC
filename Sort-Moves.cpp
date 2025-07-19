#include "GenerateMoves.h"

//needs to be rewritten
bool Board::Turn::operator > (const Turn& turn) {  //for sorting forced moves
	if (eaten_chessman != nullptr) {
		if (turn.eaten_chessman != nullptr) {
			if (eaten_chessman->id != turn.eaten_chessman->id)
				return (eaten_chessman->id > turn.eaten_chessman->id);
			else
				return (moved_chessman->id < turn.moved_chessman->id);
		}
		else return false;  //promotion
	}
	else {
		if (turn.eaten_chessman != nullptr) return true;
		else return (promotion > turn.promotion);
	}
}

bool Board::Turn::operator < (const Turn& turn) {   //for sorting other moves
	return estimate_difference < turn.estimate_difference;
}

void Game::GenerateForcedMoves::pick(int iteration) {
  if(iteration == 0){
		int best_move_pos = iteration;
		for (int i = iteration + 1; i < turns.size(); i++) {
			if (turns[i].eaten_coords() == board->last_moving_chessman_coords) {
				best_move_pos = i;
				break; 
			} 
			else if (turns[i] > turns[best_move_pos])
					best_move_pos = i;
		}
		if (best_move_pos != 0) {
			Board::Turn tmp = turns[0];
			turns[0] = turns[best_move_pos];
			turns[best_move_pos] = tmp;
		}
  }
  else {
		  int best_move_pos = iteration;
		  for (int i = iteration + 1; i < turns.size(); i++) {
			  if (turns[i] > turns[best_move_pos])
				  best_move_pos = i;
		  }
		  if (best_move_pos != iteration){
			  Board::Turn tmp = turns[iteration];
			  turns[iteration] = turns[best_move_pos];
			  turns[best_move_pos] = tmp;
		  }
  }
}

void Game::GenerateMoves::pick(int iteration) {
	if (turns.size() >= 2) {
		int best_move_pos = iteration;
		for (int i = iteration + 1; i < turns.size(); i++) {
			if (turns[best_move_pos] < turns[i])
				best_move_pos = i;
		}
		if (best_move_pos != iteration) {
			Board::Turn tmp = turns[iteration];
			turns[iteration] = turns[best_move_pos];
			turns[best_move_pos] = tmp;
		}
	}
}