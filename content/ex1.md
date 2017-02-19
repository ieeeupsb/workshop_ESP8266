# The Basics - Getting readings from a photoresistor

Before we get our hands on the WiFi capabilities of the ESP8266 we have to have some data to work with.

And for those of you that are not confortable with microcontrollers such as this one, Arduino or similar, maybe we should start with the bare basics.

![State Machine](https://i.stack.imgur.com/YHIVL.gif)

In this workshop we will be using Arduino IDE to program the microcontroller. As you may have noticed in the validation page, the language is C++ and it is structured in two main routines.

```c++
void setup(){

}

void loop(){

}
```

The ```void setup()``` routine is used to put code that only runs once when the microcontroller boots. So it will consist in pin initializations (identifying outputs and inputs), connecting to WiFi, along with other initializations.

On the other hand ```void loop()``` is code that will run repeatly, you can think it as an uncondicional loop ( ```while(true)``` ) that 