#ifndef _CARO_BOARD_H_
#define _CARO_BOARD_H_

#include <vector>

#include "CaroCell.h"
#include "Object.h"

#include <raylib.h>

class CaroBoard : public Object {
private:
	std::vector<std::vector<CaroCell*>> _board;
public:
	CaroBoard() = default;
	CaroBoard(CaroBoard& other);
	~CaroBoard();
	CaroBoard& operator= (CaroBoard& other);
	CaroBoard(int height, int width, Rectangle topleftCellDimensions, char initValue);
public:
	CaroCell* cell(int i, int j);
	char value(int i, int j);
	void setValue(int i, int j, char value);
	int height();
	int width();
public:
	void accept(IObjectHandler*) override;
	void onGamePlay() override;
	std::string toString() override;
};

#endif