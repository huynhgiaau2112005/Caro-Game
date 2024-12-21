#include "CaroResetButton.h"
#include "ObjectHandlerFactory.h"
#include "CaroGamePlay.h"

CaroResetButton::CaroResetButton() {
	_dimensions = { 887.5f, 525.3f, 260.3f, 88.2f };
	_content = "RESET";
}

CaroResetButton::CaroResetButton(Rectangle dimensions, std::string content) {
	_dimensions = dimensions;
	_content = content;
}

Rectangle CaroResetButton::dimensions() {
	return _dimensions;
}

std::string CaroResetButton::content() {
	return _content;
}

void CaroResetButton::accept(IObjectHandler* handler) {
	if (handler == nullptr) return;
	handler->handle(this);
}

void CaroResetButton::onGamePlay() {
	accept(ObjectHandlerFactory::getService("ObjectDisplayer"));
	accept(ObjectHandlerFactory::getService("HoverOnObjectHandler"));
	accept(ObjectHandlerFactory::getService("ClickOnObjectHandler"));
}

std::string CaroResetButton::toString() {
	return "CaroResetButton";
}