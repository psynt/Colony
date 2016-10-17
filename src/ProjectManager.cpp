/*
 * ProjectManager.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: nichita
 */

#include "ProjectManager.h"
#include "Constants.h"

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
			os << i+1 << ": " << projects[i]->at(j).toString() << "\n";
		}

	}
	if(DEBUG){
		cout<<"Got here"<<endl;
	}

	string s=os.str();

	return s;
}

string ProjectManager::progressProjects(int *a, int n){
	for(size_t i=0 ; i<POSSIBLE_PROJECTS ; i++){
			for(size_t j=0 ; j<projects[i]->size() ; j++){
					projects[i]->at(j).advance(a[i]);
			}
	}
	return finishedProjects();
}

string ProjectManager::finishedProjects(){
	ostringstream os;
	vector<Project>** np=new vector<Project>*[POSSIBLE_PROJECTS];
	for(size_t i=0 ; i<POSSIBLE_PROJECTS ; i++){
		np[i]=new vector<Project>();
			for(size_t j=0 ; j<projects[i]->size() ; j++){
				if(projects[i]->at(j).isFinished()){
					os<<"Project " << i+1 << ", working on " << projects[i]->at(j).toString() <<" \n";
				}else{
					np[i]->push_back(projects[i]->at(j));
				}
			}
	}
	delete projects;
	projects=np;
	return os.str();
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



