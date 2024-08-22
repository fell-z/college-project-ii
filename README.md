# College Project II

Simple code for a 'Sumo Robot'.

## How it works

The robot's electronic structure consists of two motors, one relay module and one HC-05 Bluetooth module.

The bluetooth module works between an android app and the Arduino Serial interface, receiving
commands from the app in the format \[forward, backwards, left\_steer, right\_steer, specified\], each value
 is a '0' or '1'.

The enum 'PINS' define the pins of each channel of the relay module, sequentially.

The logic for opening any channel configuration is similar to maneuvering a tank, two axes to
go forward, backwards, rotate clockwise or counterclockwise.
