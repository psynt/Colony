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
	int member, ration, uncooked, weapon, sick, medicine, barricades;
	cout << "The colony has " << member << " members. \n";
	cout << "You have " << ration << " rations of food. \n";
	cout << "You have " << uncooked << " uncooked food. \n";
	cout << "You have " << weapon << " weapons. \n";
	cout << sick << " members are sick. \n";
	cout << "You have " << medicine << " medicine. \n";
	cout << "You have " << barricades << " barricades. \n";
}


Day::Day() {
	// TODO Auto-generated constructor stub

}

Day::~Day() {
	// TODO Auto-generated destructor stub
}
void Day::incDay(){
	dayNum++;
}
