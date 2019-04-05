#include "Kernal.h"

Kernal::Kernal() {
  services = ServiceManager::getInstance();
};

ServiceManager * Kernal::getServiceManager() {
  return services;
};

Service * Kernal::service(const char* name) {
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
