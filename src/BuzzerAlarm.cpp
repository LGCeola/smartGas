#include "BuzzerAlarm.h"
#include <Arduino.h>

BuzzerAlarm::BuzzerAlarm(int pin) {
    this->pin = pin;
}

void BuzzerAlarm::begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void BuzzerAlarm::alarm() {
    digitalWrite(pin, HIGH);  // buzzer ligado
}

void BuzzerAlarm::stop() {
    digitalWrite(pin, LOW);   // buzzer desligado
}
