#ifndef BUZZER_ALARM_H
#define BUZZER_ALARM_H

class BuzzerAlarm {
private:
    int pin;

public:
    BuzzerAlarm(int pin);
    void begin();
    void alarm();
    void stop();
};

#endif
