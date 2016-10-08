/*
 * Day.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */
#include <iostream>
#include "Day.h"
#include "People.h"

using namespace std;

void Day::printStatus(){
	int member, ration, weapon, sick, medicine;
	member = getPeople();
	sick   = getSick();
	cout << "The colony has " << member << " members. \n";
	cout << "You have " << ration << " rations of food. \n";
	cout << sick << " member is sick. \n";
	cout << "You have " << medicine << " medicine. \n";
}


Day::Day() {
	// TODO Auto-generated constructor stub

}

Day::~Day() {
	// TODO Auto-generated destructor stub
}

