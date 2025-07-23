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
	Game game;
	cout << "DEPTH:";
	int depth; cin >> depth; game.setDepth(depth);
	cout << "MAX_DEPTH:";
	int max_depth; cin >> max_depth; game.setMaxDepth(max_depth);
	cout << "Choose color:";
	int color; cin >> color; game.setColor(-color);
	game.__board__->printTest();
	cout << endl;

/*	game.__board__->color_turn = -1;
	string hod;
	cin >> hod;
	Board::Turn turn1(hod, game.__board__);
	turn1();
	game.__board__->printTest();

	game.__board__->color_turn = -1;
	Game::GenerateForcedMoves ooo(game.__board__);
	ooo();
	for (auto i : ooo.turns)
		cout << i.name() << ' ';*/

	
	while (true) {
		string opponents_turn;
		cin >> opponents_turn;
		cout << game.play(opponents_turn) << endl;
		game.__board__->printTest();
	}

		/*string hod;
		cin >> hod;
		Board::Turn turn1(hod, game.__board__);
		turn1();
		cout << turn1.isCheck() << ' ' 
			<< game.__board__->supercheck(game.__board__->chessmen[same(game.__board__->color_turn)][0].x, 
				game.__board__->chessmen[same(game.__board__->color_turn)][0].y) << endl;
		game.__board__->printTest();

		Game::GenerateForcedMoves trns1(game.__board__);
		Game::GenerateMoves trns2(game.__board__);

		trns1(); trns2();
		
		if (trns1.turns.empty()) {
			trns2.pick(0);
			trns2.turns[0]();
			cout << trns2.turns[0].name() << endl << trns2.turns[0].isCheck() << ' '
				<< game.__board__->supercheck(game.__board__->chessmen[same(game.__board__->color_turn)][0].x,
					game.__board__->chessmen[same(game.__board__->color_turn)][0].y) << endl;
			game.__board__->printTest();
			cout << endl;
		}
		else {
			trns1.pick(0);
			trns1.turns[0]();
			cout << trns1.turns[0].name() << endl << trns1.turns[0].isCheck() << ' '
				<< game.__board__->supercheck(game.__board__->chessmen[same(game.__board__->color_turn)][0].x,
					game.__board__->chessmen[same(game.__board__->color_turn)][0].y) << endl;
			game.__board__->printTest();
			cout << endl;
		}
	}*/
	return 0;
}