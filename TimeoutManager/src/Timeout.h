#ifndef _TIMEOUT_H

#define _TIMEOUT_H

#include <BaseObject.h>

class Timeout: public BaseObject {

  public:

    unsigned long expireTime;

    Timeout(unsigned long time = 0);

    ~Timeout();

    virtual void execute() {
      
    };
};

#endif
