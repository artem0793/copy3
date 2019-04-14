#include <AbstractAnimate.h>
#include <Kernal.h>

class MyAnimate: public AbstractAnimate {
  public:
    MyAnimate(): AbstractAnimate(ANIMATE_TIMING_LINE, 4000, 50) {

    }
    void draw() {
      Serial.println(progress);
    };
};

void setup() {
   Serial.begin(9600);
   Kernal::getInstance();

   new MyAnimate();
}

void loop() {
  Kernal::serviceProcess();
}
