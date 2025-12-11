#include <Arduino.h>
#include "BuzzerAlarm.h"

BuzzerAlarm::BuzzerAlarm(int buzzerPin) {
  pin = buzzerPin;
}

void BuzzerAlarm::begin() {
  pinMode(pin, OUTPUT);
}

void BuzzerAlarm::alarm() {
  tone(pin, 4500);    // toca som a 4500 Hz
}

void BuzzerAlarm::stop() {
  noTone(pin);        // para o som
}
