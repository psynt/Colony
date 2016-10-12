/*
 * Colony.h
 *
 *  Created on: 8 Oct 2016
 *      Author: zaxa1
 */

#ifndef COLONY_H_INCLUDED
#define COLONY_H_INCLUDED

class Colony {
	int day;
	int rations, medicine, uncooked, weapons, barricade;
	int people, sick;
public:
	Colony();
	virtual ~Colony();
	int getPeople();
	int getSick();
	int getRat();
	int getMed();
	int getWep();
	int getUnc();
	int getDay();
	void incDay();
	void setPeople(int people);
	void setSick(int sick);
	void setRat(int rations);
	void setMed(int m);
	void setWep(int w);
	void setUnc(int u);
	int getBar();
	void setBar(int b);
};

#endif /* COLONY_H_ */
