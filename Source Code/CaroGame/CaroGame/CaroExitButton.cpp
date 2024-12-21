#include "CaroExitButton.h"

#include "CaroExitButton.h"
#include "ObjectHandlerFactory.h"
#include "CaroGamePlay.h"

CaroExitButton::CaroExitButton() {
	_dimensions = { 887.5f, 626.0f, 260.3f, 88.2f };
	_content = "EXIT";
}

CaroExitButton::CaroExitButton(Rectangle dimensions, std::string content) {
	_dimensions = dimensions;
	_content = content;
}

Rectangle CaroExitButton::dimensions() {
	return _dimensions;
}

std::string CaroExitButton::content() {
	return _content;
}

void CaroExitButton::accept(IObjectHandler* handler) {
	if (handler == nullptr) return;
	handler->handle(this);
}

void CaroExitButton::onGamePlay() {
	accept(ObjectHandlerFactory::getService("ObjectDisplayer"));
	accept(ObjectHandlerFactory::getService("HoverOnObjectHandler"));
	accept(ObjectHandlerFactory::getService("ClickOnObjectHandler"));
}

std::string CaroExitButton::toString() {
	return "CaroExitButton";
}