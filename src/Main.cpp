//============================================================================
// Name        : T1.cpp
// Author      : Zane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Player.h"
using namespace std;

int main()
{
	cout << "Hello World. Main Started.\n";

	Colony colony = new Colony();
	Day day = new Day(colony);

	while (colony.getPeople() > 0){
		day.printStatus_init();
		day.printStatus_find();
		day.printStatus_result();
		day.deathRoll();
	}

	day.printStatus_lose();

	return 0;
}
