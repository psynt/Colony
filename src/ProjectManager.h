/*
 * ProjectManager.h
 *
 *  Created on: Oct 17, 2016
 *      Author: nichita
 */


#ifndef SRC_PROJECTMANAGER_H_
#define SRC_PROJECTMANAGER_H_

#include <vector>
#include <string>
#include "Project.h"
using namespace std;

class ProjectManager {
	std::vector<Project> **projects;
	void finishedProjects(int* a);
public:
	ProjectManager();
	virtual ~ProjectManager();
	string printProjects();
	void progressProjects(int *a);
	void build(int type,int number);
	int getNoPr();
};

#endif /* SRC_PROJECTMANAGER_H_ */
