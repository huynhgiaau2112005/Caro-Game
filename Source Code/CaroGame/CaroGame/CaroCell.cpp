#include "CaroCell.h"
#include "IObjectHandler.h"

CaroCell::CaroCell(Rectangle dimensions, char value) : _dimensions(dimensions), _value(value) {}

Rectangle CaroCell::dimensions() {
	return _dimensions;
}

char CaroCell::value() {
	return _value;
}

void CaroCell::setValue(char value) {
	_value = value;
}

void CaroCell::accept(IObjectHandler* handler) {
	if (handler == nullptr) return;
	handler->handle(this);
}

void CaroCell::onGamePlay() {
	// TODO
}

std::string CaroCell::toString() {
	return "CaroCell";
}