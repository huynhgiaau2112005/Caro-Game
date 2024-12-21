#ifndef _CARO_RESET_BUTTON_H_
#define _CARO_RESET_BUTTON_H_

#include "Object.h"

#include <raylib.h>

class CaroResetButton : public Object {
private:
	Rectangle _dimensions;
	std::string _content;
public:
	CaroResetButton();
	CaroResetButton(Rectangle dimensions, std::string content);
public:
	Rectangle dimensions();
	std::string content();
public:
	void accept(IObjectHandler* handler);
	void onGamePlay() override;
	std::string toString() override;
};

#endif