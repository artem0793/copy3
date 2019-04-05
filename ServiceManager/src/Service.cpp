
#include "Service.h"
#include "ServiceManager.h"

Service::Service(String name) {
  this->name = name;
  ServiceManager::getInstance()->add(this);
};

Service::~Service() {
  ServiceManager::getInstance()->remove(this);
};
