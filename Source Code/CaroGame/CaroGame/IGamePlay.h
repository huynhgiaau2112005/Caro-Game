#ifndef _I_GAME_PLAY_H_
#define _I_GAME_PLAY_H_

#include <string>

class IGamePlay {
public:
	virtual void play() = 0;
	virtual void quit() = 0;
	virtual std::string gameName() = 0;
};

#endif