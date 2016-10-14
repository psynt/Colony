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

	cout << "\n\n\n\tDAY " << dayNum << '\n';
	cout << "--------------------------------------------------\n";

	morningEvent();

	int member=c->getPeople();
	int ration=c->getRat();
	int uncooked=c->getUnc();
	int weapon=c->getWep();
	int sick=c->getSick();
	int medicine=c->getMed();
	int barricade = c->getBar();
	int cookBot = c->getCookB();
	int turret = c->getTur();
	int healthy = member - sick;
	int scrap=c->getScr();

	string grammar;

	grammar = (member == 1) ? "" : "s";
	cout << "The colony has " << member << " member" << grammar << ", ";
	grammar = (sick == 1) ? " is" : " are";
	cout << "of which " << sick << grammar << " sick.\n";
	grammar = (ration == 1) ? "" : "s";
	cout << "You have " << ration << " ration" << grammar << " of food.\n";
	cout << "You have " << uncooked << " uncooked food.\n";
	grammar = (weapon == 1) ? "" : "s";
	cout << "You have " << weapon << " weapon" << grammar << ".\n";
	cout << "You have " << medicine << " medicine.\n";
	grammar = (barricade == 1) ? "" : "s";
	cout << "You have " << scrap << " scrap.\n";
	cout << "You have " << barricade << " barricade" << grammar << ".\n";
	grammar = (cookBot == 1) ? "" : "s";
	cout << "You have " << cookBot << " cooking robot" << grammar << ".\n";
	grammar = (turret == 1) ? "" : "s";
	cout << "You have " << turret << " turret" << grammar << ".\n";
	cout << "\n";
	grammar = (healthy == 1) ? " is" : "s are";
	cout << "The " << healthy << " healthy member" << grammar << " ready to work.\n";
}

void Day::morningEvent() {
	// a random event may happen before the day's events
	// e.g. theft, new survivors, attack etc.

	if (EVENT_PARTY_JOIN > rand() % 100) {
		cout << "A member of the colony spots a small search party as they happen upon your base.\n";
		cout << "They are running low on supplies and struggling to survive. You offer for them to join your cause.\n";

		int surv = 2 + rand() % 5;
		int rat = surv + rand() % surv;
		int unc = rand() % surv;
		int wep = rand() % (surv + 1);
		int med = rand() % 3;

		//					 r 	 m	  u  w 	 p 	  sc 	c t d si b
		Colony *f=new Colony(rat,med,unc,wep,surv,0, 	0,0,1,0, 0);

//		c->setPeople(c->getPeople()+surv);
//		c->setRat(c->getRat()+rat);
//		c->setUnc(c->getUnc()+unc);
//		c->setWep(c->getWep()+wep);
//		c->setMed(c->getMed()+med);
		*c+=f;

		cout << "+" << surv << " survivors, +" << rat << " rations";
		if (unc > 0) cout << ", +" << unc << " uncooked food";
		if (wep > 0) cout << ", +" << wep << " weapons";
		if (med > 0) cout << ", +" << med << " medicine";
		cout << ".\n\n";
		delete f;
	}
}

void Day::eveningEvent() {
	// a random event may happen after the day's events
	// e.g. morale boost gets members to do something productive before bed
}

void Day::EndDay(){
	int member = c->getPeople();
	int sick = c->getSick();
	int ration = c->getRat();
	int sickcount = 0;

	c->setRat(ration - member); // reduce ration count

	if (member > ration) {
		int i = member - ration;
		c->setPeople(c->getPeople() - i);
		c->setSick(min(c->getSick(), i));

		cout << i << " members die of starvation.\n";
	}

	member = c->getPeople();
	sick = c->getSick();
	int healthy = member - sick;

	for( int i = 0; i < healthy; i++) {
		int sick_chance = CHANCE_SICK + (CHANCE_INCREASE * sick);
		int roll_sick = rand() % 100;

		if(roll_sick < sick_chance)
			sickcount++;
	}

	c->setSick(sick + sickcount);

	if (sickcount > 0)
		cout << sickcount << " members fall ill.\n";

	eveningEvent();

	c->incDay();
}

void Day::deathRoll(){
	int med = c->getMed();
	int sick = c->getSick();
	int healed = min(sick, med);

	if (healed > 0){
		c->setMed(med - healed);
		c->setSick(c->getSick() - healed);
		cout << healed << " sick members use medicine and recover.\n";
	}

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


	if (healed > 0) {
		c->setSick(c->getSick() - healed);
		cout << healed << " sick members have recovered naturally.\n";
	}


	if (dead > 0) {
		c->setPeople(c->getPeople() - dead);
		cout << dead << " sick members have died from illness.\n";
	}
}

int Day::zmult(int day){
	if(day<30) return 2;
	if(day<70) return 3;
	if(day<150) return 4;
	return 5;
}

