//============================================================================
// Name        : T1.cpp
// Author      : Zane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Day.h"
#include "Colony.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Colony colony;
	Day day(&colony);

	while (colony.getPeople() > 0){
		day.printStatus_init();
		day.printStatus_find();
		day.printStatus_result();
		day.deathRoll();
		day.EndDay();
	}

	cout<<"You lasted "<<colony.getDay();

	return 0;
}
