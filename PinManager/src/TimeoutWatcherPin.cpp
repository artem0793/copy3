#include "TimeoutWatcherPin.h"

void TimeoutWatcherPin::execute() {
  pin->reinit();
  pin->watch();
};
