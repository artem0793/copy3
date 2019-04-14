#include "AbstractOutputPin.h"

AbstractOutputPin::AbstractOutputPin(unsigned int id): id(id) {

};

AbstractOutputPin::~AbstractOutputPin() {

};

void AbstractOutputPin::setValue(unsigned int new_value) {
  this->value = new_value;
};

unsigned int AbstractOutputPin::getValue() {
  return this->value;
};
