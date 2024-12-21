#ifndef _GAME_H_
#define _GAME_H_

#include <string>

class IGame {
public:
	virtual std::string gameName() = 0;
};

#endif