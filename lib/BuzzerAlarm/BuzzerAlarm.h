#ifndef BUZZER_ALARM_H
#define BUZZER_ALARM_H

class BuzzerAlarm {
public:
  BuzzerAlarm(int pin);
  void begin();
  void alarm();  
  void stop();   

private:
  int pin;
};

#endif
