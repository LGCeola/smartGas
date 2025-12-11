#ifndef GASSENSOR_H
#define GASSENSOR_H

class GasSensor {
  private:
    int pin;
    int limit;

  public:
    GasSensor(int analogPin, int dangerLimit);
    void begin();
    int readValue();
    bool isDanger();
};

#endif
