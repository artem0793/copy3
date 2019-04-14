#ifndef ABSTRACT_INPUT_PIN_H

#define ABSTRACT_INPUT_PIN_H

#include <BaseObject.h>

class AbstractInputPin: public BaseObject {

  protected:

    unsigned int value;

  public:

    unsigned int id;

    unsigned int severity;

    int timeoutIndex;

    AbstractInputPin(unsigned int id, unsigned int severity);

    ~AbstractInputPin();

    void reinit();

    virtual void watch() {};

    unsigned int getValue();

};

#endif
