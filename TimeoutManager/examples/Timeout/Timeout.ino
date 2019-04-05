#include <Timeout.h>
#include <TimeoutService.h>
#include <Kernal.h>

class MyTimeout: public Timeout {
  public:
    MyTimeout(): Timeout(3000) {

    }

    void execute() {
      Serial.println("Test");
      new MyTimeout;
    }
};

void setup() {
   Serial.begin(9600);
   Kernal::getInstance();
   new MyTimeout;
}

void loop() {
  Kernal::serviceProcess();
}
