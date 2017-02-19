# Introduction

And for those of you that are not confortable with microcontrollers such as this one, Arduino or similar, maybe we should start with the bare basics.

In this workshop we will be using Arduino IDE to program the microcontroller. The Arduino ecosystem is programmed in C++ and it is structured in two main routines:

```c++
void setup(){

}

void loop(){

}
```

The code inside the <code>void setup()</code> routine will only run once when the microcontroller boots. So it will consist in pin initializations (identifying outputs and inputs), connecting to WiFi, along with other initializations.

On the other hand any code inside <code>void loop()</code> will run repeatedly forever. You can think of it as an uncondicional loop (<code>while(true)</code>) that is commonly used to update readings from sensors, and calculate new outputs.