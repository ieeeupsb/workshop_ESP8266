# Advanced-ish - Blynk App

To much times we are in our bed and the switch to turn on/off the lights is sooo far away. What if we could control the lights with an app in our phone? With Blynk and an ESP8266, it’s so easy. In this tutorial you will learn how to control a LED which simulates your lights.

## The circuit

We will use a LED to simulate the lights, connecting the LED to the D0 pin in our dev board. Using a resistor and jumper cables, the circuit should look something like this:

![alt text](https://github.com/fpimenta/esp_workshop/blob/master/e782f7226577cb5059a5345e3de38d8e.png)

## The App
First, install the Blynk app.

https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&mt=8

https://play.google.com/store/apps/details?id=cc.blynk

Then, create an account.

Install the Blynk library. You can download it at https://github.com/blynkkk/blynk-library/releases/tag/v0.4.4. Download the <code>.zip</code> file in the end of the page. To install the library, in your Arduino IDE go to <code>Sketch -> Include library -> Add .zip library</code> and then give the path to your just downloaded library.

Now, with all things configured, it’s time to get things done. Open the Blynk app and start a new project. Select **NodeMCU** as the hardware and **WiFi** as your connection type. Now select the plus at the top right corner. Select a button, and then click on it. In the button settings, select the pin you want to control. You can select if the logical level is HIGH when the button is pressed (as it is predefined) or LOW. For now we will just select the pin we wan't to control. It’s all done in the app, let’s start to coding our dev board.

## Let's code the ESP8266
Create a new sketch in the Arduino IDE. Include the following libraries.

```c++
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
```

As in the other exercises, we need to connect the ESP to the WiFi. Also, we need to put the authentication code in the variable <code>auth[]</code>, you can get it in the project settings in the app (the nut icon), or in your e-mail.

```c++
char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
```

In the setup function we just need to tell the Blynk library to connect with the app. Do this by using the <code>Blynk.begin()</code> function, passing the parameters **auth**, **ssid** and **pass**.

```c++
void setup()
{
  Blynk.begin(auth, ssid, pass);
}
```

The last step! In the beginning of the loop the ESP needs to run the Blynk instance, to receive from or send to the app information. You can complete the code as you want, but remember not to use the <code>delay()</code> function or you may miss some inputs!  

```c++
void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.

 }
```
Now, flash the code and press play in the Blynk app. It should detect the ESP after some seconds and you are now controlling the LED!  
Hop into https://blynk-examples.herokuapp.com/ to check more examples.

[Main Menu](../readme.md) | [Next](./ex9.md)