
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

TimeoutService::TimeoutService(): Service("timeout.manager") {

};

void TimeoutService::add(Timeout* timeout) {
  int index = getFreeIndex();

  if (index != -1) {
    queue[index] = timeout;
  }
};

void TimeoutService::remove(Timeout* timeout) {
  for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
    if (isset_object(queue[i]) && queue[i] == timeout) {
      queue[i] = {};

      break;
    }
  }
};

void TimeoutService::execute() {
  unsigned long timer = millis();

  for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
    if (
        isset_object(queue[i]) &&
        queue[i]->expireTime <= timer
    ) {
      queue[i]->execute();

      delete queue[i];
    }
  }
};
