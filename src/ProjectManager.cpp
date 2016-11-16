/*
 * ProjectManager.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: nichita
 */

#include "ProjectManager.h"
#include "Project.h"
#include "Constants.h"
#include "Radio.h"
#include <sstream>
#include <iostream>
using namespace std;


ProjectManager::ProjectManager() {
	// TODO Auto-generated constructor stub
	projects=new vector<Project>*[POSSIBLE_PROJECTS];
	for(int i=0 ; i<POSSIBLE_PROJECTS ; i++){
		projects[i]=new vector<Project>();
	}

	if(DEBUG){
		cout<<"made vector, pushing Radio"<<endl;
	}
	projects[RAD_TYPE]->push_back(Radio::giveRadio());
	if(DEBUG){
		//cout<<(new Project(RADIO))->toString()<<endl;
		cout<<"pushed Radio"<<endl;
		cout<<projects[RAD_TYPE]->at(0).toString()<<endl;
	}
}

ProjectManager::~ProjectManager() {
	// TODO Auto-generated destructor stub
}

string ProjectManager::printProjects(){
	ostringstream os;

	for(size_t i=0 ; i<POSSIBLE_PROJECTS ; i++){
			for(size_t j=0 ; j<projects[i]->size() ; j++){
//			if(DEBUG){
//				cout<<"Project "<<i<<" of "<<projects->size() << endl;
//			}
			os<< projects[i]->at(j).toString() << "\n";
		}

	}
	if(DEBUG){
		cout<<"Got here"<<endl;
	}

	string s=os.str();

	return s;
}

void ProjectManager::progressProjects(int *a){
	for(size_t i=0 ; i<POSSIBLE_PROJECTS ; i++){
			for(size_t j=0 ; j<projects[i]->size() && a[i]>0 ; j++){
				int adv=min(projects[i]->at(j).timeLeft(),a[i]);
				projects[i]->at(j).advance(adv);
				a[i]-=adv;
			}
	}
	finishedProjects(a);
}

void ProjectManager::finishedProjects(int *a){
	vector<Project>** np=new vector<Project>*[POSSIBLE_PROJECTS];
	for(size_t i=0 ; i<POSSIBLE_PROJECTS ; i++){
		a[i]=0;
		np[i]=new vector<Project>();
			for(size_t j=0 ; j<projects[i]->size() ; j++){
				if(projects[i]->at(j).isFinished()){
					a[i]++;
				}else{
					np[i]->push_back(projects[i]->at(j));
				}
			}
	}
	delete projects;
	projects=np;
}

void ProjectManager::build(int type,int number){
	while (number--){
		if(type == TUR_TYPE){
			projects[type]->push_back(Project(TURRET));
		}
		if(type == HOB_TYPE){
			projects[type]->push_back(Project(AUTO_HOB));
		}
	}
}
int ProjectManager::getNoPr(){
	int nr=0;
	for(int i=0 ; i<POSSIBLE_PROJECTS ; i++){
		nr+=projects[i]->size();
	}
	return nr;
}



