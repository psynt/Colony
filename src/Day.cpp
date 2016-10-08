/*
 * Day.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
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

void Day::DeathRoll(){
	int dead = 0;
	int healed = 0;
	for(int i = 0; i < Colony.getSick(); i++){
		srand(time(NULL));
		int roll = rand() % 7 + 1;
		if (roll == 0){
			dead++;
		}else if (roll == 0){
			healed++;
		}
	}
	cout << dead << " sick colony members have died. \n";
	cout << healed << " sick members have recovered. \n";
	Colony.setPeople(Colony.getPeople()-dead);
	Colony.setSick(Colony.getSick()-healed);
}


Day::Day() {
	// TODO Auto-generated constructor stub

}

Day::~Day() {
	// TODO Auto-generated destructor stub
}
