#include <Arduino.h>
#include "DigitalInputPin.h"
#include "AbstractInputPin.h"

DigitalInputPin::DigitalInputPin(unsigned int id, unsigned int severity): AbstractInputPin(id, severity) {
  pinMode(id, INPUT);
};

void DigitalInputPin::watch() {
  unsigned int new_value = digitalRead(id) == HIGH ? 1 : 0;

  if (value != new_value) {
    value = new_value;
    onChange(value);
  }
};
