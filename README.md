#arduino-slip

A number of examples of arduinos, sensors, and Serial Over IP (SLIP).  This project relies heavily on the amazing OSC arduino implementation from CNMAT. 

https://github.com/CNMAT/OSC

##Potentiometer
- FlockBox: a teensy with 8 potentiometers attached (includes Flocking.js node.js synth)
- FlockingSlipSerial: Legacy first crack at all of this

##ZX Sensor Examples use the [Sparkfun Sensor.](https://www.sparkfun.com/products/12780)
- testzxsensor: a Wiring example for raw i2c communication (not mine, searching for attribution)
- zxneopixel: shines a different colour for swipe gestures
- slipneopixel: neopixel feedback and sends oscbundle (tested reading with osc.js serial example)
