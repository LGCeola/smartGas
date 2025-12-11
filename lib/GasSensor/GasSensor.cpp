#include <Arduino.h>
#include "GasSensor.h"

GasSensor::GasSensor(int analogPin, int dangerLimit) {
  pin = analogPin;
  limit = dangerLimit;
}

void GasSensor::begin() {
  pinMode(pin, INPUT);
}

int GasSensor::readValue() {
  return analogRead(pin);
}

bool GasSensor::isDanger() {
  return readValue() >= limit;
}
