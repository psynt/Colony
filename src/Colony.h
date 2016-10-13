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
	int rations, medicine, uncooked, weapons, barricade, scrap;
	int people, sick;
	int cookBots, turrets;
public:
	Colony();
	Colony(int, int, int, int, int, int, int, int, int d=1, int si=0, int b=0);
	virtual ~Colony();
	int getPeople();
	int getSick();
	int getRat();
	int getMed();
	int getWep();
	int getUnc();
	int getDay();
	int getBar();
	int getScr();
	int getCookB();
	int getTur();
	void incDay();
	void setPeople(int);
	void setSick(int);
	void setRat(int);
	void setMed(int);
	void setWep(int);
	void setUnc(int);
	void setBar(int);
	void setScr(int);
	void setCookB(int);
	void setTur(int);
	void operator+=(Colony*);
};

#endif /* COLONY_H_ */
