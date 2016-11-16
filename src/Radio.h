#ifndef SRC_RADIO_H_
#define SRC_RADIO_H_

#include "Project.h"

class Radio: public Project { //gonna try a singleton pattern
	using Project::Project;
	static Radio r;
	bool completed;
	static void reset();
	Radio();
public:
	virtual ~Radio();
	typedef Project super;
	static std::string toString();
	static Radio giveRadio();
	bool isCompleted();
};

#endif /* SRC_RADIO_H_ */
