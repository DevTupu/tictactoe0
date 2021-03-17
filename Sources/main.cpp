#include "game.cpp"
#include "arena.cpp"
#include <iostream>

#include <string>

using namespace std;

int main() {
	Game application;
	string input;

	application.run();

	// Extra confirmation so that the user is not exited so suddenly
	cout << "Press ENTER to quit" << endl;
	getline(cin, input);

	return EXIT_SUCCESS;
}