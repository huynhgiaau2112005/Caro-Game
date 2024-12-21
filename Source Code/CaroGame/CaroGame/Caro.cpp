#include "Caro.h"

Caro::Caro() {
	_gamePlay = CaroGamePlay::instance();
}

Caro::Caro(Caro& other) {
	_gamePlay = CaroGamePlay::instance();
}

Caro::~Caro() {
	// do nothing
}

Caro& Caro::operator= (Caro& other) {
	if (this == &other) return *this;

	_gamePlay = CaroGamePlay::instance();
	return *this;
}

CaroGamePlay* Caro::gamePlay() {
	return _gamePlay;
}

std::string Caro::gameName() {
	return "Caro";
}

