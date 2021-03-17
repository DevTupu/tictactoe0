#ifndef GAME_HH
#define GAME_HH

#include "arena.hh"
#include <string>

using namespace std;

/**
 * The interface of the game, handling player input
 * 
 */

class Game {
public:
	// Default constructor
	Game();

	// The basic method used to get the game running.
	void run();
	
	// Returns true if a player has won, and prints victory message
	// Otherwise returns false
	bool check_victory_condition();

	// SETTERS
	void set_player_x_name(string n);
	void set_player_o_name(string n);

	// GETTERS
	string get_player_x_name();
	string get_player_o_name();

private:
	// Names of both players, and the active player
	string player_x_name;
	string player_o_name;
	string active_player_name;

	// Game status
	bool game_complete;

	// Play area object
	Arena play_area;

	// Index and char of the most recently filled square
	int recent_index;
	char recent_char;

	// Used to support check_victory_condition. These check individual columns and rows
	bool check_columns();
	bool check_rows();
};

#endif // GAME_HH