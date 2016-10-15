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
	projects=new vector<Project>();

	if(DEBUG){
		cout<<"made vector, pushing Radio"<<endl;
	}

	projects->push_back(Radio::giveRadio());
	if(DEBUG){
		//cout<<(new Project(RADIO))->toString()<<endl;
		cout<<"pushed Radio"<<endl;
	}
}

string Colony::printProjects(){
	ostringstream os;

	for(size_t i=0 ; i<projects->size() ; i++){
		if(DEBUG){
			cout<<"Project "<<i<<" of "<<projects->size() << endl;
		}
		os << i+1 << ": " << projects->at(i).toString() << "\n";

	}
	if(DEBUG){
		cout<<"Got here"<<endl;
	}

	string s=os.str();

	return s;
}

string Colony::progressProjects(int *a, int n){
	for(int i=0 ; i<n ; i++){
		projects->at(i).advance(a[i]);
	}
	return finishedProjects();
}

string Colony::finishedProjects(){
	ostringstream os;
	vector<Project>* np=new vector<Project>();
	for (size_t i = 0; i < projects->size() ; ++i) {
		if(projects->at(i).isFinished()){
			os<<"Project " << i+1 << ", working on " << projects->at(i).toString() <<" \n";
		}else{
			np->push_back(projects->at(i));
		}
	}
	delete projects;
	projects=np;
	return os.str();
}

void Colony::build(int type){
	if(type == TUR_TYPE){
		projects->push_back(Project(TURRET));
	}
	if(type == HOB_TYPE){
		projects->push_back(Project(AUTO_HOB));
	}
}
int Colony::getNoPr(){
	return projects->size();
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
