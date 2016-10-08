/*
 * Day.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#ifndef DAY_H_
#define DAY_H_

class Day {
	int dayNum;
	void printStatus();
public:
	Day();
	~Day();
	void morningDecisions();
	void progressDay();
	void deathRoll();
	void incDay();

};

#endif /* DAY_H_ */
