
#include <Arduino.h>
#include <Timeout.h>
#include "AnimateTimeout.h"
#include "AbstractAnimate.h"


float line_timing(float progress) {
  return progress;
}

AnimateTimeout::AnimateTimeout(AbstractAnimate* animation): Timeout(animation->step), animation(animation) {

};

void AnimateTimeout::execute() {
  float time_fraction = (millis() - animation->start) / animation->duration;

  if (time_fraction > 1) {
    time_fraction = 1;
  }

  switch (animation->timing) {

    case ANIMATE_TIMING_LINE:
      animation->progress = line_timing(time_fraction);
    break;

  }


  animation->draw();
  animation->play();
};
