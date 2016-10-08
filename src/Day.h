/*
 * Day.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "Colony.h"

#ifndef DAY_H_
#define DAY_H_

class Day {
	Colony* c;
	void printStatus_init();
	void printStatus_find();
	void printStatus_result();
	void printStatus_lose();
	void getInput();
	void zombieBreakIn(int zombies);
public:
	Day(Colony* c);
	~Day();
	void morningDecisions();
	void progressDay();
	void deathRoll();
};

#endif /* DAY_H_ */
