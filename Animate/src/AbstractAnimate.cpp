#include <Arduino.h>
#include <Kernal.h>
#include <Timeout.h>
#include <TimeoutService.h>
#include "AbstractAnimate.h"
#include "AnimateTimeout.h"

AbstractAnimate::AbstractAnimate(unsigned int timing, unsigned int duration, unsigned int step, bool reverse): timing(timing), duration(duration), step(step), reverse(reverse) {
  start = millis();
  progress = reverse ? 1 : 0;

  play();
};

AbstractAnimate::~AbstractAnimate() {
  stop();
};

void AbstractAnimate::draw() {

};

void AbstractAnimate::done() {

};

void AbstractAnimate::setReverse() {
  start = millis();
  reverse = reverse ? false : true;
  progress = reverse ? 1 : 0;
};

void AbstractAnimate::play() {
  if ((reverse == false && progress < 1) || (reverse == true && progress > 0)) {
    Timeout* timeout = new AnimateTimeout(this);
    timeoutIndex = timeout->index;
  }
};

void AbstractAnimate::stop() {
  if (timeoutIndex > -1) {
    TimeoutService* timeout_service = Kernal::service("timeout.service");

    timeout_service->removeAt(timeoutIndex);

    timeoutIndex = -1;
  }
};
