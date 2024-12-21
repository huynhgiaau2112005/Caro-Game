#ifndef _OBJECT_HANDLER_FACTORY_H_
#define _OBJECT_HANDLER_FACTORY_H_

#include "IObjectHandler.h"

#include <iostream>
#include <string>
#include <map>

class ObjectHandlerFactory {
private:
	static std::map<std::string, IObjectHandler*> _services;
public:
	static void config();

	template<typename T>
	static void registerService(std::string serviceName) {
		_services.insert({ serviceName, new T() });
	}

	static IObjectHandler* getService(std::string serviceName);
};

#endif