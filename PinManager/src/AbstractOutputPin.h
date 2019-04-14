#ifndef ABSTRACT_OUTPUT_PIN_H

#define ABSTRACT_OUTPUT_PIN_H

#include <BaseObject.h>

class AbstractOutputPin: public BaseObject {

  protected:

    unsigned int id;

    unsigned int value;

  public:

    AbstractOutputPin(unsigned int id);

    ~AbstractOutputPin();

    virtual void setValue(unsigned int new_value);

    unsigned int getValue();

};

#endif
