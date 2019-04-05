#include "ServiceManager.h"

ServiceManager::ServiceManager() {

};

ServiceManager* ServiceManager::getInstance() {
  static ServiceManager* instance = new ServiceManager;

  return instance;
};

int ServiceManager::getFreeIndex() {
  int index = -1;

  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (!isset_object(services[i])) {
      index = i;

      break;
    }
  }

  return index;
};

void ServiceManager::add(Service* service) {
  int index = getFreeIndex();

  if (index >= 0) {
    services[index] = service;
  }
};

void ServiceManager::remove(Service* service) {
  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (isset_object(services[i]) && services[i] == service) {
      services[i] = {};

      break;
    }
  }
};

Service * ServiceManager::get(const char* name) {
  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (isset_object(services[i]) && services[i]->name == name) {
      return services[i];
    }
  }
};

void ServiceManager::process() {
  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (isset_object(services[i])) {
      services[i]->execute();
    }
  }
};
