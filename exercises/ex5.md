# Quality of Life - EEPROM

Sometimes it comes in handy to be able to store information in the ESP's memory that doesn't get blown up when the chip powers down.
That's where the EEPROM comes in.

> Side note: The ESP doesn't actually have EEPROM, it simulates 512 bytes of it, therefore you have fewer write cycles available before that part of memory dies (It is still a very large number of cycles, but it is advisable not to be constantly writting to it).
> If you want to store files and not just variables read on: [SPIFFS](https://github.com/esp8266/Arduino/blob/master/doc/filesystem.md).

Using the EEPROM is rather simple.

Include the <code>EEPROM.h</code> library.

<code>EEPROM.begin(512);</code> Makes the EEPROM available to your programm. 512 bytes of it. (The EEPROM is limited to 512 bytes on the ESP.)

<code>EEPROM.write(byte_nbr,value);</code> Write 'value' to the 'byte_nbr' byte of the EEPROM. (REMEMBER: 1 byte is limited to the decimal number of 255)

<code>value = EEPROM.read(byte_nbr);</code> Saves the value of the 'byte_nbr' byte of the EEPROM to the 'value' variable.

As simple as that.

> Try writting a simple sketch that saves the WiFi credentials into the EEPROM, so you won't have to upload hardcoded credentials in your projects.

[Return to exercises](./..)