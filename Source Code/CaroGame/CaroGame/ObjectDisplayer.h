#ifndef _OBJECT_DISPLAYER_H_
#define _OBJECT_DISPLAYER_H_

#include "IObjectHandler.h"

class ObjectDisplayer : public IObjectHandler {
public:
	void handle(CaroBoard* object) override;
	void handle(CaroCell* object) override;
	void handle(CaroPlayerTurnTextBox* object) override;
	void handle(CaroResetButton* object) override;
	void handle(CaroExitButton* object) override;
};

#endif