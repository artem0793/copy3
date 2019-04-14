#include <Arduino.h>
#include "DigitalOutputPin.h"

DigitalOutputPin::DigitalOutputPin(unsigned int id): AbstractOutputPin(id) {
  pinMode(id, OUTPUT);
};

void DigitalOutputPin::setValue(unsigned int new_value) {
  if (value != new_value) {
    digitalWrite(id, new_value > 0 ? HIGH : LOW);
    onChange(new_value);
  }
};

void DigitalOutputPin::onChange(unsigned int value) {

};
