#include <Kernal.h>
#include <TimeoutService.h>
#include "AbstractInputPin.h"
#include "TimeoutWatcherPin.h"

void AbstractInputPin::reinit() {
  TimeoutWatcherPin* timeout = new TimeoutWatcherPin(this);

  this->timeoutIndex = timeout->index;
};

AbstractInputPin::AbstractInputPin(unsigned int id, unsigned int severity): id(id), severity(severity) {
  reinit();
};

AbstractInputPin::~AbstractInputPin() {
  TimeoutService* timeout_service = Kernal::service("timeout.service");
  timeout_service->removeAt(timeoutIndex);
};

unsigned int AbstractInputPin::getValue() {
  return value;
};
