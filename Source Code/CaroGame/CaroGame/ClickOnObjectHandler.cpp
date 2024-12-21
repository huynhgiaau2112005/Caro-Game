#include "ClickOnObjectHandler.h"

#include "CaroCell.h"
#include "CaroBoard.h"
#include "CaroGameRule.h"
#include "CaroResetButton.h"
#include "CaroGamePlay.h"
#include "CaroPlayerTurnTextBox.h"
#include "CaroExitButton.h"

#include <iostream>
#include <raylib.h>

void ClickOnObjectHandler::handle(CaroBoard* object) {
	for (int i = 0; i < object->height(); i++) {
		for (int j = 0; j < object->width(); j++) {
			if (CheckCollisionPointRec(GetMousePosition(), object->cell(i,j)->dimensions())) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					CaroGamePlay* gamePlay = CaroGamePlay::instance();
					CaroPlayer* playerInTurn = gamePlay->playerInTurn();

					if (CaroGameRule::isValidMove(playerInTurn, i, j, object)) {
						object->cell(i, j)->setValue(playerInTurn->symbol());
						if (CaroGameRule::isWinningMove(playerInTurn, i, j, object)) {
							gamePlay->setGameStatus(CARO_WIN);
						}
						else {
							gamePlay->increaseTurnCount(1);
						}
					}
				}
			}
		}
	}
}

void ClickOnObjectHandler::handle(CaroCell* object) {
	// TODO
}

void ClickOnObjectHandler::handle(CaroPlayerTurnTextBox* object) {
	// TODO
}

void ClickOnObjectHandler::handle(CaroResetButton* object) {
	if (CheckCollisionPointRec(GetMousePosition(), object->dimensions())) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			CaroGamePlay::instance()->reset();
		}
	}
}

void ClickOnObjectHandler::handle(CaroExitButton* object) {
	if (CheckCollisionPointRec(GetMousePosition(), object->dimensions())) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			CaroGamePlay::instance()->setGameStatus(CARO_EXIT);
		}
	}
}

std::string ClickOnObjectHandler::eventName() {
	return "ClickOnObjectHandler";
}