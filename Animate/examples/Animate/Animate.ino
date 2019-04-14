#include <AbstractAnimate.h>
#include <Kernal.h>

bool once = false;

class MyAnimate: public AbstractAnimate {

  public:

    MyAnimate(): AbstractAnimate(A_QUAD_TIMING, 1000, 100) {

    };

    void draw() {
      Serial.println(progress);
    };

    void done() {
      if (once == false) {
        once = true;

        this->setReverse();
        this->play();
      }
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
