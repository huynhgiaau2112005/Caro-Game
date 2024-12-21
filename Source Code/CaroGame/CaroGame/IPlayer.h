#ifndef _I_PLAYER_H_
#define _I_PLAYER_H_

#include <string>

class IPlayer {
public:
	virtual std::string gameName() = 0;
};

#endif