/*
 * Colony.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: zaxa1
 */

#include "Colony.h"
#include "Constants.h"

Colony::Colony() {
	medicine=INITIAL_MEDICINE;
	rations = INITIAL_FOOD;
	weapons = INITIAL_WEAPONS;
	day=0;
	uncooked=INITIAL_UNCOOKED;
	sick=INITIAL_SICK;
	people=INITIAL_PEOPLE;
	barricade=INITIAL_BARRICADES;
}

Colony::Colony(int r,int m, int u, int w, int d, int p, int s, int b){
	medicine=m;
	rations = r;
	weapons = w;
	day=d;
	uncooked=u;
	sick=s;
	people=p;
	barricade=b;
}

void Colony::operator+=(Colony *c){
	medicine+=c->medicine;
	rations+=c->rations;
	weapons+=c->weapons;
	uncooked+=c->uncooked;
	sick+=c->sick;
	people+=c->people;
	barricade+=c->barricade;

	day = day>c->day?day:c->day;

}

Colony::~Colony() {
	//important destructor
}
void Colony::incDay(){
	day++;
}

int Colony::getPeople(){
	return people;
}
int Colony::getSick(){
	return sick;
}
int Colony::getRat(){
	return rations;
}
int Colony::getMed(){
	return medicine;
}
int Colony::getWep(){
	return weapons;
}
int Colony::getUnc(){
	return uncooked;
}
int Colony::getDay(){
	return day;
}

void Colony::setPeople(int people){
	this->people=people;
}

void Colony::setSick(int sick){
	this->sick=sick;
}
void Colony::setRat(int rations){
	this->rations=rations;
}
void Colony::setMed(int medicine){
	this->medicine=medicine;
}
void Colony::setWep(int weapons){
	this->weapons=weapons;
}
void Colony::setUnc(int uncooked){
	this->uncooked=uncooked;
}
void Colony::setBar(int b){
	barricade=b;
}
int Colony::getBar(){
	return barricade;
}
