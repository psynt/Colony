/*
 * Constants.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

const int INITIAL_PEOPLE = 10;
const int INITIAL_FOOD = 2*INITIAL_PEOPLE;
const int INITIAL_WEAPONS = 0;
const int INITIAL_SICK = 0;
const int INITIAL_MEDICINE = 0;
const int INITIAL_BARRICADES = 0;
#define DEBUG 1

//chances for finding stuff in %
const int FIND_RAT = 40;
const int FIND_MED = 20;
const int FIND_WEAP = 10;
const int FIND_UNC = 50;
const int FIND_SURV = 2;

//chance of getting sick at the end of day
const int CHANCE_SICK = 20;
const int CHANCE_INCREASE = 6; //increased sick chance per sick person in colony



#endif /* CONSTANTS_H_ */
