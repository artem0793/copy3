
#include <Arduino.h>
#include <Timeout.h>
#include "AnimateTimeout.h"
#include "AbstractAnimate.h"

float linear_timing(float progress) {
  return progress;
};

float quad_timing(float progress) {
  return pow(progress, 2);
};

float circ_timing(float progress) {
  return 1 - sin(acos(progress));
};

AnimateTimeout::AnimateTimeout(AbstractAnimate* animation): Timeout(animation->step), animation(animation) {

};

void AnimateTimeout::execute() {
  float time_passed = millis() - animation->start;
  float time_fraction = time_passed / animation->duration;

  if (time_fraction > 1) {
    time_fraction = 1;
  }

  if (animation->reverse == true) {
    time_fraction = 1 - time_fraction;
  }

  switch (animation->timing) {
    case A_QUAD_TIMING:
      animation->progress = quad_timing(time_fraction);
      break;

    case A_CIRC_TIMING:
      animation->progress = circ_timing(time_fraction);
      break;

    case A_LINEAR_TIMING:
    default:
      animation->progress = linear_timing(time_fraction);
      break;

  }

  animation->draw();
  animation->play();
};
