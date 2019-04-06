#ifndef _TIMEOUT_H

#define _TIMEOUT_H

#include <BaseObject.h>

class Timeout: public BaseObject {

  public:

    unsigned int index;

    unsigned long expireTime;

    Timeout(unsigned long);

    ~Timeout(void);

    virtual void execute(void) {

    };

};

#endif
