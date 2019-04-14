#ifndef ABSTRACT_ANIMATE_H

#define ABSTRACT_ANIMATE_H

#include <BaseObject>

const unsigned int ANIMATE_TIMING_LINE = 0;

float line_timing(float progress);

class AbstractAnimate: public BaseObject {

  public:

    int timeoutIndex;

    unsigned long start = 0;

    unsigned int duration;

    unsigned int progress = 0;

    unsigned int step;

    unsigned int timing;

    AbstractAnimate(unsigned int timing, unsigned int duration, unsigned int step);

    ~AbstractAnimate();

    virtual void draw();

    void play(void);

    void stop(void);

};

#endif
