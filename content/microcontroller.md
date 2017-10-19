# Introduction - Programming a microcontroller

And for those of you that are not confortable with microcontrollers such as this one, Arduino or similar, maybe we should start with the bare basics.

In this workshop we will be using Arduino IDE to program the microcontroller. The Arduino ecosystem is programmed in C++ and it is structured in two main routines:

```c++
void setup(){

}

void loop(){

}
```

The code inside the <code>void setup()</code> routine will only run once when the microcontroller boots. So it will consist in pin initializations (identifying outputs and inputs), connecting to WiFi, along with other initializations.

On the other hand ```void loop()``` is code that will run **repeatedly**. You can think of it as an uncondicional loop ( ```while(true)``` ) that is commonly used to update readings from sensors (inputs), and calculate new outputs.

[Main Menu](../readme.md) | [Next](./hiesp.md)
