
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
    String type;

    /**
     * Target element.
     */
    TargetType * target;

    /**
     * Event constructor.
     */
    Event(String type, TargetType * target) {
      this->type = type;
      this->target = target;
    }

};

#endif
