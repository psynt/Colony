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

//chances for finding stuff in %
const int FIND_RAT = 40;
const int FIND_MED = 20;
const int FIND_WEAP = 10;
const int FIND_UNC = 50;
const int FIND_SURV = 5;

//chance of getting sick at the end of day in %
const int CHANCE_SICK = 5;
const int CHANCE_INCREASE = 5;

//likelihood of random events in %
const int EVENT_PARTY_JOIN = 5;

//cooking details
const int UNC_FOOD_CONV = 3;	//rations made from 1 uncooked food
const int COOK_SPEED = 2;		//maximum uncooked food cooked by each cook


#endif /* CONSTANTS_H_ */
