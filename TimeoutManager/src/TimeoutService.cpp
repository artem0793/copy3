
#include "Timeout.h"
#include "TimeoutService.h"

int TimeoutService::getFreeIndex() {
  int index = -1;

  for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
    if (!isset_object(queue[i])) {
      index = i;

      break;
    }
  }

  return index;
};

TimeoutService* TimeoutService::getInstance() {
  static TimeoutService* instance = new TimeoutService();

  return instance;
};

TimeoutService::TimeoutService(): Service("timeout.service") {

};

void TimeoutService::add(Timeout* timeout) {
  int index = getFreeIndex();

  if (index != -1) {
    queue[index] = timeout;
    queue[index]->index = index;
  }
};

void TimeoutService::remove(Timeout* timeout) {
  for (int unsigned index = 0; index < SERVICE_MAX_TIMEOUT_QUENTITY; index++) {
    if (isset_object(queue[index]) && queue[index] == timeout) {
      queue[index] = {};

      break;
    }
  }
};

void TimeoutService::removeAt(unsigned int index) {
  if (isset_object(queue[index])) {
    delete queue[index];
  }
};

void TimeoutService::execute() {
  unsigned long timer = millis();

  for (int unsigned index = 0; index < SERVICE_MAX_TIMEOUT_QUENTITY; index++) {
    if (
        isset_object(queue[index]) &&
        queue[index]->expireTime <= timer
    ) {
      queue[index]->execute();

      delete queue[index];
    }
  }
};
