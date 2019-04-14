#include <Kernal.h>
#include <DigitalInputPin.h>
#include <AnalogOutputPin.h>
#include <AbstractAnimate.h>

class LEDAnimate: public AbstractAnimate {

  public:
    AnalogOutputPin* pin;

    LEDAnimate(AnalogOutputPin* pin): AbstractAnimate(A_QUAD_TIMING, 300, 10, false, true), pin(pin) {
      Serial.println("LEDAnimate");
    };

    void draw() {
      pin->setValue(progress == 0 ? 0 : 100 * progress);
    };

};

class LED: public AnalogOutputPin {

  public:

    LEDAnimate* animate;

    LED(unsigned int id): AnalogOutputPin(id) {
      Serial.println("LED");
      animate = new LEDAnimate(this);
    }

    void on() {
      Serial.println("ON");
      animate->setReverse();
      animate->play();
    }

    void off() {
      Serial.println("OFF");
      animate->setReverse();
      animate->play();
    }

};

class Button: public DigitalInputPin {

  protected:

    LED* led;

  public:

    Button(LED* led, unsigned int id): DigitalInputPin(id, 50), led(led) {
      Serial.println("Button");
    };

    void onChange(unsigned int value) {
      Serial.println("Click");
      if (value == 1) {
        if (led->getValue() != 0) {
          led->off();
        }
        else {
          led->on();
        }
      }
    };

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
