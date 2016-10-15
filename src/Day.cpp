#include "Day.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
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
	int scrap=c->getScr();
	int barricade = c->getBar();
	int cookBot = c->getCookB();
	int turret = c->getTur();
	int healthy = member - sick;

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

	cout << "You have " << scrap << " scrap.\n";

	grammar = (barricade == 1) ? "" : "s";
	cout << "You have " << barricade << " barricade" << grammar << ".\n";

	grammar = (cookBot == 1) ? "" : "s";
	cout << "You have " << cookBot << " cooking robot" << grammar << ".\n";

	grammar = (turret == 1) ? "" : "s";
	cout << "You have " << turret << " turret" << grammar << ".\n";

	if(c->getNoPr()>0){

		cout << "\n";

		cout << "Current projects:\n";
		cout << c->printProjects();
	}

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
		int scr = rand() % 5;

//								r	 m	  u	   w	p	 sc	  c  t  d  si b
		Colony* f = new Colony(rat, med, unc, wep, surv, scr, 0, 0, 0, 0, 0);

		*c += f;

		cout << "+" << surv << " survivors, +" << rat << " rations";
		if (unc > 0) cout << ", +" << unc << " uncooked food";
		if (wep > 0) cout << ", +" << wep << " weapons";
		if (med > 0) cout << ", +" << med << " medicine";
		if (scr > 0) cout << ", +" << scr << " scrap";
		cout << ".\n\n";

		delete f;
	}
}

void Day::eveningEvent() {
	// a random event may happen after the day's events
	// e.g. morale boost gets members to do something productive before bed
}

void Day::projInp(int* a){
	char t;
	do{
		cout<<"Do you want to want to change project status? (y/n)\n";

		do{
			cin >> t;
			if(t=='N' || t=='n') return;
		}while(t!='y' && t!='Y');

		cout<<"New project(n), assign workers to current projects(a), or cancel(c)?\n";
		do{
			cin>>t;

			if(strchr("nN",t)){
				cout<<"Costs:\n";
				cout<<"Turret: "<< TUR_C_SCRAP<<" scrap and "<<TUR_C_WEAPONS<<" weapons.\n";
				cout<<"Cookbot: "<<HOB_C_SCRAP << "scrap.\n";
				cout<<"Choose new project: Turret (t), cookbot(b), or cancel(c).\n";
				do{
					cin>>t;

					if(strchr("tT",t)){
						do{
							cin>>t;
						}while(!strchr("ynYN",t));
						if(strchr("Yy",t)){
							c->build(TUR_TYPE);
						}
					}

				}while(!strchr("tbcTBC",t));
			}


		}while(!strchr("nacNAC",t));

	}while(true);

}

void Day::EndDay(){
	int member = c->getPeople();
	int sick = c->getSick();
	int ration = c->getRat();
	int sickcount = 0;

	c->setRat(ration - member); // reduce ration count

	if (member > ration) {
		int death = member - ration;
		c->setPeople(c->getPeople() - death);
		c->setSick(min(c->getSick(), death));

		cout << death << " members die of starvation.\n";
		c->setRat(0);
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
		string grammar;
		int* inp = new int[ACTIVITIES];
		inp[0] = 0;
		inp[1] = 0;
		inp[2] = 0;

		getInput(inp);

		if (inp[0] > 0) {
			int* k = new int[SEARCHABLES];
			search(inp[0], k);

//									r	  m		u	  w		p	  sc   c  t  d  si b
			Colony* f = new Colony(k[0], k[3], k[1], k[2], k[5], k[4], 0, 0, 0, 0, 0);

			*c += f;

			cout << "Your search party finds: \n";
			grammar = (k[0] == 1) ? "" : "s";
			cout << "\t" << k[0] << " ration" << grammar << " of food\n";
			cout << "\t" << k[1] << " uncooked food\n";
			grammar = (k[2] == 1) ? "" : "s";
			cout << "\t" << k[2] << " weapon" << grammar << "\n";
			cout << "\t" << k[3] << " medicine\n";
			cout << "\t" << k[4] << " scrap\n";
			grammar = (k[5] == 1) ? "" : "s";
			cout << "\t" << k[5] << " survivor" << grammar << "\n";

			delete f;
		}

		if (inp[1] > 0) {
			c->setBar(c->getBar() + inp[1]);

			grammar = (inp[1] == 1) ? "" : "s";
			cout << "Your building party constructs " << inp[1] << " new barricade" << grammar << ".\n";
		}

		if (c->getCookB() > 0) {
			int autoFood = cookFood(c->getCookB(), HOB_COOK_SPEED);
			c->setRat(c->getRat() + autoFood);

			cout << "Your cooking robots automatically produce " << autoFood << " rations of food, using " << autoFood / UNC_FOOD_CONV << " uncooked food.\n";
		}

		if (inp[2] > 0) {
			int manualFood = cookFood(inp[2], COOK_SPEED);
			c->setRat(c->getRat() + manualFood);

			cout << "Your cooking party produces " << manualFood << " rations of food, using " << manualFood / UNC_FOOD_CONV << " uncooked food.\n";
		}

		cout << "\n";
	}
}

