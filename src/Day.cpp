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

<<<<<<< HEAD
void Day::printStatus_init(){
	int dayNum = Colony.getDay();
	
	cout << "DAY " << dayNum << '\n';								 
	cout << "--------------------------------------------------\n"   
	cout << "The colony has " << member << " members. \n";			 
	cout << "You have " << ration << " ration(s) of food. \n";
	cout << "You have " << uncooked << " uncooked food. \n"
	cout << sick << " member is sick. \n";
=======
void Day::printStatus(){
	int member, ration, uncooked, weapon, sick, medicine, barricades;
	cout << "The colony has " << member << " members. \n";
	cout << "You have " << ration << " rations of food. \n";
	cout << "You have " << uncooked << " uncooked food. \n";
	cout << "You have " << weapon << " weapons. \n";
	cout << sick << " members are sick. \n";
>>>>>>> origin/master
	cout << "You have " << medicine << " medicine. \n";
	cout << "You have " << barricades << " barricades. \n";
}

void Day::printStatus_find(){
	int f_ration;
	int f_uncooked;
	int f_weap;
	int f_med;
	int barricade;
	cout << "\nYour search party finds: \n";
	cout << "\t" << f_ration << " ration(s) of food\n";
	cout << "\t" << f_uncooked << " uncooked food\n";
	cout << "\t" << f_weap << " weapon(s)\n";
	cout << "\t" << f_med << " medicine(s)\n";
	cout << "The colony now has " << barricade << " barricade(s)\n";
}

void Day::printStatus_result(){
	
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
		Day::printStatus_lose();
	}
	
}

void Day::printStatus_lose(){
	
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
