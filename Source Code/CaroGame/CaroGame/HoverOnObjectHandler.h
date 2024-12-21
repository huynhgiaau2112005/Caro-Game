#ifndef _HOVER_ON_OBJECT_HANDLER_H_
#define _HOVER_ON_OBJECT_HANDLER_H_

#include "IObjectEventHandler.h"

class HoverOnObjectHandler : public IObjectEventHandler {
public:
	void handle(CaroBoard* object) override;
	void handle(CaroCell* object) override;
	void handle(CaroPlayerTurnTextBox* object) override;
	void handle(CaroResetButton* object) override;
	void handle(CaroExitButton* object) override;
	std::string eventName() override;
};

#endif