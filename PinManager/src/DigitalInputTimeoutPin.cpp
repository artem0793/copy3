#include "DigitalInputTimeoutPin.h"
#include "DigitalInputPin.h"
#include <Timeout.h>

DigitalInputTimeoutPin::DigitalInputTimeoutPin(unsigned int severity, DigitalInputPin* pin): Timeout(severity), pin(pin) {

};

void DigitalInputTimeoutPin::execute() {
  pin->watch();
  DigitalInputTimeoutPin* timeout = new DigitalInputTimeoutPin(pin->severity, pin);
  pin->timeoutIndex = timeout->index;
};
