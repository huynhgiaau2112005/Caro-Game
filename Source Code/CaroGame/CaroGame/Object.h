#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "IObjectHandler.h"

#include <string>

class Object {
public:
	virtual void accept(IObjectHandler*) = 0;
	virtual void onGamePlay() = 0;
	virtual std::string toString() = 0;
};

#endif