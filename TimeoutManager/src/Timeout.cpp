#include <Kernal.h>
#include "Timeout.h"
#include "TimeoutManager.h"

Timeout::Timeout(unsigned long time) {
  this->expireTime = millis() + time;
  TimeoutService::getInstance()->add(this);
};

Timeout::~Timeout() {
  TimeoutService::getInstance()->remove(this);
};
