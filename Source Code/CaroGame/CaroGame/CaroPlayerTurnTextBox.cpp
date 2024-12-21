#include "CaroPlayerTurnTextBox.h"
#include "IObjectHandler.h"
#include "ObjectHandlerFactory.h"
#include "CaroGamePlay.h"


CaroPlayerTurnTextBox::CaroPlayerTurnTextBox() {
	_title = "PLAYER TURN:";
	_player = nullptr;
}

CaroPlayerTurnTextBox::CaroPlayerTurnTextBox(CaroPlayerTurnTextBox& other) {
	_title = other._title;
	_player = new CaroPlayer(*other._player);
}

CaroPlayerTurnTextBox::~CaroPlayerTurnTextBox() {
	delete _player;
}

CaroPlayerTurnTextBox& CaroPlayerTurnTextBox:: operator= (CaroPlayerTurnTextBox& other) {
	if (this == &other) return *this;

	delete _player;
	_title = other._title;
	_player = new CaroPlayer(*other._player);

	return *this;
}

std::string CaroPlayerTurnTextBox::title() {
	return _title;
}
CaroPlayer* CaroPlayerTurnTextBox::player() {
	return _player;
}

void CaroPlayerTurnTextBox::setPlayerTurn(CaroPlayer* player) {
	_player = player;
}

void CaroPlayerTurnTextBox::accept(IObjectHandler* handler) {
	if (handler == nullptr) return;
	handler->handle(this);
}

void CaroPlayerTurnTextBox::onGamePlay() {
	setPlayerTurn(CaroGamePlay::instance()->playerInTurn());
	accept(ObjectHandlerFactory::getService("ObjectDisplayer"));
}

std::string CaroPlayerTurnTextBox::toString() {
	return "CaroPlayerTurnTextBox";
}