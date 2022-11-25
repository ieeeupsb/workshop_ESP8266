# Serial

Serial is a mean of communication used in many connecters we use daily such as USB, Ethernet, Bluetooth, and many others. Serial communication is a great way to debug your code!

### Serial.begin(BAUD_RATE)

This method is used to initialize Serial communication at a given baud rate (or speed).

### Serial.println(CONTENT_TO_PRINT)

This is used to print a value in a different line. Which means that is equivalent to doing <code>Serial.print()</code> with a <code>"\n"</code> at the end.

### Serial Monitor

To see the Serial values on the screen, all you have to do is click on the Serial Monitor button on the upper right corner of the IDE and <strong>make sure that 115200 is selected</strong> as the baud rate on the bottom of the Serial Monitor window, otherwise you won't be able to tell what is being printed on the screen. (The value should always be the same as the one set in your code)

![Serial](./images/serial.png)

[Main Menu](../readme.md) | [Next](./ex2.md)
