#include <iostream>
#include "Game.h"
#include "Day.h"
using namespace std;

Game::Game(Colony* c, Day* d) {
	colony = c;
	day = d;
}

Game::Game() {
	colony = new Colony();
	day = new Day(colony);
}

Game::~Game() {
	delete colony;
	delete day;
}

void Game::play() {
	while (colony->getPeople() > 0){
		day->printStatus_init();
		day->printStatus_find();
		day->printStatus_result();
		day->deathRoll();
		day->EndDay();
	}

	cout << "You lasted " << colony->getDay() << " days. Congratulations.\n";
}
