#include <AbstractAnimate.h>
#include <Kernal.h>

class MyAnimate: public AbstractAnimate {

  public:

    MyAnimate(): AbstractAnimate(A_QUAD_TIMING, 1500, 50) {

    };

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
