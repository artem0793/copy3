#ifndef _TIMEOUT_MANAGER_H

#define _TIMEOUT_MANAGER_H

#include <Arduino.h>
#include <Service.h>
#include "Timeout.h"

const int unsigned SERVICE_MAX_TIMEOUT_QUENTITY = 10;

class TimeoutService: public Service {

  protected:

    Timeout* queue[SERVICE_MAX_TIMEOUT_QUENTITY] = {};

    int getFreeIndex(void);

    TimeoutService(void);

  public:

    static TimeoutService* getInstance(void);

    void add(Timeout*);

    void remove(Timeout*);

    void execute(void);

};

#endif
