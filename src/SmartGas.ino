#include "GasSensor.h"
#include "BuzzerAlarm.h"

GasSensor gas(A0, 300);     // pino A0, limite de gás 300
BuzzerAlarm buzzer(8);      // buzzer no pino 8

void setup() {
  Serial.begin(9600);
  gas.begin();
  buzzer.begin();
}

void loop() {
  int value = gas.readValue();
  Serial.print("Leitura MQ-2: ");
  Serial.println(value);

  if (gas.isDanger()) {
    buzzer.alarm();  // toca alarme forte
  } else {
    buzzer.stop();   // silêncio
  }

  delay(500);
}
