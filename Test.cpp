#include "GenerateMoves.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <deque>
#include <random>
#include <ctime>
using namespace std;

void Board::printTest() {

	for (int i = 2; i < 10; i++) {
		for (int j = 2; j < 10; j++)
		{
			cout.width(3); cout << (int)board[i * 12 + j] << " ";
		}
		cout << endl;
	}
	//cout << zobrist << endl;
}

int main() {
	Game a;
	a.__board__->printTest();
	deque<Board::Turn> history;


	for (int i = 0; i < 10; i++) {
		string hod;
		cin >> hod;
		Board::Turn t(hod, a.__board__);
		t();
		cout << (int)a.__board__->pawns[0] << ' ' << (int)a.__board__->pawns[0] << ' ' << (int)a.__board__->pieces[0] << ' '
			<< (int)a.__board__->pieces[1] << endl;
		history.push_front(t);
		a.__board__->printTest();
		cout << endl;

		Game::GenerateForcedMoves my_forced_moves(a.__board__);
		my_forced_moves();
		Game::GenerateMoves my_moves(a.__board__);
		my_moves();
		
		for (int i = 0; i < my_forced_moves.turns.size(); i++)
			my_forced_moves.pick(i);
		for (int i = 0; i < my_moves.turns.size(); i++)
			my_moves.pick(i);

		if (my_forced_moves.turns.empty()){
			Board::Turn answer = my_moves.turns[0];
			answer();
			cout << answer.name() << endl;
			cout << (int)a.__board__->pawns[0] << ' ' << (int)a.__board__->pawns[0] << ' ' << (int)a.__board__->pieces[0] << ' '
				<< (int)a.__board__->pieces[1] << endl;
			a.__board__->printTest();
			history.push_front(answer);
		}
		else {
			Board::Turn answer = my_forced_moves.turns[0];
			answer();
			cout << answer.name() << endl;
			cout << (int)a.__board__->pawns[0] << ' ' << (int)a.__board__->pawns[0] << ' ' << (int)a.__board__->pieces[0] << ' '
				<< (int)a.__board__->pieces[1] << endl;
			a.__board__->printTest();
			history.push_front(answer);
		}

		cout << endl;
	}

	for (auto i : history) {
		i.unmake();
		a.__board__->printTest();
		cout << endl << (int)a.__board__->en_passant;
		cout << endl;
	}

	return 0;
}