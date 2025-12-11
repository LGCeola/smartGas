#include "GasSensor.h"
#include <Arduino.h>

GasSensor::GasSensor(int pin, int threshold) {
    this->pin = pin;
    this->threshold = threshold;
}

void GasSensor::begin() {
    pinMode(pin, INPUT);
}

int GasSensor::readValue() {
    return analogRead(pin);
}

bool GasSensor::isDanger() {
    return readValue() > threshold;
}
