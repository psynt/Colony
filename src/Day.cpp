#include "Day.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <limits>

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
		cout << "\nCurrent projects:\n";
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

void Day::projInp(int* a,int p){
//	char t;
//	do{
//		cout<<"Do you want to want to change project status? (y/n)\n";
//
//		do{
//			cin >> t;
//			if(t=='N' || t=='n') return;
//		}while(t!='y' && t!='Y');
//
//		do{
//			cout<<"New project(n), assign workers to current projects(a), or cancel(c)?\n";
//			cin>>t;
//
//			//NEW PROJECT
//			if(strchr("nN",t)){
//				cout<<"Costs:\n";
//				cout<<"Turret: "<< TUR_C_SCRAP<<" scrap and "<<TUR_C_WEAPONS<<" weapons.\n";
//				cout<<"Cookbot: "<<HOB_C_SCRAP << " scrap.\n";
//				cout<<"Choose new project: Turret (t), cookbot(b), or cancel(c).\n";
//				do{
//					cin>>t;
//
//					//TURRET
//					if(strchr("tT",t)){
//						cout<<"Confirm new Turret project (y/n).\n";
//						do{
//							cin>>t;
//						}while(!strchr("ynYN",t));
//						if(strchr("Yy",t)){
//							if(c->getScr()<TUR_C_SCRAP || c->getWep()<TUR_C_WEAPONS){
//								cout<<"Not enough resources.\n";
//							}else{
//								c->setScr(c->getScr()-TUR_C_SCRAP);
//								c->setWep(c->getWep()-TUR_C_WEAPONS);
//								c->build(TUR_TYPE);
//							}
//						}
//					}
//
//					//AUTO_HOB
//					if(strchr("bB",t)){
//						cout<<"Confirm new CookBot project (y/n).\n";
//						do{
//							cin>>t;
//						}while(!strchr("ynYN",t));
//						if(strchr("Yy",t)){
//							if(c->getScr()<HOB_C_SCRAP){
//								cout<<"Not enough resources.\n";
//							}else{
//								c->setScr(c->getScr()-HOB_C_SCRAP);
//								c->build(HOB_TYPE);
//							}
//						}
//					}
//
//				}while(!strchr("tbcTBC",t));
//			}
//
//			// TODO: ASSIGN
//
//		}while(!strchr("nacNAC",t));
//
//	}while(true);

	//gonna try this again...


	bool good,cancel;

	string t;
	do{

		cout<<"Start new projects and/or assign " << p << " people to active ones.\n";
		cout<<"On a single line, input your command in the form (n) for new projects, (w) for assign workers to projects, (t) for turret, (b) for cookbot, (r) for radio.\n";
		cout<<"e.g. nt2b3wt10b5r20 adds 2 new turret projects, 3 new cookbot projects and assigns 10 workers to turrets, 5 workers to bots and 20 workers on the radio.\n";
		cout<<"Note that you may not start a new radio project, and also, you may only use as many people as you assigned to projects.\n";
		cout<<"Type a (c) to cancel"<<endl;

		cin>>ws;
		getline(cin,t);
		good=false;
		cancel=false;
		int state=0;//0 default 1 new 2 work
					//11 new turrets 12 new bots
					//21 work turrets 22 work bots 20 work radio
		int nr=0,newstate=0,up=0,us=0,uw=0,build[POSSIBLE_PROJECTS-1];
		for(int i=0 ; i<POSSIBLE_PROJECTS-1 ; i++) build[i]=0;
		for(size_t i=0 ; i<t.length() ; i++){
			if(strchr("cC",t[i])){
				build[0]=build[1]=a[0]=a[1]=a[2]=0;
				return;
			}
			if(strchr("0123456789",t[i])){
				nr=nr*10+(t[i]-'0');

			} else
			if(strchr("nN",t[i])){
				newstate=1;
//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
			} else
			if(strchr("Tt",t[i])){
				if(state==0){
					cout<<"Illegal input\n";
					cancel=true;
					break;
				}
				if(state>9) newstate=state/10%10*10+1;
				else newstate=state*10+1;
//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
			} else
			if(strchr("Ww",t[i])){
				newstate=2;
			} else
			if(strchr("Bb",t[i])){
				if(state==0){
					cout<<"Illegal input\n";
					cancel=true;
					break;
				}
				if(state>9) newstate=state/10%10*10+2;
				else newstate=state*10+2;
			} else
			if(strchr("Rr",t[i])){
				newstate=20;
			} else{
				cout<<"Did i not make myself clear?\n";
				break;
			}
			if(i == t.length()-1 || (state!=newstate && nr!=0)){
//				if(i == t.length()-1){
//					if(DEBUG)cout<<"Called at the end.\n";
//				}
//				if (DEBUG) cout<<"State = "<<state<<"\n";
//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
				int s1=state/10;
				state%=10;
//				if(s1==1 && state==0){
//					cout<<"Nonononono! No building new radios! You must try to repair the one you have.\n";
//					break;
//				}
				if(s1==2){
					if(DEBUG) cout<<"a["<<state<<"]="<<nr<<"\n";
					a[state]=nr;
					up+=nr;
					if(state == 0){
						us+=Project::getSCost(state)*nr;
					}
				} else
				if(s1==1){

					us+=Project::getSCost(state)*nr;
					if(state==1){
						uw+=TUR_C_WEAPONS*nr;
					}
					build[state-1]+=nr;
					if(DEBUG) cout<<"Nr = "<<nr<<"\n";
				}
				nr=0;
			}
			if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
			state=newstate;
		}
		if(up<=p && uw<=c->getWep() && us<=c->getScr()){
			if(DEBUG){
				cout<<"\nInput accepted.\n";
				cout<<"Build "<<build[0]<<" tur, "<<build[1]<<" hob.\n";
				cout<<"Assign "<<a[0]<<" , "<<a[1] << " , " <<a[2]<<"\n";
			}
			c->setWep(c->getWep()-uw);
			c->setScr(c->getScr()-us);
			for(int i=0 ; i<POSSIBLE_PROJECTS-1 ; i++){
				c->build(i+1,build[i]);
			}
			good=true;
		}else{
			cout<<"I don't like what you told me. I won't mention your insubordination to anybody, but please try to give me better input next time.\n";
		}
	}while(!(good && !cancel));


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
		int* proj= new int[POSSIBLE_PROJECTS];
		for(int i=0 ; i<ACTIVITIES ; i++) inp[i]=0;
		for(int i=0 ; i<POSSIBLE_PROJECTS ; i++) proj[i]=0;

		do{
			getInput(inp);

			if(inp[3]>0){
				projInp(proj,inp[3]);
				if(proj[0]==proj[1]==proj[2]==0){
					cout<<"Cancelled\n";
				}else{
					cout<<c->progressProjects(proj);
				}
			}
		}while(inp[3]>0 && (proj[0]==proj[1]==proj[2]==0));

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
			delete k;
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
		delete inp;
		delete proj;
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
	int totalStrength;

	while (i--) {
		zombies += (rand() % c->getDay());
	}


	cout << "Night falls.\n";
	cout << "You have " << healthy << " healthy members, ";
	cout << weapon << " weapon(s), ";
	cout << barricade << " barricade(s) and ";
	cout << turret << " turret(s).\n";

	if (DEBUG)
		cout << "[DEBUG] Total strength: " << totalStrength << "\n";

	cout << "\n" << zombies << " zombies attack in the night.\n";

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

	if (DEBUG)
		cout << "\n[DEBUG] Resolution: " << res << "\n";

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
    int total;
    int healthy = c->getPeople() - c->getSick();
	bool good,cancel;

	string t;
	do{
		do{
			a[0]=a[1]=a[2]=a[3]=0;
			cout<<"\nOn a single line, input your command in the form Search (s), Cook food (f), Barricades(b), Projects (p).\n";
			cout<<"e.g. s3f3b3p1 assigns 3 members to search, e members to cook, 3 to barricades and 1 to other projects.\n";
			cout<<"Type a (c) to cancel"<<endl;
			cin>>ws;
			getline(cin,t);
			good=true;
			cancel=false;
			int state=0;//0 default 1 search 3 cook 2 bar 4 proj
			int nr=0,newstate=0;
			for(size_t i=0 ; i<t.length() ; i++){
				if(strchr("cC",t[i])){
					cancel=true;
					break;
				} else
				if(strchr("0123456789",t[i])){
					nr=nr*10+(t[i]-'0');
					if(DEBUG) cout<<"Nr= "<<nr<<"\n";

				} else
				if(strchr("sS",t[i])){
					newstate=1;
	//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
				} else
				if(strchr("fF",t[i])){
					newstate=3;
	//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
				} else
				if(strchr("bB",t[i])){
					newstate=2;
	//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
				} else
				if(strchr("pP",t[i])){
					newstate=4;
	//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
				}
				if(i == t.length()-1 || (state!=newstate && nr!=0)){
	//				if(i == t.length()-1){
	//					if(DEBUG)cout<<"Called at the end.\n";
	//				}
	//				if (DEBUG) cout<<"State = "<<state<<"\n";
	//				if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
	//				if(s1==1 && state==0){
	//					cout<<"Nonononono! No building new radios! You must try to repair the one you have.\n";
	//					break;
	//				}
					if(DEBUG) cout<<"a["<<state-1<<"]="<<nr<<"\n";
					a[state-1]=nr;
					nr=0;
				}
				//if (DEBUG) cout<<"NewState = "<<newstate<<"\n";
				state=newstate;
			}
			total = a[0] + a[1] + a[2] + a[3] ;

			if (a[0] < 0 || a[1] < 0 || a[2] < 0 || a[3] < 0) {
				cout << "Bad input. Reconsider.\n";
				good=false;
			}
			if (total > healthy){
				cout << "Not enough people. Reconsider.\n";
				good=false;
			}
		}while(!(good && !cancel));

//    do {
//        cout << "Search: ";
//        while(!(cin >> search)){
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.  Try again: ";
//        }
//        cout << "Prepare defences: ";
//        while(!(cin >> prepare)){
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.  Try again: ";
//        }
//        cout << "Cook: ";
//        while(!(cin >> cook)){
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.  Try again: ";
//        }
//        cout << "Work on projects: ";
//        while(!(cin >> proj)){
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.  Try again: ";
//        }
//
//        cout << "\n";
//
//        total = search + prepare + cook + proj ;
//
//        if (search < 0 || prepare < 0 || cook < 0 || proj < 0) {
//            cout << "Bad input. Reconsider.\n";
//            continue;
//        }
//        if (total > healthy){
//            cout << "Not enough people. Reconsider.\n";
//            continue;
//        }

        cout << a[0] << " searching, "<< a[1] << " defending, " << a[2] << " cooking food and "<< a[3] <<" working on projects. \n";
        if (total < healthy)
            cout << healthy - total << " member(s) not assigned to a task.\n";

        cout << "Are you sure? (y/n)\n";
        cin >> ws;
		getline(cin,t);

    } while (t[0] != 'y' && t[0] != 'Y');
    cout << "\n\n";

}

Day::Day(Colony *c) {
    this->c=c;
}

Day::~Day() {
    delete c;
}
