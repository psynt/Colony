#include "Constants.h"
#include "Day.h"

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

class Game {
	Colony* colony;
	Day* day;
public:
	Game();
	Game(Colony* c, Day* d);
	~Game();
	void play();
};

#endif /* SRC_GAME_H_ */
