#include <Event.h>
#include <EventCallback.h>
#include <EventTarget.h>

class Element: public EventTarget<Element> {
  public:
    String text = "Event construct!";
};

class ElementEventCallback: public EventCallback<Element> {
  protected:
    void callback(Event<Element> * event) {
      Serial.println(event->target->text);
    }
};

void setup() {
  Serial.begin(9600);
  Serial.println("Setup - start");
  Element * item = new Element;
  ElementEventCallback * callback = new ElementEventCallback();
  item->on("construct", callback);
  item->dispatch(
    new Event<Element>("construct", item)
  );
  Serial.println("Setup - end");
}

void loop() {
  // put your main code here, to run repeatedly:
}
