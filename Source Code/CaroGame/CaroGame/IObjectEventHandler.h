#ifndef _I_OBJECT_HANDLER_H_
#define _I_OBJECT_HANDLER_H_

#include "IObjectHandler.h"

#include <string>

class IObjectEventHandler : public IObjectHandler {
public:
	virtual std::string eventName() = 0;
};

#endif