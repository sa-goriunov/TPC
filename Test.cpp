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
	srand(time(NULL));
	a.__board__->printTest();
	deque<Board::Turn> history;


	for (int i = 0; i < 6; i++) {
		string hod;
		cin >> hod;
		Board::Turn t(hod, a.__board__);
		t();
		cout << endl << (int)t.before_en_passant << ' ' << (int)t.en_passant << endl;
		history.push_front(t);
		a.__board__->printTest();
		cout << endl;

		Game::GenerateMoves my_moves;
		my_moves(a.__board__);
		
		Board::Turn answer = my_moves.turns[(rand()) % my_moves.turns.size()];
		answer();
		cout << answer.name() << endl;
		cout << endl << (int)answer.before_en_passant << ' ' << (int)answer.en_passant << endl;
		history.push_front(t);
		a.__board__->printTest();
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