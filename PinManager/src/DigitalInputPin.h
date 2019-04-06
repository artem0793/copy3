
#ifndef DIGITAL_INPUT_PIN_H

#define DIGITAL_INPUT_PIN_H

#include <BaseObject.h>

class DigitalInputPin: public BaseObject {

  protected:

    unsigned int id;

    bool value;

  public:

    unsigned int severity;

    unsigned int timeoutIndex;

    DigitalInputPin(unsigned int, unsigned int);

    ~DigitalInputPin();

    void watch(void);

    virtual void onChange(void) {};

};

#endif
