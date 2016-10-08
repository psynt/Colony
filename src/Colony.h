/*
 * Colony.h
 *
 *  Created on: 8 Oct 2016
 *      Author: zaxa1
 */

#ifndef COLONY_H_
#define COLONY_H_

class Colony {
	int day;
	int rations, medicine,uncooked, weapons;
	int people;
	int sick;
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
};

#endif /* COLONY_H_ */
