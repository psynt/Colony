/*
 * Day.cpp
 *
 *  Created on: Oct 8, 20 *      Author: nichita
 */

#include "Day.h"

#include <cstdlib>
#include <iostream>
#include <string>

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

	cout << "\n\n\n\tDAY " << dayNum << '\n';
	cout << "--------------------------------------------------\n";
	cout << "The colony has " << member << " members.\n";
	cout << sick << " members are sick. \n";
	cout << "You have " << ration << " ration(s) of food. \n";
	cout << "You have " << uncooked << " uncooked food. \n";
	cout << "You have " << weapon << " weapon(s)\n";
	cout << "You have " << medicine << " medicine. \n";
	cout << "You have " << barricade << " barricades. \n";
	cout << "The " << member - sick << " healthy members are ready to work.\n\n";
}

void Day::EndDay(){
	int member=c->getPeople();
	int sick=c->getSick();
	int ration=c->getRat();
	int healthy=member-sick;
	int sickcount=0;

	c->setRat(ration-member); //reduce ration count

	//loop to make healthy people sick, with increasing
	for( int i = 0; i < healthy; i++){
		int sick_chance=CHANCE_SICK+(CHANCE_INCREASE*sick);
		int roll_sick = rand() %100;
		if(roll_sick < sick_chance){
			sickcount++;
		}
	}

	c->setSick(sickcount);
	c->incDay();
}

void Day::deathRoll(){
	int med=c->getMed(),sick=c->getSick();
	int healed=med>sick?sick:med;
	cout<<healed<<" members healed by medicine\n";
	c->setMed(med-healed);


	int dead = 0;
	healed = 0;
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

	int *inp=new int[3];
    getInput(inp);
	int* k=new int[5];
	search(inp[0],k);
	int f_ration=k[0];
	int f_uncooked=k[1];
	int f_weap=k[2];
	int f_med=k[3];

	c->setMed(c->getMed()+f_med);
	c->setWep(c->getWep()+f_weap);
	c->setUnc(c->getUnc()+f_uncooked);
	c->setRat(c->getRat()+f_ration);

	if (inp[0] > 0) {
		cout << "Your search party finds: \n";
		cout << "\t" << f_ration << " ration(s) of food\n";
		cout << "\t" << f_uncooked << " uncooked food\n";
		cout << "\t" << f_weap << " weapon(s)\n";
		cout << "\t" << f_med << " medicine(s)\n";
	}

	c->setBar(c->getBar() + inp[1]);

	if (inp[1] > 0) {
		cout << "Your building party constructs " << inp[1] << " new barricades.\n";
	}

	int u = c->getUnc();
	int i = cookFood(inp[2], u);
	c->setRat(c->getRat() + i);
	c->setUnc(u);

	if (inp[2] > 0) {
		cout << "Your cooking party produces " << i << "rations of food, using " << i / 2 << " uncooked food.\n\n";
	}
}

void Day::zombieBreakIn(int zombies)
{
	c->setPeople(c->getPeople() - zombies);
	cout << zombies << " members of the colony perish.\n";
}

int Day::cookFood(int people, int &uncooked)
{
	int cooked = 0;

	cooked = min(2 * people, uncooked);
	uncooked-=cooked;

	if(DEBUG){
		cout<<people << " people cooked " <<2*cooked<<" food. "<<uncooked<<" uncooked food remains.\n";
	}

	return 2*cooked;
}

void Day::printStatus_result(){
	int weapon = c->getWep();
	int member = c->getPeople();
	int sick = c->getSick();
	int healthy = member - sick;
	int barricade = c->getBar();
	int zombies = 1 + rand() % 3 + (1 + rand() % 3) * c->getDay();

	cout << "Night falls.\n";
	cout << "You have " << healthy << " healthy members, ";
	cout << weapon << " weapon(s) and ";
	cout << barricade << " barricade(s).\n\n";
	cout << zombies << " zombies attack in the night.\n";



	int res = healthy + (healthy>c->getWep()?c->getWep():healthy) + c->getBar() - zombies;
	if (res==0){
		cout << "You barely manage to hold them back.\n";
	}
	else if(res>0){
		cout << "You successfully defend the colony.\n";
	}
	else {
		cout << res << " zombies break through your defences.\n";

		Day::zombieBreakIn(res);
	}

	int barLoss = rand() % barricade;
	int bL = (barLoss > zombies) ? zombies : barLoss;

	cout << bL << " barricades are destroyed in the attack.\n";

	c->setBar(barricade - bL);
}

void Day::search(int people,int* search_arr){
	int ration = 0;
	int uncooked = 0;
	int weapon = 0;
	int medicine = 0;
	int survivor = 0;

	for(int i = 0; i < people; i++){
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
		int roll_surv = rand() % 100;
		if(roll_surv < FIND_SURV){
			survivor++;
		}
	}
	search_arr[0]=ration;
	search_arr[1]=uncooked;
	search_arr[2]=weapon;
	search_arr[3]=medicine;
	search_arr[4]=survivor;
}

void Day::getInput(int* a){
	int cook, prepare, search;
	char t;
	do {
		cout << "Search: ";
		cin >> search;
		cout << "Prepare defences: ";
		cin >> prepare;
		cout << "Cook: ";
		cin >> cook;
		if(search+prepare+cook>(c->getPeople()-c->getSick()) || search<0 || prepare<0 || cook<0){
			cout<<"Bad decisions. Reconsider.\n";
			continue;
		}
		cout << search << " searching, "<< prepare << " defending, " << cook << " cooking food\n";
		cout << "Are you sure? (y/n)\n";
		cin >> t;
		cout << "\n\n";

	} while (t != 'y' && t != 'Y');

	a[0] = search;
	a[1] = prepare;
	a[2] = cook;
}

Day::Day(Colony *c) {
	// TODO Auto-generated constructor stub
	this->c=c;

}

Day::~Day() {
	delete c;
	// TODO Auto-generated destructor stub
}
