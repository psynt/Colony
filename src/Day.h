/*
 * Day.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "Colony.h"

#ifndef DAY_H_INCLUDED

class Day {
	Colony* c;
public:
	Day(Colony* c);
	~Day();
	void morningDecisions();
	void progressDay();
	void deathRoll();
	void EndDay();
	void printStatus_init();
	void printStatus_find();
	void printStatus_result();
	int* getInput();
	void zombieBreakIn(int zombie);
	int* search(int people);
	int cookFood(int people, int uncooked);

};

#endif /* DAY_H_ */
