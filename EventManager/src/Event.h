
/**
 * @file
 * Event class.
 */

#ifndef _EVENT_H

#define _EVENT_H

template<typename TargetType>
class Event {

  public:

    /**
     * Event name.
     */
    const char* type;

    /**
     * Target element.
     */
    TargetType* target;

    /**
     * Event constructor.
     */
    Event(const char* type, TargetType * target): type(type), target(target) {

    }

};

#endif
