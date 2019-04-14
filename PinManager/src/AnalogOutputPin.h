#ifndef ANALOG_OUTPUT_PIN_H

#define ANALOG_OUTPUT_PIN_H

#include "AbstractOutputPin.h"

class AnalogOutputPin: public AbstractOutputPin {

  public:

    AnalogOutputPin(unsigned int id);

    void setValue(unsigned int value);

    virtual void onChange(unsigned int value);

};

#endif
