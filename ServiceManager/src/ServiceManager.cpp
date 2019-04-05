#include "ServiceManager.h"

ServiceManager::ServiceManager() {

};

ServiceManager * ServiceManager::getInstance() {
  static ServiceManager * instance = new ServiceManager;
  
  return instance;
};

int ServiceManager::getFreeIndex() {
  int index = -1;

  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (!isset_object(this->services[i])) {
      index = i;
      break;
    }
  }

  return index;
};

void ServiceManager::add(Service * service) {
  int index = this->getFreeIndex();
  
  if (index >= 0) {
    this->services[index] = service;
  }
};

void ServiceManager::remove(Service * service) {
  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (isset_object(this->services[i]) && this->services[i] == service) {
      this->services[i] = NULL;
      break;
    }
  }
};

Service * ServiceManager::get(String name) {
  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (isset_object(this->services[i]) && this->services[i]->name == name) {
      return this->services[i];
    }
  }
};

void ServiceManager::process() {
  for (unsigned int i = 0; i < SERVICE_MAX_QUENTITY; i++) {
    if (isset_object(this->services[i])) {
      this->services[i]->execute();
    }
  }
};
