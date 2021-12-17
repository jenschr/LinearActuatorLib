#include "linearactuator.h"

LinearActuator::LinearActuator()
{
  state = WAIT_OUT;
  _secondsMove = 2000;
  _secondsWait = 1000;
}

void LinearActuator::begin(int reversePin, int forwardPin)
{
  begin(reversePin, forwardPin, 2000, 1000);
};

void LinearActuator::begin(int reversePin, int forwardPin, int secondsMove, int secondsWait)
{
  _reversePin = reversePin;
  _forwardPin = forwardPin;
  _secondsMove = secondsMove;
  _secondsWait = secondsWait;
  pinMode(_reversePin, OUTPUT);
  pinMode(_forwardPin, OUTPUT);
};

void LinearActuator::maintain( unsigned long currentTime )
{
  if( currentTime > _nextStateChangeTime )
  {
    switch(state)
    {
      case MOVE_IN: state = WAIT_IN; _nextStateChangeTime += _secondsWait; off(); break;
      case WAIT_IN: state = MOVE_OUT; _nextStateChangeTime += _secondsMove; out(); break;
      case MOVE_OUT: state = WAIT_OUT; _nextStateChangeTime += _secondsWait; off(); break;
      case WAIT_OUT: state = MOVE_IN; _nextStateChangeTime += _secondsMove; in(); break;
      default: break;
    }
    
  }
}
void LinearActuator::off()
{
  digitalWrite(_reversePin, LOW);
  digitalWrite(_forwardPin, LOW);
};

void LinearActuator::out()
{
  digitalWrite(_reversePin, LOW);
  digitalWrite(_forwardPin, HIGH);
}

void LinearActuator::in()
{
  digitalWrite(_reversePin, HIGH);
  digitalWrite(_forwardPin, LOW);
}