void Day::zombieBreakIn(int zombies)
{
	int people = c->getPeople();
	string grammar1, grammar2;

	people -= zombies;
	if (people < 0) people = 0;

	if (people == 1) {
		grammar1 = "";
		grammar2 = "es";
	}
	else {
		grammar1 = "s";
		grammar2 = "";
	}

	cout << c->getPeople() - people << " member" << grammar1 << " of the colony perish" << grammar2 << ".\n";
	c->setPeople(people);
}

int Day::cookFood(int workers, int speed)
{
	int uncooked = c->getUnc();

	if (DEBUG)
		cout << "cookFood() called with " << workers << " workers, " << speed << " speed and " << uncooked << " uncooked food.\n";

	int cooked = 0;

	cooked = min(speed * workers, uncooked);
	uncooked -= cooked;
	c->setUnc(uncooked);
	cooked *= UNC_FOOD_CONV;

	if(DEBUG)
		cout << workers << " workers cooked " << cooked << " food using " << cooked / UNC_FOOD_CONV << " uncooked food.\n";

	return cooked;
}

void Day::printStatus_result(){
	int weapon = c->getWep();
	int member = c->getPeople();
	int sick = c->getSick();
	int healthy = member - sick;
	int barricade = c->getBar();
	int turret = c->getTur();
	int zombies = 0;
	int i = zmult(c->getDay());

	while (i--) {
		zombies += (rand() % c->getDay());
	}


	cout << "Night falls.\n";
	cout << "You have " << healthy << " healthy members, ";
	cout << weapon << " weapon(s), ";
	cout << barricade << " barricade(s) and ";
	cout << turret << " turret(s).";

	cout << "\n\n" << zombies << " zombies attack in the night.\n";

	bool brokenIn=false;
	int turretKills = 0;

	for (i = 0; i < turret; i++) {
		turretKills += TURRET_BASE;

		while (TURRET_SHOOT > rand() % 100) {
			turretKills++;
		}
	}

	if (turretKills > zombies) turretKills = zombies;

	if (turretKills > 0) cout << "Your turrets automatically gun down " << turretKills << " zombies.\n";

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
	int total;
	int healthy = c->getPeople() - c->getSick();
	char t;

	do {
		cout << "Search: ";
		cin >> search;
		cout << "Prepare defences: ";
		cin >> prepare;
		cout << "Cook: ";
		cin >> cook;

		cout << "\n";

		total = search + prepare + cook;

		if (search < 0 || prepare < 0 || cook < 0) {
			cout << "Bad input. Reconsider.\n";
			continue;
		}
		if (total > healthy){
			cout << "Not enough people. Reconsider.\n";
			continue;
		}

		cout << search << " searching, "<< prepare << " defending, " << cook << " cooking food.\n";
		if (total < healthy)
			cout << healthy - total << " member(s) not assigned to a task.\n";

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
