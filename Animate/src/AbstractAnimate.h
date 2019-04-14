#ifndef ABSTRACT_ANIMATE_H

#define ABSTRACT_ANIMATE_H

#include <BaseObject.h>

const unsigned int A_LINEAR_TIMING = 0;

const unsigned int A_QUAD_TIMING = 1;

const unsigned int A_CIRC_TIMING = 2;

float quad_timing(float progress);

float line_timing(float progress);

float circ_timing(float progress);

class AbstractAnimate: public BaseObject {

  public:

    int timeoutIndex = -1;

    unsigned long start;

    unsigned int duration;

    float progress;

    unsigned int step;

    unsigned int timing;

    bool reverse;

    AbstractAnimate(unsigned int timing, unsigned int duration, unsigned int step, bool auto_start = true, bool reverse = false);

    ~AbstractAnimate();

    virtual void draw();

    virtual void done();

    void play(void);

    void stop(void);

    void setReverse(void);

};

#endif
