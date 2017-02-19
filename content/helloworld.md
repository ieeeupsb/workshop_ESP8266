# The Basics - Hello World

So now we'll get our hands dirty! Lets start small by simply making a LED blink.

All we have to do is to connect the longer (positive) pin of the LED to a logic pin of the ESP8266 and the other pin to Ground (GND) as follows:

![Hello World](./images/helloworld.png)

Next you have to program it!

```c++
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

[Next](./ex1.md)