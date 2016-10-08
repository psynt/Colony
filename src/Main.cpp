//============================================================================
// Name        : T1.cpp
// Author      : Zane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Day.h"
#include "Colony.h"
using namespace std;

int main()
{
	srand(time(NULL));
	cout << "Hello World. Main Started.\n";

	Colony colony;
	Day day(&colony);

	while (colony.getPeople() > 0){
		day.printStatus_init();
		day.getInput();
		day.printStatus_find();
		day.printStatus_result();
		day.deathRoll();
	}

	return 0;
}
