#include <Kernal.h>
#include <DigitalInputPin.h>

class Button: public DigitalInputPin {

  public:

    Button(unsigned int id): DigitalInputPin(id, 300) {
      Serial.println("Button");
    }

    void onChange(unsigned int value) {
      Serial.print(value == 1 ? "On" : "Off");
      Serial.println(" change");
      Serial.println(micros());
    }

};

void setup() {
  Serial.begin(9600);

  new Button(2);
}

void loop() {
  Kernal::serviceProcess();
}
