#include "Colony.h"
#include "Constants.h"

#ifndef DAY_H_INCLUDED

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
	void getInput(int* i);
	void zombieBreakIn(int zombie);
	void search(int people,int *k);
	int cookFood(int people, int &uncooked);
};

#endif /* DAY_H_ */
