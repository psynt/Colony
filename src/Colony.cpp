#include "Colony.h"
#include "Radio.h"
#include "Project.h"
#include "Constants.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

Colony::Colony(int r, int m, int u, int w, int p, int sc, int c, int t, int d, int si, int b){
	medicine=m;
	rations = r;
	weapons = w;
	day=d;
	uncooked=u;
	sick=si;
	people=p;
	barricade=b;
	scrap = sc;
	cookBots = c;
	turrets = t;
	pm=ProjectManager();
}

string Colony::printProjects(){
	return pm.printProjects();
}

string Colony::progressProjects(int *a){
	pm.progressProjects(a);
	ostringstream os;
	os<<"Projects finished: "<<a[1]<<" Turrets and "<<a[2]<<" cookbots.\n";
	addBot(a[2]);
	addTur(a[1]);
	if(DEBUG) cout<<"Projects finished: "<<a[1]<<" Turrets and "<<a[2]<<" cookbots.\n";
	if(a[0]){
		Radio::giveRadio().isCompleted();
		os<<"Also, the Radio should be working now.\n";
	}
	return os.str();
}
void Colony::addBot(int b){
	cookBots+=b;
}

void Colony::addTur(int t){
	turrets+=t;
}

void Colony::build(int type,int number){
	pm.build(type,number);
}
int Colony::getNoPr(){
	return pm.getNoPr();
}

void Colony::operator+=(Colony *c){
	medicine+=c->medicine;
	rations+=c->rations;
	weapons+=c->weapons;
	uncooked+=c->uncooked;
	sick+=c->sick;
	people+=c->people;
	barricade+=c->barricade;
	scrap+=c->scrap;
	cookBots+=c->cookBots;
	turrets+=c->turrets;

	day = day>c->day?day:c->day;
}

Colony::~Colony() {
	//important destructor
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

int Colony::getScr() {
	return scrap;
}

int Colony::getCookB() {
	return cookBots;
}

int Colony::getTur() {
	return turrets;
}

void Colony::setScr(int s) {
	this->scrap = s;
}

void Colony::setCookB(int c) {
	this->cookBots = c;
}

void Colony::setTur(int t) {
	this->turrets = t;
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
