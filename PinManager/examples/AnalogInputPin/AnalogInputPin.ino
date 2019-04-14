#include <Kernal.h>
#include <AnalogInputPin.h>

class Voltmetr: public AnalogInputPin {

  public:

    Voltmetr(unsigned int id): AnalogInputPin(id, 1000) {
      Serial.println("Voltmetr init");
    };

    void onChange(unsigned int value) {
      Serial.print(value);
      Serial.println(" change");
    };

};

void setup() {
  Serial.begin(9600);

  new Voltmetr(2);
}

void loop() {
  Kernal::serviceProcess();
}
