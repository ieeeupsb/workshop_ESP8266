# Advanced-ish - OTA updates

If you were curious enough to take a look at SPIFFS, during the [EEPROM exercise](./ex5.md) you probably noticed a little something on the flash layout schematic: "OTA update".

There are a few ways to implement OTA (Over The Air) updates in the ESP8266. You have the ArduinoOTA library (easy way), and a couple of libraries and projects from the community that alow you to request the new software from a server and make everything simpler when updating a lot of devices at the same time.

Here we will be using the ArduinoOTA library because the other options would require a server and a lot of fiddling around and tweaking it's settings.

> If you end up configuring such a server, let us know how you did it by creating a new issue in this repo. We love to know what people are using the skills learned in our workshops for. Ideas and projects are always welcome.

## ArduinoOTA

We're not going to explain this example in as much detail as in previous exercises, because that would be a workshop on it's own. All the exercises in the Advanced section are for you to develop an idea of the capabilities of the ESP and work on them at home.

Let's now access one of the biggest repositories of knowledge about the ESP8266. The 'Examples' menu in the Arduino IDE.
This thing is the best place to get an idea of how all the libraries work. You can try out Mesh Networks and ESP-NOW comunication later, but right now let's focus on OTA.

Go to <code>File > Examples > ArduinoOTA > BasicOTA</code>

This sketch has everything you need to upload code over-the-air.

> I recomend changing the hostname so you know with board is yours. (line 24 of the sketch)

Try uploading the that code to the ESP and let it boot. Then you should see in the <code>Tools > Port</code> menu your board as a network device.

After that, add a few lines of code to make the LED blink and try uploading over-the-air. <strong>Everytime you upload code over-the-air you need to include the code in this example. Otherwise, when the board boots it will lose the capability of recieving updates over-the-air and you will need to update it through USB.</strong>

You now have a few hours of fun  ahead of you tinkering with OTA updates.

[Main Menu](../readme.md) | [Next](./ex8.md)
