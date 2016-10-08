/*
 * Day.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */
#include <iostream>
#include "Day.h"
#include "People.h"
#include "Colony.h"

using namespace std;

void Day::printStatus_init(){
	int dayNum=c->getDay();
	int member=c->getPeople();
	/*
	variables to get
	current:
	1) day number
	2) total members
	3) uncooked food
	4) sick
	5) medicine
	6) barricade
	
	variables are not yet defined but are used in the function, please define
	*/
	
	cout << "DAY " << dayNum << '\n';								 
	cout << "--------------------------------------------------\n";
	cout << "The colony has " << member << " members. \n";			 
	cout << "You have " << ration << " ration(s) of food. \n";
	cout << "You have " << uncooked << " uncooked food. \n"
	cout << sick << " member is sick. \n";
	cout << "You have " << medicine << " medicine. \n";
	cout << "You have " << barricade << " barricades. \n";
}

void Day::printStatus_find(){
	/*
	variables to get
	1) found rations
	2) found uncooked food
	3) found weapons
	4) found medicines
	5) total barricades
	
	variables are not yet defined but are used in the function, please define
	*/
	cout << "\nYour search party finds: \n";
	cout << "\t" << f_ration << " ration(s) of food\n";
	cout << "\t" << f_uncooked << " uncooked food\n";
	cout << "\t" << f_weap << " weapon(s)\n";
	cout << "\t" << f_med << " medicine(s)\n";
	cout << "The colony now has " << barricade << " barricade(s)\n";
}

void Day::printStatus_result(){
	/*
	variables to get
	1) healthy members
	2) total number of weapons
	3) total number of barricades
	4) number of zombies
	
	variables are not yet defined but are used in the function, please define
	*/
	cout << "Night falls.";
	cout << "You have " << healthy << " healthy members, ";
	cout << weapon << " weapon(s) and ";
	cout << barricade << " barricade(s). \n";
	
	cout << zombies << " zombies attacked in the night. \n";
	
	int res = healthy + weapon + barricade - zombies;
	if (res==0){
		cout << "You barely managed to hold them back.\n";
	}
	else if(res>0){
		cout << "Congratulations! You have successfully defended colony from the zombies.\n";
	}
	else {
		//lines to be printed when zombies > human
		//insert deathroll function here
	}
	
}

int* Day::getInput(){
	
	cout << "Number of ";
	
}





Day::Day(Colony *c) {
	// TODO Auto-generated constructor stub
	this->c=c;

}

Day::~Day() {
	// TODO Auto-generated destructor stub
}
