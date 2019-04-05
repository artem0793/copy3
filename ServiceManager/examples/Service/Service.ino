#include <Service.h>
#include <ServiceManager.h>
#include <Kernal.h>

class MyService: public Service {
  public:

    MyService(): Service("test.service") {
      Serial.println("MyService");
    }
    void test() {
      Serial.println("YYY");
    }
    void execute() {
      Serial.println("XXX");
      delay(1000);
    };
};

void setup() {
  Serial.begin(9600);

  Serial.println("init");

  new MyService;
}

void loop() {
  Kernal::serviceProcess();
}