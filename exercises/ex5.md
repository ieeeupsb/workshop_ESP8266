# Quality of Life - EEPROM

Sometimes it comes in handy to be able to store information in the ESP's memory that doesn't get blown up when the chip powers down.
That's where the EEPROM comes in.

> Fun Fact: The ESP doesn't actually have EEPROM, it simulates 512 bytes of it using the chip's flash memory, therefore you have fewer write cycles available before that part of memory dies (It is still a very large number of cycles, but it is advisable not to be constantly writting to it).

> If you want to store files and not just variables read on: [SPIFFS](https://github.com/esp8266/Arduino/blob/master/doc/filesystem.md).

Using the EEPROM is rather simple.

Include the <code>EEPROM.h</code> library.

<code>EEPROM.begin(512);</code> Makes the EEPROM available to your program. 512 bytes of it. (The EEPROM is limited to 512 bytes on the ESP.)

<code>EEPROM.write(byte_nbr,value);</code> Stages a write (See <code>commit()</code>) of 'value' to the 'byte_nbr' byte of the EEPROM. (REMEMBER: 1 byte is limited to the decimal number of 255)

<code>value = EEPROM.read(byte_nbr);</code> Saves the value of the 'byte_nbr' byte of the EEPROM to the 'value' variable.

<code>bool success = EEPROM.commit();</code> Actually writes the data to the EEPROM and returns if it was successful.

<code>EEPROM.end();</code> 'Closes' the EEPROM, but does a <code>commit()</code> first.

As simple as that.

> Try writting a simple sketch that saves the WiFi credentials into the EEPROM, so you won't have to upload hardcoded credentials in your projects.
> The SSID max size is 32 bytes (characters) and the PASSWORD max size is 64 bytes.

[Return to exercises](./)
