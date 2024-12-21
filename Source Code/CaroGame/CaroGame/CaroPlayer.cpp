#include "CaroPlayer.h"

CaroPlayer::CaroPlayer(char symbol, Color color) {
	_symbol = symbol;
	_color = color;
}

char CaroPlayer::symbol() {
	return _symbol;
}

Color CaroPlayer::color() {
	return _color;
}

std::string CaroPlayer::gameName() {
	return "Caro";
}