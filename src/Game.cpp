#include <iostream>
#include "Game.h"
using namespace std;

Game::Game() {
	// important constructor
}

Game::~Game() {
	// important destructor
}

void Game::play(){
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
