![Banner](https://github.com/trackuino/trackuino/wiki/img/trackuino-banner-narrow.png)

This is a modified version of "Trackuino": an open-source APRS tracker based on the Arduino platform. It was designed primarily to track high altitude balloons, so it has other handy features like reading temperature sensors and a buzzer for acoustic location.

Trackuino is intended for use by licensed radio amateurs.

This modified version supports serial via SoftwareSerial and the DRA818V radio module

**Please note:** This project is a fork of Trackuino, they are the original creators of the code.

Features
========

 * Custom PCB
 * GPS: any NMEA GPS will work fine
 * Radio: DRA818V (500/1000 mW).
 * 1200 bauds AFSK using 8-bit PWM
 * Sends out standard APRS position messages (latitude, longitude, altitude, course, speed and time).
 * Internal/external temperature sensors (LM60) to read temperature in and outside the payload
 * Active/passive buzzer support to ease acoustic payload location.
 * 1 x SMA female plugs (radio out)
 * Open source (GPLv2 license), both software and hardware. In other words, do whatever you want with it: modify it, add it to your project, etc. as long as you opensource your modifications as well.

Status
========

 * GPS ok!
 * DRA818V ok!
 * APRS AF OUT ok!
 * Buzzer ok!
 * Temp Sensor ok!

Download
========

The latest version is 1.52.

Use the `Download ZIP` button to get the source code.

Building
========

If you are building for the Arduino platform you need Arduino IDE version 1.8.13 or higher. Get it from the [Arduino web site](http://arduino.cc/).

Unzip the firmware in your sketches directory and load it up by double-clicking on trackuino.ino.

The single most important configuration file is "config.h". The file is self-documented. Here is where you set up your callsign, among other things.

Flashing
========

**Important**: When flashing the Arduino/Uno32, remove the Venus GPS or the entire Trackuino shield. After flashing the firmware, you can plug it back in. The GPS and the host computer share the same serial port on the AVR, so they will conflict when used together.

Hardware
========

The [Mini APRS Tracker](https://www.iu2frl.it/micro-aprs-tracker/) contains all the informations. PCB drawings coming soon!

Related projects
================

Some other HAB-related projects I wrote:

  * https://www.iu2frl.it/tracker-aprs-su-icom-ic-e2820/ - APRS Tracker for ICOM IC-2820
  * https://www.iu2frl.it/arduino-aprs-beacon/ - an APRS beacon
  * https://www.iu2frl.it/category/autocostruzione/aprs-autocostruzione/ - APRS related articles

Support
=======

Discuss firmware bugs or suggestions in the issue tracker.
