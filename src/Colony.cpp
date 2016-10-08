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
