#include <Arduino.h>
 
int statusLed = 2;
void setup() {
    pinMode(statusLed, OUTPUT);
  
}

void loop() {
    digitalWrite(statusLed, HIGH);
    delay(100);
    digitalWrite(statusLed, LOW);
    delay(1000);
}

 