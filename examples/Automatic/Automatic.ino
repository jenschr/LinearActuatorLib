/*
 * Simple code example showing how to run two linear actuators
 * back and forth at different intervals.
 */

#include "linearactuator.h"

#define ACTUATOR1_REVERSE_PIN 11
#define ACTUATOR1_FORWARD_PIN 12

#define ACTUATOR2_REVERSE_PIN 9
#define ACTUATOR2_FORWARD_PIN 10

int distance = 10000; // how many seconds to move the actuator

LinearActuator linear1;
LinearActuator linear2;

void setup() {
  // Set it up
  linear1.begin(ACTUATOR1_REVERSE_PIN, ACTUATOR1_FORWARD_PIN, distance, 1000);
  linear2.begin(ACTUATOR2_REVERSE_PIN, ACTUATOR2_FORWARD_PIN, distance, 1500);
  
  // Start by pulling the actuator all the way in
  linear1.in();
  linear2.in();
  delay(distance);

  // Then turn it off
  linear1.off();
  linear2.off();
}

void loop() {
  // Only call millis once
  unsigned long now = millis();

  // keep things moving
  linear1.maintain(now);
  linear2.maintain(now);
}
