#ifndef _TIMEOUT_MANAGER_H

#define _TIMEOUT_MANAGER_H

const int unsigned SERVICE_MAX_TIMEOUT_QUENTITY = 10;

#include <Service.h>
#include "Timeout.h"

class TimeoutService: public Service {

  protected:

    Timeout * queue[SERVICE_MAX_TIMEOUT_QUENTITY] = {};

    int getFreeIndex() {
      int index = -1;

      for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
        if (!isset_object(this->queue[i])) {
          index = i;
          break;
        }
      }

      return index;
    }

    TimeoutService(): Service("timeout.manager") {

    };

  public:

    static TimeoutService * getInstance() {
      static TimeoutService * instance = new TimeoutService();

      return instance;
    }

    void add(Timeout * timeout) {
      int index = this->getFreeIndex();

      if (index != -1) {
        this->queue[index] = timeout;
      }
    }

    void remove(Timeout * timeout) {
      for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
        if (isset_object(this->queue[i]) && this->queue[i] == timeout) {
          this->queue[i] = NULL;
          break;
        }
      }
    }

    void execute() {
      unsigned long timer = millis();

      for (int unsigned i = 0; i < SERVICE_MAX_TIMEOUT_QUENTITY; i++) {
        if (
            isset_object(this->queue[i]) &&
            this->queue[i]->expireTime <= timer
        ) {
          this->queue[i]->execute();

          delete this->queue[i];
        }
      }
    }

};

#endif
