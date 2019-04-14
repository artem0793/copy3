#ifndef ABSTRACT_ANIMATE_H

#define ABSTRACT_ANIMATE_H

#include <BaseObject.h>

const unsigned int A_LINEAR_TIMING = 0;

const unsigned int A_QUAD_TIMING = 1;

const unsigned int A_CIRC_TIMING = 2;

const unsigned int A_BOUNCE_TIMING = 3;

float quad_timing(float progress);

float line_timing(float progress);

float circ_timing(float progress);

class AbstractAnimate: public BaseObject {

  public:

    int timeoutIndex;

    unsigned long start;

    unsigned int duration;

    float progress = 0;

    unsigned int step;

    unsigned int timing;

    AbstractAnimate(unsigned int timing, unsigned int duration, unsigned int step);

    ~AbstractAnimate();

    virtual void draw();

    void play(void);

    void stop(void);

};

#endif
