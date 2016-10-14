#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Day.h"
#include "Colony.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Game *g=new Game();

	int option;

	do {
		cout << "========== COLONY ==========\n";
		cout << "\n";
		cout << "1. New Game\n";
		cout << "2. Quit\n";
		cout << "\n";
		cout << "OPTION: ";

		cin >> option;

		if (option == 1) {
			g->play();
		}

	} while (option != 2);

	cout << "\nQuitting...\n";

	return 0;
}
