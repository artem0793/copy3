
#include <Arduino.h>
#include "AnalogInputPin.h"
#include "AbstractInputPin.h"

AnalogInputPin::AnalogInputPin(unsigned int id, unsigned int severity): AbstractInputPin(id, severity) {

};

void AnalogInputPin::watch() {
  unsigned int new_value = analogRead(id);

  if (value != new_value) {
    value = new_value;
    onChange(value);
  }
};
