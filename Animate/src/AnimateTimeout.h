#ifndef ANIMATE_TIMEOUT

#define ANIMATE_TIMEOUT

#include <Timeout.h>
#include "AbstractAnimate.h"

class AnimateTimeout: public Timeout {

  protected:

    AbstractAnimate* animation;

  public:

    AnimateTimeout(AbstractAnimate* animation);

    void execute(void);

};

#endif
