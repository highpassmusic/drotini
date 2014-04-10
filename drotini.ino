#include "Encoders.h"
#include "Buttons.h"
#include "Display.h"
#define DEBUG

Encoders *encoders;
Buttons  *buttons;
Display  *display;

void setup() {
#ifdef DEBUG
    Serial.begin(115200);
#endif

    encoders = new Encoders();
    buttons = new Buttons(10, 11, 12);
    display = new Display(8, 9 , 0);
    display->setText(0, "Hello World!");
    display->writeText();
#ifdef DEBUG
    Serial.println("We set this ass up");
#endif
    
}

void loop() {
  //Serial.println(encoders->getPosition(0), DEC);
  //Serial.println(5, DEC);
}
