/*
   Simple button control of a single actuator

   Requirements:
   - Button connected to pin 2 (with pulldown)
   - Button connected to pin 3 (with pulldown)
   - A linear actuator with auto-stop connected to pins 4 and 5
   - Linear actuator library installed
*/

#include <linearactuator.h>

LinearActuator linearActuatorInstance;   // A single instance of the library
const int extendButtonPin = 2;           // Pin number for the pushbutton to extend the actuator
const int contractButtonPin = 3;         // Pin number for the pushbutton to contract the actuator

const int extendPin = 4;                 // Pin number to extend the actuator
const int contractPin = 5;               // Pin number to contract the actuator

void setup() {
  // Set button pins as inputs
  pinMode(extendButtonPin, INPUT);
  pinMode(contractButtonPin, INPUT);

  // Set the pins to control the actuator
  linearActuatorInstance.begin(ACTUATOR_REVERSE_PIN, ACTUATOR_FORWARD_PIN);
}

void loop() {
  if (digitalRead(extendButtonPin) == HIGH)
  {
    linearActuatorInstance.out();
  }
  else if (digitalRead(contractButtonPin) == HIGH)
  {
    linearActuatorInstance.in();
  }
  else
  {
    linearActuatorInstance.off(); // if no button is pressed, turn off
  }
}
