#ifndef ABSTRACT_PIN_H

#define ABSTRACT_PIN_H

#include <BaseObject.h>

class AbstractPin: public BaseObject {

  public:

    unsigned int id;

    unsigned int severity;

    int timeoutIndex;

    AbstractPin(unsigned int id, unsigned int severity);

    ~AbstractPin();

    void reinit();

    virtual void watch() {};

};

#endif
