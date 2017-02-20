# Introduction - Hello ESP8266

Like the Arduino this microcontroller has GPIO pins to interact with the real world, however while the Arduino operates at and outputs 5V, <strong>the ESP8266 chip runs at 3.3V</strong> the same voltage as it's logical outputs. This difference is very important to keep in mind when connecting them to other devices like sensors and motors, because there is the possibility of applying too little voltage and the sensor not being able to operate properly, or applying too much and ending up by frying the components. Caution is always advised. The pins are organized as follows:

![ESP8266 pinout](./images/esp8266.png)

As you can see there are many types of identifications on each pin, which means the same pin can have more that one function. For example, as you will see in a bit, you can identify a digital pin by its name or by its number, so you can use D0 or 16 to identify the first digital pin on the board.

We advise you you keep this tab open on the side as you will need to reference to it later.

Now lets get our hands on something meaningfull!

[Next](./helloworld.md)
