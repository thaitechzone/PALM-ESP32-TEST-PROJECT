#include <Arduino.h>
#include "pin_config.h"

#define RELAY_ON  LOW   // Active Low
#define RELAY_OFF HIGH

const unsigned long TOGGLE_INTERVAL_MS = 5000;

unsigned long lastToggleTime = 0;
bool relaysOn = false;

void setRelays(bool on) {
    digitalWrite(PIN_RELAY1, on ? RELAY_ON : RELAY_OFF);
    digitalWrite(PIN_RELAY2, on ? RELAY_ON : RELAY_OFF);
    digitalWrite(PIN_RELAY3, on ? RELAY_ON : RELAY_OFF);
}

void setup() {
    pinMode(PIN_RELAY1, OUTPUT);
    pinMode(PIN_RELAY2, OUTPUT);
    pinMode(PIN_RELAY3, OUTPUT);

    relaysOn = false;
    setRelays(relaysOn);
    lastToggleTime = millis();
}

void loop() {
    if (millis() - lastToggleTime >= TOGGLE_INTERVAL_MS) {
        lastToggleTime = millis();
        relaysOn = !relaysOn;
        setRelays(relaysOn);
    }
}
