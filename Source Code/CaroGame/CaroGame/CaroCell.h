#ifndef _CARO_CELL_H_
#define _CARO_CELL_H_

#include "Object.h"

#include <raylib.h>

class CaroCell: public Object {
private:
	Rectangle _dimensions;
	char _value;
public:
	CaroCell() = default;
	CaroCell(Rectangle dimensions, char value);
public:
	Rectangle dimensions();
	char value();
	void setValue(char value);
public:
	void accept(IObjectHandler*) override;
	void onGamePlay() override;
	std::string toString() override;
};

#endif