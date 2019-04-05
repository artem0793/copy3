#ifndef _TIMEOUT_MANAGER_H

#define _TIMEOUT_MANAGER_H

#include <Arduino.h>
#include <Service.h>
#include "Timeout.h"

const int unsigned SERVICE_MAX_TIMEOUT_QUENTITY = 10;

class TimeoutService: public Service {

  protected:

    Timeout* queue[SERVICE_MAX_TIMEOUT_QUENTITY] = {};

    int getFreeIndex() {
      int index = -1;

      for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
        if (!isset_object(queue[i])) {
          index = i;

          break;
        }
      }

      return index;
    }

    TimeoutService(): Service("timeout.manager") {

    };

  public:

    static TimeoutService* getInstance() {
      static TimeoutService* instance = new TimeoutService();

      return instance;
    }

    void add(Timeout* timeout) {
      int index = getFreeIndex();

      if (index != -1) {
        queue[index] = timeout;
      }
    }

    void remove(Timeout* timeout) {
      for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
        if (isset_object(queue[i]) && queue[i] == timeout) {
          queue[i] = {};

          break;
        }
      }
    }

    void execute() {
      unsigned long timer = millis();

      for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
        if (
            isset_object(queue[i]) &&
            queue[i]->expireTime <= timer
        ) {
          queue[i]->execute();

          delete queue[i];
        }
      }
    }

};

#endif
