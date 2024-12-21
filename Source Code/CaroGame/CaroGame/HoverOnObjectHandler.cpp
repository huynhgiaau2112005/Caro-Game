#include "HoverOnObjectHandler.h"
#include "CaroCell.h"
#include "CaroBoard.h"
#include "CaroPlayerTurnTextBox.h"
#include "CaroResetButton.h"
#include "CaroGamePlay.h"
#include "CaroExitButton.h"

#include <raylib.h>

void HoverOnObjectHandler::handle(CaroBoard* object) {
	for (int i = 0; i < object->height(); i++) {
		for (int j = 0; j < object->width(); j++) {
			handle(object->cell(i, j));
		}
	}
}

void HoverOnObjectHandler::handle(CaroCell* object) {
	Color hoveringColor = CaroGamePlay::instance()->playerInTurn()->color();

	if (CheckCollisionPointRec(GetMousePosition(), object->dimensions())) {
		DrawRectangleRec(object->dimensions(), Fade(hoveringColor, 0.3f));
	}
}

void HoverOnObjectHandler::handle(CaroPlayerTurnTextBox* object) {
	// TODO
}

void HoverOnObjectHandler::handle(CaroResetButton* object) {
	if (CheckCollisionPointRec(GetMousePosition(), object->dimensions())) {
		DrawRectangleRec(object->dimensions(), Fade(GREEN, 0.3f));
	}
}

void HoverOnObjectHandler::handle(CaroExitButton* object) {
	if (CheckCollisionPointRec(GetMousePosition(), object->dimensions())) {
		DrawRectangleRec(object->dimensions(), Fade(GREEN, 0.3f));
	}
}

std::string HoverOnObjectHandler::eventName() {
	return "HoverOnObjectHandler";
}