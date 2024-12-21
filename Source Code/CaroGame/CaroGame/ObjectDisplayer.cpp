#include "ObjectDisplayer.h"

#include "CaroCell.h"
#include "CaroBoard.h"
#include "CaroPlayerTurnTextBox.h"
#include "CaroResetButton.h"
#include "CaroGamePlay.h"
#include "CaroExitButton.h"

#include <iostream>
#include <raylib.h>

void ObjectDisplayer::handle(CaroBoard* object) {
	for (int i = 0; i < object->height(); i++) {
		for (int j = 0; j < object->width(); j++) {
			handle(object->cell(i, j));
		}
	}
	std::vector<std::pair<int, int>> winningLine = CaroGamePlay::instance()->winningLine();
	for (auto pos : winningLine) {
		int i = pos.first, j = pos.second;
		DrawRectangleRec(object->cell(i, j)->dimensions(), Fade(GREEN, 0.3f));
	}
}

void ObjectDisplayer::handle(CaroCell* object) {
	if (object == nullptr) return;

	DrawRectangleRec(object->dimensions(), RAYWHITE);

	DrawRectangleLinesEx(object->dimensions(), 0.7f, BLACK);

	std::string text = std::string(1, object->value());
	int fontSize = object->dimensions().height;
	int textWidth = MeasureText(text.c_str(), fontSize);
	int textX = object->dimensions().x + (object->dimensions().width - textWidth) / 2;
	int textY = object->dimensions().y;

	Color textColor = (object->value() == 'X') ? RED : BLUE;

	DrawText(text.c_str(), textX, textY, fontSize, textColor);
}

void ObjectDisplayer::handle(CaroPlayerTurnTextBox* object) {
	std::string title;
	int gameStatus = CaroGamePlay::instance()->gameStatus();

	if (gameStatus == CARO_WIN) {
		title = " THE WINNER:";
	}
	else {
		title = object->title();
	}

	std::string symbol = std::string(1, object->player()->symbol());

	Color textColor = CaroGamePlay::instance()->playerInTurn()->color();

	DrawText(title.c_str(), 870, 300, 40, textColor);
	DrawText(symbol.c_str(), 980, 345, 120, textColor);
}

void ObjectDisplayer::handle(CaroResetButton* object) {
	Rectangle buttonBox = object->dimensions();
	DrawRectangleRec(buttonBox, Fade(ORANGE, 0.8f));
	DrawRectangleLinesEx(object->dimensions(), 3.0f, BLACK);

	std::string text = object->content();
	int fontSize = 50;
	int textWidth = MeasureText(text.c_str(), fontSize);
	Vector2 textPos = {
			buttonBox.x + (buttonBox.width - textWidth) / 2,
			buttonBox.y + (buttonBox.height - fontSize) / 2
	};

	DrawText(object->content().c_str(), textPos.x, textPos.y, fontSize, BLACK);
}

void ObjectDisplayer::handle(CaroExitButton* object) {
	Rectangle buttonBox = object->dimensions();
	DrawRectangleRec(buttonBox, Fade(RED, 0.8f));
	DrawRectangleLinesEx(object->dimensions(), 3.0f, BLACK);

	std::string text = object->content();
	int fontSize = 50;
	int textWidth = MeasureText(text.c_str(), fontSize);
	Vector2 textPos = {
			buttonBox.x + (buttonBox.width - textWidth) / 2,
			buttonBox.y + (buttonBox.height - fontSize) / 2
	};

	DrawText(object->content().c_str(), textPos.x, textPos.y, fontSize, BLACK);
}