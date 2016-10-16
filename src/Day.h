#include "Colony.h"

#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED

class Day {
	Colony* c;
public:
	Day(Colony* c);
	~Day();
	static int zmult(int d);
	void morningDecisions();
	void progressDay();
	void deathRoll();
	void EndDay();
	void printStatus_init();
	void printStatus_find();
	void printStatus_result();
	void morningEvent();
	void eveningEvent();
	void getInput(int*);
	void zombieBreakIn(int);
	void search(int, int*);
	int cookFood(int, int);
	void projInp(int*,int);
};

#endif /* DAY_H_ */
