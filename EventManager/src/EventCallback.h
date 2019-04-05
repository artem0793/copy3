
/**
 * @file
 * EventCallback class.
 */

#ifndef _EVENT_CALLBACK_H

#define _EVENT_CALLBACK_H

#include <BaseObject.h>
#include "Event.h"

template<typename TargetType>
class EventCallback: public BaseObject {

  public:

    /**
     * Envent name.
     */
    const char* type;

    /**
     * Handler callback.
     */
    virtual void callback(Event<TargetType> * event) {};

};

#endif
