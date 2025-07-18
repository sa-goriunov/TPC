#include "GenerateMoves.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <deque>
#include <random>
#include <ctime>
using namespace std;

void Board::printTest() {
	
	for(int i = 2; i<10; i++){
		for (int j = 2; j < 10; j++)
		{
			cout.width(3); cout << (int)board[i * 12 + j] << " ";
		}
		cout << endl;
	}
	//cout << zobrist << endl;
}

int main() {
	srand(time(NULL));
	Game a;
	a.__board__->printTest();
	deque<Board::Turn> history;


	for (int i = 0; i < 6; i++) {
		string hod;
		cin >> hod;
		Board::Turn t(hod, a.__board__);
		t();
		cout << endl << t.isCheck() << endl;
		history.push_front(t);
		a.__board__->printTest();
		cout << endl;

		Board::GenerateMoves my_moves;
		my_moves(a.__board__, t.en_passant);

		int y = my_moves.turns.size();
		Board::Turn answer = my_moves.turns[(rand()) % y];
		answer();
		cout << endl << y << endl;
		cout << answer.name() << endl;
		history.push_front(t);
		a.__board__->printTest();
		cout << endl;
	}

	/*for (auto i : history) {
		i.unmake();
		a.__board__->printTest();
		cout << endl;
	}*/

	return 0;
}