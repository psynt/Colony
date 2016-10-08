/*
 * Day.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#ifndef DAY_H_
#define DAY_H_

class Day {
	Colony* c;
	void printStatus_init();
	void printStatus_find();
	void printStatus_result();
public:
	Day(Colony* c);
	~Day();
	void morningDecisions();
	void progressDay();
	void deathRoll();

};

#endif /* DAY_H_ */
