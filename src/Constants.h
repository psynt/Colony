#include <string>

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEBUG 0

//initial resources
const int INITIAL_PEOPLE = 10;
const int INITIAL_FOOD = 2 * INITIAL_PEOPLE;
const int INITIAL_WEAPONS = 0;
const int INITIAL_SICK = 0;
const int INITIAL_MEDICINE = 0;
const int INITIAL_BARRICADES = 0;
const int INITIAL_UNCOOKED = 0;
const int INITIAL_SCRAP = 0;
const int INITIAL_COOKBOTS = 0;
const int INITIAL_TURRETS = 0;


//number of activities able to be done in a day
const int ACTIVITIES = 3;

//chances to find stuff in %
	const int SEARCHABLES = 6;		// # of different resources able to be found when searching
	const int FIND_RAT = 40;
	const int FIND_MED = 15;
	const int FIND_WEAP = 10;
	const int FIND_UNC = 50;
	const int FIND_SCR = 30;
	const int FIND_SURV = 5;

//chance of random events in %
const int EVENT_PARTY_JOIN = 5;

//sick details
const int CHANCE_SICK = 5;		// % static chance for each member to get sick each night
const int CHANCE_INCREASE = 5;	// % increase chance to get sick for each member already sick

//turret details
const int TURRET_BASE = 3;		// minimum zombies killed by each turret
const int TURRET_SHOOT = 60;	// % chance for turret to shoot again recursively

//cooking details
const int UNC_FOOD_CONV = 3;	// rations made from 1 uncooked food
const int HOB_COOK_SPEED=1;		// AutoHob cooked food per day
const int COOK_SPEED = 2;		// maximum uncooked food cooked by each cook

//Projects
	//Type
	const int TUR_TYPE = 1;
	const int HOB_TYPE = 2;
	//Names
	const std::string TURRET_N = "Turret";
	const std::string HOB_N = "Cooking Robot";
	//Costs
	const int TUR_C_SCRAP = 8;
	const int TUR_C_WEAPONS = 2;
	const int HOB_C = 4;
//	const int COST_RADIO = 25;
	//Time
	const int TUR_TIME = 20;
	const int HOB_TIME = 5;
	//QuickConstructor
#define TURRET TURRET_N,TUR_TIME,TUR_TYPE
#define AUTO_HOB HOB_N,HOB_TIME,HOB_TYPE



#endif /* CONSTANTS_H_ */
