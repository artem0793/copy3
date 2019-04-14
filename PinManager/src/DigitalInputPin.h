
#ifndef DIGITAL_INPUT_PIN_H

#define DIGITAL_INPUT_PIN_H

#include "AbstractInputPin.h"

class DigitalInputPin: public AbstractInputPin {

  public:

    DigitalInputPin(unsigned int id, unsigned int severity);

    void watch(void);

    virtual void onChange(unsigned int) {};

};

#endif
