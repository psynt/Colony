/*
 * Colony.cpp
 *
 *  Created on: 8 Oct 2016
 *      Author: zaxa1
 */

#include "Colony.h"
#include "Constants.h"

Colony::Colony() {
	// TODO Auto-generated constructor stub
	medicine=INITIAL_MEDICINE;
	rations = INITIAL_FOOD;
	weapons = INITIAL_WEAPONS;
	day=0;
	sick=0;
	people=INITIAL_PEOPLE;
}

Colony::~Colony() {
	// TODO Auto-generated destructor stub
}
void Colony::incDay(){
	day++;
}

int Colony::getPeople(){
	return people;
}
int Colony::getSick(){
	return sick;
}
int Colony::getRat(){
	return rations;
}
int Colony::getMed(){
	return medicine;
}
int Colony::getWep(){
	return weapons;
}
int Colony::getUnc(){
	return uncooked;
}
int Colony::getDay(){
	return day;
}

void Colony::setPeople(int people){
	this->people=people;
}

void Colony::setSick(int sick){
	this->sick=sick;
}
void Colony::setRat(int rations){
	this->rations=rations;
}
void Colony::setMed(int medicine){
	this->medicine=medicine;
}
void Colony::setWep(int weapons){
	this->weapons=weapons;
}
void Colony::setUnc(int uncooked){
	this->uncooked=uncooked;
}
void Colony::setBar(int b){
	barricade=b;
}
int Colony::getBar(){
	return barricade;
}
