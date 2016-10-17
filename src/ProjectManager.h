/*
 * ProjectManager.h
 *
 *  Created on: Oct 17, 2016
 *      Author: nichita
 */

#include <vector>
#include <string>
#include "Project.h"
using namespace std;

#ifndef SRC_PROJECTMANAGER_H_
#define SRC_PROJECTMANAGER_H_

class ProjectManager {
	std::vector<Project> **projects;
	string finishedProjects();
public:
	ProjectManager();
	virtual ~ProjectManager();
	string printProjects();
	string progressProjects(int *a, int n);
	void build(int type,int number);
	int getNoPr();
};

#endif /* SRC_PROJECTMANAGER_H_ */
