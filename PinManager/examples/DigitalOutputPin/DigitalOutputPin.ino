#include <Kernal.h>
#include <DigitalInputPin.h>
#include <DigitalOutputPin.h>

class LED: public DigitalOutputPin {

  public:

    LED(unsigned int id): DigitalOutputPin(id) {
      Serial.println("LED");
    }

    void onChange(unsigned int value) {
      Serial.print("LED: ");
      Serial.print(value == 1 ? "On" : "Off");
      Serial.println(" change");
    }

};

class Button: public DigitalInputPin {

  protected:

    LED* led;

  public:

    Button(LED* led, unsigned int id): DigitalInputPin(id, 50), led(led) {
      Serial.println("Button");
    }

    void onChange(unsigned int value) {
      Serial.print("Button: ");
      Serial.print(value == 1 ? "On" : "Off");
      Serial.println(" change");

      if (value == 1) {
        led->setValue(led->getValue() == 1 ? 0 : 1);
      }
    }

};

void setup() {
  Serial.begin(9600);

  new Button(
    new LED(3),
    2
  );
}

void loop() {
  Kernal::serviceProcess();
}
