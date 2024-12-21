#include "ObjectHandlerFactory.h"

#include "ObjectDisplayer.h"
#include "HoverOnObjectHandler.h"
#include "ClickOnObjectHandler.h"

std::map<std::string, IObjectHandler*> ObjectHandlerFactory::_services;

void ObjectHandlerFactory::config() {
	registerService<ObjectDisplayer>("ObjectDisplayer");
	registerService<HoverOnObjectHandler>("HoverOnObjectHandler");
	registerService<ClickOnObjectHandler>("ClickOnObjectHandler");
}

IObjectHandler* ObjectHandlerFactory::getService(std::string serviceName) {
	if (_services.find(serviceName) == _services.end()) return nullptr;
	return _services[serviceName];
}