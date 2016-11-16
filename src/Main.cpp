#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

using namespace std;

int main()
{
	srand(time(NULL));

	int option;

	do {
		cout << "========== COLONY ==========\n";
		cout << "\n";
		cout << "1. New Game\n";
		cout << "2. Load Game\n";
		cout << "0. Quit\n";
		cout << "\n";
		cout << "OPTION: ";

		cin >> option;

		if (option == 1) {
			Game* game = new Game();
			game->play();
			delete game;
		}

		if (option == 2) {
			cout << "Feature not yet implemented.\n";
		}


	} while (option != 0);

	cout << "\nQuitting...\n";

	return 0;
}
