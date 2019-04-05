
/**
 * @file
 * Service.
 */

#include "Service.h"
#include "ServiceManager.h"

Service::Service(const char* name): name(name) {
  ServiceManager::getInstance()->add(this);
};

Service::~Service() {
  ServiceManager::getInstance()->remove(this);
};
