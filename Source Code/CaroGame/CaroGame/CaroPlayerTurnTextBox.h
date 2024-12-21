#ifndef _PLAYER_TURN_TEXT_BOX_H_
#define _PLAYER_TURN_TEXT_BOX_H_

#include "Object.h"
#include "CaroPlayer.h"

class CaroPlayerTurnTextBox : public Object {
private:
	std::string _title;
	CaroPlayer* _player;
public:
	CaroPlayerTurnTextBox();
	CaroPlayerTurnTextBox(CaroPlayerTurnTextBox&);
	~CaroPlayerTurnTextBox();
	CaroPlayerTurnTextBox& operator= (CaroPlayerTurnTextBox&);
public:
	std::string title();
	CaroPlayer* player();
	void setPlayerTurn(CaroPlayer*);
public:
	void accept(IObjectHandler*) override;
	void onGamePlay() override;
	std::string toString() override;
};

#endif