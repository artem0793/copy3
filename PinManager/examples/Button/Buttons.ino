#include <Kernal.h>
#include <DigitalInputPin.h>

class Button: public DigitalInputPin {

  public:

    Button(unsigned int id): DigitalInputPin(id, 1000) {
      Serial.println("Button");
    }

    void onChange() {
      Serial.print(value ? "On" : "Off");
      Serial.println(" change");
      Serial.println(micros());
    }

};

void setup() {
  Serial.begin(9600);
  new Button(2);
  new Button(3);
  new Button(4);
  new Button(5);
  new Button(6);
  new Button(7);
  new Button(8);
  new Button(9);
  new Button(10);
  new Button(11);
}

void loop() {
  Kernal::serviceProcess();
}
