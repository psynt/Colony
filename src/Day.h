/*
 * Day.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "Colony.h"

#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED

class Day {
	Colony* c;
public:
	~Day(Colony* c);
	void morningDecisions();
	void progressDay();
	void deathRoll();
	void printStatus_init();
	void printStatus_find();
	void printStatus_result();
	void getInput();
	void zombieBreakIn(int zombie);

};

#endif /* DAY_H_ */
