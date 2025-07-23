#include "Assess-Defines.h"
#include "Game.h"
#include "GenerateMoves.h"

#include <iostream>

std::string Game::play(std::string opponents_turn) {
	if ((history.empty()) && (my_color == WHITE)) {

	}
	else {
		Board::Turn opps_turn(opponents_turn, __board__);
		opps_turn();
		history.push_back(opps_turn);
	}

	GenerateForcedMoves forced_moves(__board__); GenerateMoves other_moves(__board__);
	Board::Turn best_turn(31, __board__);
	//std::vector<Board> boards_for_forced_moves, boards_for_other_moves;
	
	int depth = DEPTH - 1; int ply = 0;
	int res = -_INFINITY_;
	int tmp = 0;
	int alpha = -_INFINITY_, beta = _INFINITY_;

	forced_moves();
	for (int i = 0; i < forced_moves.turns.size(); i++) {
		forced_moves.pick(i);
		forced_moves.turns[i]();
/*
std::cout << forced_moves.turns[i].name() << std::endl;
__board__->printTest();
std::cout << forced_moves.turns[i].isCheck() << std::endl;
*/
		if (forced_moves.turns[i].isCheck()) depth++;
		tmp = -NegaScout(-(alpha + 1), -alpha, depth, ply + 1, __board__);
		if ((tmp > alpha) && (tmp < beta))
			tmp = -NegaScout(-beta, -tmp, depth, ply + 1, __board__);
		forced_moves.turns[i].unmake();

		if (tmp > res) res = tmp;
		if (res > alpha) {
			alpha = res;
			best_turn = forced_moves.turns[i];
		}
		if (alpha >= beta) break;
	}

	other_moves();

	for (int i = 0; i < other_moves.turns.size(); i++) {
		other_moves.pick(i);
		other_moves.turns[i]();
/*
std::cout << other_moves.turns[i].name() << std::endl;
__board__->printTest();
std::cout << other_moves.turns[i].isCheck() << std::endl;
*/
		if (other_moves.turns[i].isCheck()) depth++;
		tmp = -NegaScout(-(alpha + 1), -alpha, depth, ply + 1, __board__);
		if ((tmp > alpha) && (tmp < beta))
			tmp = -NegaScout(-beta, -tmp, depth, ply + 1, __board__);
		other_moves.turns[i].unmake();
		if (tmp > res) res = tmp;
		if (res > alpha) {
			alpha = res;
			best_turn = other_moves.turns[i];
		}
		if (alpha >= beta) break;
	}

	history.push_back(best_turn);
	best_turn();
	std::cout << "Assess:" << res << std::endl;
	return best_turn.name();
}