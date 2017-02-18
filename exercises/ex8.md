# Advanced-ish - Blynk App

To much times we are on our bed and the switch to turn on/off the lights is sooo far away. What if we could control the lights with an app in our phone? With Blynk and a ESP8266, it’s so easy. In this tutorial you will learn how to control a LED which simulates your lights using your ESP and the Blynk app.

## The App
First, install the Blynk app.

https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&mt=8

https://play.google.com/store/apps/details?id=cc.blynk

Then, create an account. You need to associate an e-mail to the account in order to receive the credentials necessary to integrate the ESP with the app.

Install the Blynk library. You can download it at https://github.com/blynkkk/blynk-library/releases/tag/v0.4.4. Download the .zip file in the end of the page. To install the library, in your Arduino IDE go to Sketch -> Include library -> Add .zip library and then  give the path to your just downloaded library.

Now, with all things configured, it’s time to get things done. Open the Blynk app and start a new project. Select NodeMCU as the hardware and WiFi as your connection type. Now select the plus at the top right corner. Select a button, and then click on it. In the button settings, select the pin you want to control. You can select if the logical level is HIGH when the button is pressed (as it is predefined) or LOW. For now we will just select the pin. It’s all done in the app, so let’s start to code our dev board.

## Let's code the ESP8266
Create a new sketch in the Arduino IDE. Include the following libraries.

```c++
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
```

As in the other exercises, we need to connect the ESP to the WiFi. Also, we need to put the authentication code in the variable auth[], you can get it in the project settings in the app (the nut icon), or in your e-mail.

```c++
char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
```

In the setup function we just need to tell the Blynk library to connect with the app. Do this by using the <code>Blynk.begin()</code> function, passing the parameters auth, ssid and pass.

```c++
void setup()
{
  Blynk.begin(auth, ssid, pass);
}
```

The last step! In the beginning of the loop the ESP needs to run the Blynk instance, to receive from or send to information to the app. You can complete the code as you want, but remember to use the <code>delay()</code> function or you may miss some inputs!  

```c++
void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.

 }
```
Now, flash the code and press play in the Blynk app. It should detect the ESP after some seconds and you are now controlling the LED!  
Hop into https://blynk-examples.herokuapp.com/ to check more examples.