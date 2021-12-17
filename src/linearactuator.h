#ifndef LINEAR_ACTUATOR_H
#define LINEAR_ACTUATOR_H

#include <Arduino.h>

#define MOVE_IN 1
#define WAIT_IN 2
#define MOVE_OUT 3
#define WAIT_OUT 4

class LinearActuator
{
  public:
    LinearActuator();
    void begin(int reversePin, int forwardPin);
    void begin(int reversePin, int forwardPin, int secondsMove, int secondsWait);
    void maintain( unsigned long currentTime );
    void off();
    void out();
    void in();
  private:
    int state;
    int _reversePin;
    int _forwardPin;
    int _secondsMove;
    int _secondsWait;
    unsigned long _nextStateChangeTime;
};

#endif /* ROST_COMMUNICATOR_H */
