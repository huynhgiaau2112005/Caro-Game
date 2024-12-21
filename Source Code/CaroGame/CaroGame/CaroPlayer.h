#ifndef _CARO_PLAYER_H_
#define _CARO_PLAYER_H_

#include "IPlayer.h"

#include <string>
#include <raylib.h>

class CaroPlayer: public IPlayer {
private:
	char _symbol;
	Color _color;
public:
	CaroPlayer() = default;
	CaroPlayer(CaroPlayer&) = default;
	~CaroPlayer() = default;
	CaroPlayer& operator= (CaroPlayer&) = default;
	CaroPlayer(char symbol, Color color);
	char symbol();
	Color color();
public:
	std::string gameName() override;
};

#endif