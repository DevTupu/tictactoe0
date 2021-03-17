#ifndef ARENA_HH
#define ARENA_HH

#include <vector>

using namespace std;

/**
 * The play area for the game: 
 * A 3 x 3 square consisting of 9 smaller squares
 * 
 */

class Arena {
public:
	// Default constructor
	Arena();

	// Draws the game area's visual. Also used to refresh the area.
	void draw_play_arena();

	// Returns squares' status
	vector<char> get_squares_status_char();

	// Fills the square of the index. Return false if square is full or out of range
	bool fill(int index, char symbol);

	// Returns true if full, and prints an appropriate message
	bool check_filled();

private:
	// Char info of squares' contents and by extension game status
	vector<char> squares_status_char;

	// How many squares are filled
	int filled;


};

#endif // ARENA_HH