/*
 * Colony.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: zaxa1
 */

#include "Colony.h"
#include "Constants.h"

Colony::Colony() {
	// TODO Auto-generated constructor stub
	medicine=INITIAL_MEDICINE;
	rations = INITIAL_FOOD;
	weapons = INITIAL_WEAPONS;
}

Colony::~Colony() {
	// TODO Auto-generated destructor stub
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