void Day::printStatus_find(){

	if (c->getSick() < c->getPeople()) {
		int *inp = new int[ACTIVITIES];
		inp[0] = 0;
		inp[1] = 0;
		inp[2] = 0;

		getInput(inp);

		if (inp[0] > 0) {
			int* k =new int[SEARCHABLES];
			search(inp[0], k);

//			int f_ration = k[0];
//			int f_uncooked = k[1];
//			int f_weap = k[2];
//			int f_med = k[3];
//			int f_scr = k[4];
//			int f_surv = k[5];
			//					 r 	  m	   u 	w 	 p 	  sc 	c t d si b
			Colony *f=new Colony(k[0],k[3],k[1],k[2],k[5],k[4], 0,0,1,0, 0);

//			c->setMed(c->getMed()+f_med);
//			c->setWep(c->getWep()+f_weap);
//			c->setUnc(c->getUnc()+f_uncooked);
//			c->setRat(c->getRat()+f_ration);
//			c->setScr(c->getScr()+f_scr);
//			c->setPeople(c->getPeople()+f_surv);
			*c+=f;

			cout << "Your search party finds: \n";
			cout << "\t" << k[0] << " ration(s) of food\n";
			cout << "\t" << k[1] << " uncooked food\n";
			cout << "\t" << k[2] << " weapon(s)\n";
			cout << "\t" << k[3] << " medicine\n";
			cout << "\t" << k[4] << " scrap\n";
			cout << "\t" << k[5] << " survivor(s)\n";
			delete f;
		}

		if (inp[1] > 0) {
			c->setBar(c->getBar() + inp[1]);

			cout << "Your building party constructs " << inp[1] << " new barricades.\n";
		}

		if (inp[2] > 0) {
			int u = c->getUnc();
			int i = cookFood(inp[2], u);
			c->setRat(c->getRat() + i);
			c->setUnc(u);

			cout << "Your cooking party produces " << i << " rations of food, using " << i / UNC_FOOD_CONV << " uncooked food.\n";
		}

		cout << "\n";
	}
}

void Day::zombieBreakIn(int zombies)
{
	int p=c->getPeople();
	p-=zombies;
	if(p<0) p=0;
	cout << c->getPeople()-p << " members of the colony perish.\n";
	c->setPeople( p );
}

int Day::cookFood(int people, int &uncooked)
{
	if (DEBUG)
		cout << "cookFood() called with " << people << " people and " << uncooked << " uncooked.\n";

	int cooked = 0;

	cooked = min(COOK_SPEED * people, uncooked);
	uncooked -= cooked;
	cooked *= UNC_FOOD_CONV;

	if(DEBUG){
		cout << people << " people cooked " << cooked << " food using " << cooked / UNC_FOOD_CONV << " uncooked food.\n";
	}

	return cooked;
}

void Day::printStatus_result(){
	int weapon = c->getWep();
	int member = c->getPeople();
	int sick = c->getSick();
	int healthy = member - sick;
	int barricade = c->getBar();
	int turret = c->getTur();
	//int zombies = 1 + rand() % 3 + (1 + rand() % 3) * c->getDay();
	int zombies = c->getDay() + (rand() % c->getDay());

	cout << "Night falls.\n";
	cout << "You have " << healthy << " healthy members, ";
	cout << weapon << " weapon(s), ";
	cout << barricade << " barricade(s) and ";
	cout << turret << " turret(s).";

	cout << "\n\n" << zombies << " zombies attack in the night.\n";

	bool brokenIn=false;
	int turretKills = 0;

	for (int i = 0; i < turret; i++) {
		turretKills += TURRET_BASE;

		while (TURRET_SHOOT > rand() % 100) {
			turretKills++;
		}
	}

	if (turretKills > zombies) turretKills = zombies;

	if (turret > 0) cout << "Your turrets automatically gun down " << turretKills << " zombies.\n";

	int res = healthy + min(c->getWep(), healthy) + c->getBar() + turretKills - zombies;
	if (res == 0 || res == 1){
		cout << "You barely manage to hold them back.\n";
	}
	else if(res>0){
		cout << "You successfully defend the colony.\n";
	}
	else {
		res=-res;
		cout << res << " zombies break through your defenses.\n";
		brokenIn=true;
		zombieBreakIn(res);
		if(c->getPeople()<=0){ return; }
	}

	int barLoss = 0;
	int bL;

	if (barricade > 0){
		barLoss = rand() % barricade;
	}
	if (barLoss > zombies){
		barLoss=zombies;
	}
	bL = (brokenIn) ? barricade : barLoss;

	if (bL > 0)
		cout << bL << " barricades are destroyed in the attack.\n";

	c->setBar(barricade - bL);

	cout << "\n";
}

void Day::search(int people,int* search_arr){
	int ration = 0;
	int uncooked = 0;
	int weapon = 0;
	int medicine = 0;
	int scrap = 0;
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
		int roll_scr = rand() % 100;
		if (roll_scr < FIND_SCR){
			scrap++;
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
	search_arr[4]=scrap;
	search_arr[5]=survivor;
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
		if(search+prepare+cook>(c->getPeople()-c->getSick()) || search<0 || prepare<0 || cook<0){	// TODO: improve this code
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
	this->c=c;
}

Day::~Day() {
	delete c;
}
