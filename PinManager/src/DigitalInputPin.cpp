#include <Kernal.h>
#include <Arduino.h>
#include "DigitalInputPin.h"
#include "DigitalInputTimeoutPin.h"
#include <TimeoutService.h>

DigitalInputPin::DigitalInputPin(unsigned int id, unsigned int severity): id(id), severity(severity) {
  pinMode(id, INPUT);
  new DigitalInputTimeoutPin(severity, this);
};

DigitalInputPin::~DigitalInputPin() {
  TimeoutService* timeout_service = Kernal::service("timeout.service");
  timeout_service->removeAt(timeoutIndex);
};

void DigitalInputPin::watch() {
  bool new_value = digitalRead(id) == HIGH ? true : false;

  if (value != new_value) {
    value = new_value;
    onChange();
  }
};
