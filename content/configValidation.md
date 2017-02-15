# Test your configuration

Plug in the nodeMCU board.
Open to the Arduino IDE.

In the 'Tools' menu go to 'Port' and select the USB port the board is connected to.
Now, still in the 'Tools' menu go to 'Board', scroll down and select 'NodeMCU 0.9 (ESP-12 Module)'.

Now the fun part: CODE!!!!

```c++
#define BUILT_IN_LED 2

void setup(){
  // Este código corre apenas uma vez, quando a placa é inicializada.
  pinMode(BUILT_IN_LED, OUTPUT);     // Inicialização do pin ligado ao LED da placa como um output
}


void loop(){
  // Este código corre repetidamente até a energia ser cortada à placa.
  
  digitalWrite(BUILT_IN_LED, LOW);   // Liga-se o LED (Sim, os pinos no ESP8266 ficam activos quando ligados à massa)
  
  delay(1000);                      // Espera-se um segundo
  digitalWrite(BUILT_IN_LED, HIGH);  // Desliga-se o LED ao aplicar a diferença de potêncial correspondente ao nível lógico HIGH (3.3V)
  delay(2000);                      // Esperam-se dois segundos
}
```

If you see the board's LED blinking, you're all good.
If not, ask for assistance from one of the IEEE members.
