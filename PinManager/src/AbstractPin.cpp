#include <Kernal.h>
#include <TimeoutService.h>
#include "AbstractPin.h"
#include "TimeoutWatcherPin.h"

void AbstractPin::reinit() {
  TimeoutWatcherPin* timeout = new TimeoutWatcherPin(this/*, this->severity*/);

  this->timeoutIndex = timeout->index;
};

AbstractPin::AbstractPin(unsigned int id, unsigned int severity): id(id), severity(severity) {
  reinit();
};

AbstractPin::~AbstractPin() {
  TimeoutService* timeout_service = Kernal::service("timeout.service");
  timeout_service->removeAt(timeoutIndex);
};
