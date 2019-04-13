
#ifndef DIGITAL_INPUT_PIN_H

#define DIGITAL_INPUT_PIN_H

#include "AbstractPin.h"

class DigitalInputPin: public AbstractPin {

  protected:

    unsigned int value;

  public:

    DigitalInputPin(unsigned int id, unsigned int severity);

    void watch(void);

    virtual void onChange(unsigned int) {};

};

#endif
