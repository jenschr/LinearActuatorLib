# LinearActuatorLib
Simple library for controlling linear actuators (and anything similar) using forward &amp; backward pins. Made for use with Arduino, Teensy or Particle boards, but will work with anything using an Arduino style API.

This is not really a fully featured library, but it's general and I find it useful when using actuators that have some sort of auto-stop at the ends. I've used this with actuators from Linak and a couple chinese companies. Feel free to use it as a basis for your own libraries also as the code is quite simple to understand and extend.

## Installing
Just follow [these instructions](https://www.arduino.cc/en/guide/libraries#toc5) to install manually.

## Usage
Create one or more instances of actuators. Call the begin-method to tell the library what pins to use for each of the instances.

    instance.begin( reversePin, forwardPin)

You can then create your own code to move the actuator using the following commands:

    instance.out();
    instance.in();
    instance.off();

To have the library handle the timing, you can optionally set distance and duration for the in/out movement and time in between using the longer method:

    instance.begin( reversePin, forwardPin, secondsToMove, secondsToWait)

By using this command, you just set it up once and it will cycle forever as long as you remember to call:

    instance.maintain( millis() );

Have a look at the [example files](./examples) to see a full working example.

## Support
I can not offer support for a free library like this, but you could always hire me as a consultant if you need help: [https://maketronics.no](https://maketronics.no)



