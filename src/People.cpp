/*
 * People.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "People.h"

People::People() {
	people = 0;
	sick = 0;
}

People::~People() {
	// important destructor
}

int People::getPeople(){
	return people;
}
int People::getSick(){
	return sick;
}
