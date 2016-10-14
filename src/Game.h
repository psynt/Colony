#include "Constants.h"
#include "Colony.h"
#include "Day.h"

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

class Game {

public:
	Game();
	~Game();
	void newGame();
//	void loadGame();
	void play(Colony colony, Day day);
};

#endif /* SRC_GAME_H_ */
