#ifndef _EVENT_TARGET_H

#define _EVENT_TARGET_H

const int EVENT_TARGET_SIZE = 10;

#include <BaseObject.h>
#include "Event.h"
#include "EventCallback.h"

template <typename TargetType>
class EventTarget {

  protected:

    /**
     * Array of handler with all events.
     */
    EventCallback<TargetType>* handlers[EVENT_TARGET_SIZE] = {};

    /**
     * Find free plase in array.
     */
    int getFreeMapIndex() {
      for (int unsigned index = 0; index < EVENT_TARGET_SIZE; index++) {
        if (isset_object(this->handlers[index]) == false) {
          return index;
        }
      }

      return -1;
    }

  public:

    /**
     * Add hendler to event.
     */
    void on(const char* type, EventCallback<TargetType> * callback) {
      int index = getFreeMapIndex();

      if (index != -1) {
        callback->type = type;
        handlers[index] = callback;
      }
    }

    /**
     * Remove event handler.
     */
    void off(EventCallback<TargetType> * callback) {
      for (int unsigned index = 0; index < EVENT_TARGET_SIZE; index++) {
        if (isset_object(this->handlers[index]) == true && this->handlers[index] == callback) {
          delete this->handlers[index];
        }
      }
    }

    /**
     * Fire all events by group.
     */
    void dispatch(Event<TargetType> * event) {
      for (int unsigned index = 0; index < EVENT_TARGET_SIZE; index++) {
        if (isset_object(handlers[index]) && handlers[index]->type == event->type) {
          handlers[index]->callback(event);
        }
      }

      delete event;
    }

};

#endif
