#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Day.h"
#include "Colony.h"
using namespace std;

int main()
{
	srand(time(NULL));

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
			Colony colony;
			Day day(&colony);

			while (colony.getPeople() > 0){
				day.printStatus_init();
				day.printStatus_find();
				day.printStatus_result();
				day.deathRoll();
				day.EndDay();
			}

			cout << "You lasted " << colony.getDay() << " days. Congratulations.\n\n\n\n";
		}

	} while (option != 2);

	cout << "\nQuitting...\n";

	return 0;
}
