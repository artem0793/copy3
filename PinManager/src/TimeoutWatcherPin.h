#ifndef PIN_WHATCHER_TIMEOUT_H

#define PIN_WHATCHER_TIMEOUT_H

#include "Timeout.h"
#include "AbstractPin.h"

class TimeoutWatcherPin: public Timeout {

  private:

    AbstractPin* pin;

  public:

    TimeoutWatcherPin(AbstractPin* pin): Timeout(pin->severity), pin(pin) {};

    void execute();

};

#endif
