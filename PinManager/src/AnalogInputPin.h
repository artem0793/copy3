
#ifndef ANALOG_INPUT_PIN_H

#define ANALOG_INPUT_PIN_H

#include "AbstractInputPin.h"

class AnalogInputPin: public AbstractInputPin {

  public:

    AnalogInputPin(unsigned int id, unsigned int severity);

    void watch(void);

    virtual void onChange(unsigned int) {};

};

#endif
