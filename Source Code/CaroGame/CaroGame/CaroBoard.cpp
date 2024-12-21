#include "CaroBoard.h"
#include "IObjectHandler.h"
#include "ObjectHandlerFactory.h"
#include "CaroGamePlay.h"

CaroBoard::CaroBoard(CaroBoard& other) {
	for (int i = 0; i < other.height(); i++) {
		_board.push_back({});
		for (int j = 0; j < other.width(); j++) {
			_board[i].push_back(other._board[i][j]);
		}
	}
}

CaroBoard::~CaroBoard() {
	for (int i = 0; i < _board.size(); i++) {
		while (!_board[i].empty()) {
			delete _board[i].back();
			_board[i].pop_back();
		}
	}
}

CaroBoard& CaroBoard::operator= (CaroBoard& other) {
	if (this == &other) return *this;

	for (int i = 0; i < other.height(); i++) {
		_board.push_back({});
		for (int j = 0; j < other.width(); j++) {
			_board[i].push_back(other._board[i][j]);
		}
	}

	return *this;
}

CaroBoard::CaroBoard(int height, int width, Rectangle topleftCellDimensions, char initValue) {
	float posX = topleftCellDimensions.x, posY = topleftCellDimensions.y;
	float cellWidth = topleftCellDimensions.width, cellHeight = topleftCellDimensions.height;
	for (int i = 0; i < height; i++) {
		_board.push_back({});
		for (int j = 0; j < width; j++) {
			float thisX = posX + j * cellWidth;
			float thisY = posY + i * cellHeight;
			_board[i].push_back(new CaroCell({ thisX, thisY, cellWidth, cellHeight }, initValue));
		}
	}
}

CaroCell* CaroBoard::cell(int i, int j) {
	return _board[i][j];
}

char CaroBoard::value(int i, int j) {
	return _board[i][j]->value();
}

void CaroBoard::setValue(int i, int j, char value) {
	_board[i][j]->setValue(value);
}

int CaroBoard::height() {
	return _board.size();
}

int CaroBoard::width() {
	if (_board.empty()) return 0;
	return _board[0].size();
}

void CaroBoard::accept(IObjectHandler* handler) {
	if (handler == nullptr) return;
	handler->handle(this);
}

void CaroBoard::onGamePlay() {
	accept(ObjectHandlerFactory::getService("ObjectDisplayer"));
	accept(ObjectHandlerFactory::getService("HoverOnObjectHandler"));

	if (CaroGamePlay::instance()->gameStatus() == CARO_IS_PLAYING) {
		accept(ObjectHandlerFactory::getService("ClickOnObjectHandler"));
	}
}

std::string CaroBoard::toString() {
	return "CaroBoard";
}