#ifndef _I_OBJECT_HANDLER_
#define _I_OBJECT_HANDLER_

class CaroBoard;
class CaroCell;
class CaroPlayerTurnTextBox;
class CaroResetButton;
class CaroExitButton;

class IObjectHandler {
public:
	virtual void handle(CaroBoard* object) = 0;
	virtual void handle(CaroCell* object) = 0;
	virtual void handle(CaroPlayerTurnTextBox* object) = 0;
	virtual void handle(CaroResetButton* object) = 0;
	virtual void handle(CaroExitButton* object) = 0;
};

#endif