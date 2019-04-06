#ifndef DIGITAL_INPUT_TIMEOUT_PIN_H

#define DIGITAL_INPUT_TIMEOUT_PIN_H

#include "DigitalInputPin.h"
#include <Timeout.h>

class DigitalInputTimeoutPin: public Timeout {

  protected:

    DigitalInputPin* pin;

    void execute(void);

  public:

    DigitalInputTimeoutPin(unsigned int, DigitalInputPin*);

};

#endif
