/*
  IoT Workshop
  github.com/Sleepy105
  02/2017
  Ex1
*/

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
