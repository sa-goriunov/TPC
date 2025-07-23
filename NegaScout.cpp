#include "Assess-Defines.h"
#include "Game.h"
#include "GenerateMoves.h"

#include <iostream>

int Game::forcedSearch(int alpha, int beta, int ply, Board* board) {

//std::cout << ply << std::endl;
	if (!board->chessmen[WHITE_][0].enabled) return (-_INFINITY_ + ply) * (board->color_turn);
	if (!board->chessmen[BLACK_][0].enabled) return (_INFINITY_ - ply) * (board->color_turn);

	int res = board->assess();
	int tmp = 0;

	if (res > alpha) alpha = res;
	if (alpha >= beta) return alpha;
	
	GenerateForcedMoves forced_moves(board);
	forced_moves();

	for (int i = 0; i < forced_moves.turns.size(); i++) {
		forced_moves.pick(i);
		forced_moves.turns[i]();
/*
std::cout << forced_moves.turns[i].name() << std::endl;
__board__->printTest();
std::cout << forced_moves.turns[i].isCheck() << std::endl;
*/
		tmp = -forcedSearch(-beta, -alpha, ply + 1, board);
		forced_moves.turns[i].unmake();

		if (tmp > res) res = tmp;
		if (res > alpha) alpha = res;
		if (alpha >= beta) return alpha;
	}

	return res;
}

int Game::NegaScout(int alpha, int beta, int depth, int ply, Board *board) {
//if (history.size() > 0)std::cout << ply << std::endl;

	if (!board->chessmen[WHITE_][0].enabled) return (-_INFINITY_ + ply) * (board->color_turn);
	if (!board->chessmen[BLACK_][0].enabled) return (_INFINITY_ - ply) * (board->color_turn);

	depth--;

	if ((depth <= 0) || (ply > MAX_DEPTH)) {
		return forcedSearch(alpha, beta, ply, board);
	}

	int res = -_INFINITY_;
	int tmp = 0;

	GenerateForcedMoves forced_moves(board);
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
		tmp = -NegaScout(-(alpha + 1), -alpha, depth, ply + 1, board);
		if ((tmp > alpha) && (tmp < beta))
			tmp = -NegaScout(-beta, -tmp, depth, ply + 1, board);
		forced_moves.turns[i].unmake();

		if (tmp > res) res = tmp;
		if (res > alpha) alpha = res;
		if (alpha >= beta) return alpha;
	}

	GenerateMoves moves(board);
	moves();

	for (int i = 0; i < moves.turns.size(); i++) {
		moves.pick(i);
		moves.turns[i]();
/*
std::cout << moves.turns[i].name() << std::endl;
__board__->printTest();
std::cout << moves.turns[i].isCheck() << std::endl;
*/
		if (moves.turns[i].isCheck()) depth++;
		tmp = -NegaScout(-(alpha + 1), -alpha, depth, ply + 1, board);
		if ((tmp > alpha) && (tmp < beta))
			tmp = -NegaScout(-beta, -tmp, depth, ply + 1, board);
		moves.turns[i].unmake();
		if (tmp > res) res = tmp;
		if (res > alpha) alpha = res;
		if (alpha >= beta) return alpha;
	}

	if ((res == -(_INFINITY_ - (ply + 1)))
		&& !(board->supercheck(board->chessmen[WHITE_][0].x, board->chessmen[WHITE_][0].y) ||
			board->supercheck(board->chessmen[BLACK_][0].x, board->chessmen[BLACK_][0].y)))
		res = 0;
	return res;
}