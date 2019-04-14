
#include <Arduino.h>
#include "AnalogInputPin.h"
#include "AbstractInputPin.h"

AnalogInputPin::AnalogInputPin(unsigned int id, unsigned int severity): AbstractInputPin(id, severity) {

};

void AnalogInputPin::watch() {
  unsigned int sensorValue = analogRead(id);
  unsigned int new_value = map(sensorValue, 0, 1023, 0, 100);

  if (value != new_value) {
    value = new_value;
    onChange(value);
  }
};
