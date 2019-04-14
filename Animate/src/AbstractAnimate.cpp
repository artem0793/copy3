#include <Arduino.h>
#include <Kernal.h>
#include <Timeout.h>
#include <TimeoutService.h>
#include "AbstractAnimate.h"
#include "AnimateTimeout.h"

AbstractAnimate::AbstractAnimate(unsigned int timing, unsigned int duration, unsigned int step): timing(timing), duration(duration), step(step) {
  start = millis();

  play();
};

AbstractAnimate::~AbstractAnimate() {
  stop();
};

void AbstractAnimate::draw() {

};

void AbstractAnimate::play() {
  if (progress < 1) {
    Timeout* timeout = new AnimateTimeout(this);
    timeoutIndex = timeout->index;
  }
};

void AbstractAnimate::stop() {
  TimeoutService* timeout_service = Kernal::service("timeout.service");

  timeout_service->removeAt(timeoutIndex);
};
