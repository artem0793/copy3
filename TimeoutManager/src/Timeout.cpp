#include <Kernal.h>
#include "Timeout.h"
#include "TimeoutService.h"

Timeout::Timeout(unsigned long time) {
  expireTime = millis() + time;
  TimeoutService::getInstance()->add(this);
};

Timeout::~Timeout() {
  TimeoutService::getInstance()->remove(this);
};
