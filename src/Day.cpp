/*
 * Day.cpp
 *
 *  Created on: Oct 8, 20 *      Author: nichita
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Day.h"
#include "People.h"
#include "Colony.h"
#include "Constants.h"

using namespace std;

void Day::printStatus_init(){
	int dayNum=c->getDay();
	int member=c->getPeople();
	int ration=c->getRat();
	int uncooked=c->getUnc();
	int weapon=c->getWep();
	int sick=c->getSick();
	int medicine=c->getMed();
	int barricade = c->getBar();
	
	cout << "DAY " << dayNum << '\n';								 
	cout << "--------------------------------------------------\n";
	cout << "The colony has " << member << " members. \n";			 
	cout << "You have " << ration << " ration(s) of food. \n";
	cout << "You have " << uncooked << " uncooked food. \n";
	cout << "You have " << weapon << " weapon(s)\n";
	cout << "You have " << medicine << " medicine. \n";
	cout << "You have " << barricade << " barricades. \n";
	cout << sick << " members are sick. \n";
}

void Day::deathRoll(){
	int dead = 0;
	int healed = 0;
	for(int i = 0; i < c->getSick(); i++){
		int roll = rand() % 7 + 1;
		if (roll == 1){
			dead++;
		}else if (roll == 7){
			healed++;
		}
	}
	cout << dead << " sick colony members have died. \n";
	cout << healed << " sick members have recovered. \n";
	c->setPeople(c->getPeople()-dead);
	c->setSick(c->getSick()-healed);
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
	cout << "The colony now has " << c->getBar() << " barricade(s)\n";
}

void Day::zombieBreakIn(int zombies)
{
	c->setPeople(c->getPeople() - zombies);
	cout << zombies << " members of the colony perish.\n";
}

void Day::printStatus_result(){
	int weapon=c->getWep();
	int member=c->getPeople();
	int ration=c->getRat();
	int uncooked=c->getUnc();
	int sick=c->getSick();
	int medicine=c->getMed();
	/*
	variables to get
	1) healthy members
	2) total number of weapons
	3) total number of barricades
	4) number of zombies
	
	variables are not yet defined but are used in the function, please define
	*/
	int healthy=member-sick;
	int barricade;
	int zombies;
	
	cout << "Night falls.";
	cout << "You have " << healthy << " healthy members, ";
	cout << weapon << " weapon(s) and ";
	cout << barricade << " barricade(s). \n";
	cout << zombies << " zombies attack in the night. \n";
	
	int res = healthy + c->getWep() + c->getBar() - zombies;
	if (res==0){
		cout << "You barely manage to hold them back.\n";
	}
	else if(res>0){
		cout << "You have successfully defend the colony.\n";
	}
	else {
		cout << res << " zombies break through your defences.\n";

		Day::zombieBreakIn(res);
	}
	
}

int* Day::search(){
	int ration = 0;
	int uncooked = 0;
	int weapon = 0;
	int medicine = 0;
	//PLEASE CHANGE NEXT LINE
	int NumSearch = 3; //PLEASE CHANGE THIS LINE TO CALLING THE NUMBER OF PEOPLE ALLOCATED TO SEARCH
	for(int i = 0; i < NumSearch; i++){
		int roll_rat = rand() % 100;
		if (roll_rat < FIND_RAT ){
			ration++;
		}
		int roll_unc = rand() % 100;
		if (roll_unc < FIND_UNC){
			uncooked++;
		}
		int roll_weap = rand() % 100;
		if (roll_weap < FIND_WEAP){
			weapon++;
		}
		int roll_med = rand() % 100;
		if (roll_med < FIND_MED){
			medicine++;
		}
	}
	int search_arr[4];
	search_arr[0]=ration;
	search_arr[1]=uncooked;
	search_arr[2]=weapon;
	search_arr[3]=medicine;
	return search_arr;
}

int* Day::search(){
	int ration = 0;
	int uncooked = 0;
	int weapon = 0;
	int medicine = 0;
	//PLEASE CHANGE NEXT LINE
	int NumSearch = 3; //PLEASE CHANGE THIS LINE TO CALLING THE NUMBER OF PEOPLE ALLOCATED TO SEARCH
	for(int i = 0; i < NumSearch; i++){
		int roll_rat = rand() % 100;
		if (roll_rat < FIND_RAT ){
			ration++;
		}
		int roll_unc = rand() % 100;
		if (roll_unc < FIND_UNC){
			uncooked++;
		}
		int roll_weap = rand() % 100;
		if (roll_weap < FIND_WEAP){
			weapon++;
		}
		int roll_med = rand() % 100;
		if (roll_med < FIND_MED){
			medicine++;
		}
	}
	int search_arr[4];
	search_arr[0]=ration;
	search_arr[1]=uncooked;
	search_arr[2]=weapon;
	search_arr[3]=medicine;
	return search_arr;
}

int* Day::getInput(){
	int cook, prepare, search;
	char t;
	do{
		cout << "Everybody is ready to work.";
		cout << "\nSearch: ";
		cin >> search;
		cout << "\nPrepare defences: ";
		cin >> prepare;
		cout << "\nCook: ";
		cin >> cook;
		if(search+prepare+cook>(c->getPeople()-c->getSick()) || search<0 || prepare<0 || cook<0){
			cout<<"Bad input. please reconsider\n";
			continue;
		}
		cout << search << " searching, "<< prepare << " defending, " << cook << "cooking food\n";
		cout<<"Happy? (y/n)\n";
		cin>>t;

	}while(t!="y" && t!="Y");
	

	int a[3];
	a[0]=search;
	a[1]=prepare;
	a[2]=cook;
	
	return a;
}

Day::Day(Colony *c) {
	// TODO Auto-generated constructor stub
	this->c=c;

}

Day::~Day() {
	delete c;
	// TODO Auto-generated destructor stub
}
