#include <string>
using namespace std;
#ifndef SRC_PROJECT_H_
#define SRC_PROJECT_H_


class Project {
protected:
	int type;
	string name;
	int time;
	int duration;
public:
	Project(string,int,int);
	virtual ~Project();
	void advance(int);
	int timeLeft();
	bool isFinished();
	string toString();
};

#endif /* SRC_PROJECT_H_ */
