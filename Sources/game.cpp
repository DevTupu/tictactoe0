#include "../Headers/arena.hh"
#include "../Headers/game.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constructor
Game::Game() {
	game_complete = false;
	recent_char = 'X';
}

// SETTERS
void Game::set_player_x_name(string n){
	player_x_name = n;
}
void Game::set_player_o_name(string n){
	player_o_name = n;
}

void Game::run() {
	string input;
	Game::play_area = Arena();
	
	bool do_not_ask_for_input;

	// Ask for player names, then draw game board
	cout << "Please enter Player X name: ";
	getline(cin, player_x_name);
	cout << "Please enter Player O name: ";
	getline(cin, player_o_name);
	active_player_name = player_x_name;
	

	while(!game_complete) {
		Game::play_area.draw_play_arena();
		// Check for draws
		do_not_ask_for_input = play_area.check_filled();
		while(!do_not_ask_for_input){
			// WARNING: Improper values may cause malfunctions
			cout << active_player_name << ", please input the number of the square (1-9) you want to fill: ";
			getline(cin, input);
			try {
				// Transform input into a proper index
				recent_index = stoi(input);
				recent_index--;

				// Check if input is in proper range
				do_not_ask_for_input = play_area.fill(recent_index, recent_char);
			} catch(...) {
				cout << "Please give a proper number." << endl;
			}
		}

		

		// After every turn, check if game has ended
		game_complete = check_victory_condition();

		// If not, turn changes
		if(active_player_name == player_x_name) {
			active_player_name = player_o_name;
			recent_char = 'O';
		} else {
			active_player_name = player_x_name;
			recent_char = 'X';
		}
	}

	// Display the winning board
	Game::play_area.draw_play_arena();
}

bool Game::check_columns() {

	vector<char> status;
	status = play_area.Arena::get_squares_status_char();

	// Determine the location
	if(recent_index < 3) {
		// Top row (0, 1, 2)
		if((status.at(recent_index + 3) == recent_char) && status.at(recent_index + 6) == recent_char) {
			cout << active_player_name << " wins!" << endl;
			return true;
		}
	} else if (recent_index > 5) {
		// Bottom Row (6, 7, 8)
		if((status.at(recent_index - 3) == recent_char) && status.at(recent_index - 6) == recent_char) {
			cout << active_player_name << " wins!" << endl;
			return true;
		}
	} else {
		// Middle row (3, 4, 5)
		if((status.at(recent_index - 3) == recent_char) && status.at(recent_index + 3) == recent_char) {
			cout << active_player_name << " wins!" << endl;
			return true;
		}
	}

	// Getting this far means columns are not complete
	return false;
}

bool Game::check_rows() {

	vector<char> status;
	status = play_area.Arena::get_squares_status_char();

	// Determine the location
	if((recent_index == 0) || (recent_index == 3) || (recent_index == 6)) {
		// Leftmost column
		if((status.at(recent_index + 1) == recent_char) && (status.at(recent_index + 2) == recent_char)){
			cout << active_player_name << " wins!" << endl;
			return true;
		} 
	} else if((recent_index == 1) || (recent_index == 4) || (recent_index == 7)) {
		// Middle column
		if((status.at(recent_index - 1) == recent_char) && (status.at(recent_index + 1) == recent_char)){
			cout << active_player_name << " wins!" << endl;
			return true;
		} 
	} else {
		// Rightmost column
		if((status.at(recent_index - 2) == recent_char) && (status.at(recent_index - 1) == recent_char)){
			cout << active_player_name << " wins!" << endl;
			return true;
		} 
	}

	// Getting this far means rows are not complete
	return false;
}

bool Game::check_victory_condition(){
	vector<char> status;
	status = play_area.Arena::get_squares_status_char();
	
	
	// Check columns and rows, and return if won
	if(check_columns() || check_rows()) {
		return true;
	}

	// Check diagonals
	if((recent_index == 1) || (recent_index == 3) || (recent_index == 5) || (recent_index == 7)) {
		// These indexes are impossible for diagonals
		return false;
	}

	// Upper left corner to lower right corner
	if((status.at(0) == recent_char) && (status.at(4) == recent_char) && (status.at(8) == recent_char)) {
		cout << active_player_name << " wins!" << endl;
		return true;
	}

	// Lower left corner to upper right corner
	if((status.at(6) == recent_char) && (status.at(4) == recent_char) && (status.at(2) == recent_char)) {
		cout << active_player_name << " wins!" << endl;
		return true;
	}

	// If program reaches this far, the game is still in progress, unless all squares are full
	return play_area.check_filled();
}

