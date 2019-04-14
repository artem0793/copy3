#ifndef DIGITAL_OUTPUT_PIN_H

#define DIGITAL_OUTPUT_PIN_H

#include "AbstractOutputPin.h"

class DigitalOutputPin: public AbstractOutputPin {

  public:

    DigitalOutputPin(unsigned int id);

    void setValue(unsigned int value);

    virtual void onChange(unsigned int value);

};

#endif
