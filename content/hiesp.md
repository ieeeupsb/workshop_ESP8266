# Introduction - Hello ESP8266

Like the Arduino this microcontroller has GPIO pins to interact with the real world, however while the Arduino operates at and outputs 5V the ESP8266 chip runs at 3.3V the same voltage as it's logical outputs. This difference is very important to keep in mind when connecting them to other devices like sensors and motors, because there is the possibility of applying to little voltage and the sensor not being able to operate properly, or applying too much and ending up by frying the components. Caution is always advised. The pins are organized as follows:

![ESP8266 pinout](./images/esp8266.png)

[Next](./helloworld.md)
