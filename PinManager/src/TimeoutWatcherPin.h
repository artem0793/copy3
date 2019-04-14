#ifndef PIN_WHATCHER_TIMEOUT_H

#define PIN_WHATCHER_TIMEOUT_H

#include "Timeout.h"
#include "AbstractInputPin.h"

class TimeoutWatcherPin: public Timeout {

  private:

    AbstractInputPin* pin;

  public:

    TimeoutWatcherPin(AbstractInputPin* pin): Timeout(pin->severity), pin(pin) {};

    void execute();

};

#endif
