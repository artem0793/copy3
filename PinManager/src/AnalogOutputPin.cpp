#include <Arduino.h>
#include "AnalogOutputPin.h"

AnalogOutputPin::AnalogOutputPin(unsigned int id): AbstractOutputPin(id) {

};

void AnalogOutputPin::setValue(unsigned int new_value) {
  new_value = map(new_value, 0, 100, 0, 100);

  if (value != new_value) {
    analogWrite(id, new_value);
    onChange(new_value);
    AbstractOutputPin::setValue(new_value);
  }
};

void AnalogOutputPin::onChange(unsigned int value) {

};
