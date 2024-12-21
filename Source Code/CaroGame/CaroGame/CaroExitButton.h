#ifndef _CARO_EXIT_BUTTON_H_
#define _CARO_EXIT_BUTTON_H_

#include "Object.h"

#include <raylib.h>

class CaroExitButton : public Object {
private:
	Rectangle _dimensions;
	std::string _content;
public:
	CaroExitButton();
	CaroExitButton(Rectangle dimensions, std::string content);
public:
	Rectangle dimensions();
	std::string content();
public:
	void accept(IObjectHandler* handler);
	void onGamePlay() override;
	std::string toString() override;
};

#endif