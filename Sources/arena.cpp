#include "../Headers/arena.hh"
#include "../Headers/game.hh"

#include <iostream>
#include <vector>

using namespace std;


Arena::Arena() {
	squares_status_char = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	filled = 0;
}

bool Arena::fill(int index, char symbol) {
	if ((index < 0) || index > 8) {
		cout << "Please use proper range." << endl;
		return false;
	} else if ((squares_status_char.at(index) == 'O') || (squares_status_char.at(index) == 'X')) {
		cout << "Square already filled." << endl;
		return false;
	} else {
		// Input is proper
		squares_status_char.at(index) = symbol;
		filled++;
		return true;
	}
}

vector<char> Arena::get_squares_status_char(){
	return squares_status_char;
}

void Arena::draw_play_arena() {
	vector<char> sss = squares_status_char;
	cout << endl;
	cout << "|---|---|---|" << endl;
	cout << "| " << sss.at(0) << " | " << sss.at(1) << " | " << sss.at(2) << " |" << endl;
	cout << "|---|---|---|" << endl;
	cout << "| " << sss.at(3) << " | " << sss.at(4) << " | " << sss.at(5) << " |" << endl;
	cout << "|---|---|---|" << endl;
	cout << "| " << sss.at(6) << " | " << sss.at(7) << " | " << sss.at(8) << " |" << endl;
	cout << "|---|---|---|" << endl;
	cout << endl;
}

bool Arena::check_filled() {
	if(filled > 8) {
		cout << "All squares are full!" << endl;
		return true;
	} else {
		return false;
	}
}
