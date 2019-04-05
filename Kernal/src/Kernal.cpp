#include "Kernal.h"
#include <TimeoutManager.h>

Kernal::Kernal() {
  this->services = ServiceManager::getInstance();
};

ServiceManager * Kernal::getServiceManager() {
  return this->services;
};

Service * Kernal::service(String name) {
  return Kernal::getInstance()
    ->getServiceManager()
    ->get(name);
};

Kernal * Kernal::getInstance() {
  static Kernal * instance = new Kernal;

  return instance; 
};

void Kernal::serviceProcess() {
  Kernal::getInstance()
    ->getServiceManager()
    ->process();
};
