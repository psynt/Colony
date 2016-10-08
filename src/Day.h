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
	void getInput(int* i);
	void zombieBreakIn(int zombie);
	void search(int people,int *k);
	int cookFood(int people, int uncooked);

};

#endif /* DAY_H_ */
