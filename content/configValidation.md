# Test your configuration

Plug in the nodeMCU board.
Open to the Arduino IDE.

In the 'Tools' menu go to 'Port' and select the USB port the board is connected to.
Now, still in the 'Tools' menu go to 'Board', scroll down and select 'NodeMCU 0.9 (ESP-12 Module)'.

Now the fun part: CODE!!!!

```c++
#define BUILT_IN_LED 2

void setup(){
  // Code within these brackets will run only once, at board startup.
  pinMode(BUILT_IN_LED, OUTPUT);    // Initialize the GPIO pin 2 to be an Output
}


void loop(){
  // The code inside these brackets will run forever until the power is unplugged from the board.
  
  digitalWrite(BUILT_IN_LED, LOW);  // Turn on the LED (It's a active-low pin)
  
  delay(1000);                      // Wait 1 second before proceding to the next command.
  digitalWrite(BUILT_IN_LED, HIGH); // Turn off the LED
  delay(2000);                      // Wait 2 seconds before proceding to the next command.
}
```

If you see the board's LED blinking, you're all good.
If not, ask for assistance from one of the IEEE members.

## [Go Back](../readme.md)