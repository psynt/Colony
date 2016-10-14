/*
 * Constants.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

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
const int COOK_SPEED = 2;		// maximum uncooked food cooked by each cook


#endif /* CONSTANTS_H_ */
