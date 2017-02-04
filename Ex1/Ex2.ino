/*
  IoT Workshop
  github.com/Sleepy105
  02/2017
  Ex2 - Código baseado num exemplo da Adafruit Library para o sensor DHT11
*/

#include <DHT.h>

#define DHTPIN 5     // Pino ao qual ligar o sensor DHT11
#define DHTTYPE DHT11   // Seleciona o modelo do sensor como DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Este código corre apenas uma vez, quando a placa é inicializada.
  Serial.begin(115200);     // Inicia a comunicação serial com uma baud rate de 115200.
  dht.begin();     // Inicia a comunicação com o sensor DHT11
}

void loop() {
  // Este código corre repetidamente até a energia ser cortada à placa.
  delay(1000);

  // Ler a humidade ou temperatura pode demorar até 250 millisegundos!
  // O sensor é lento e os dados da humidade ou temperatura podem ter um atraso de 2 segundos.
  // Ler a humidade em %
  float humidity = dht.readHumidity();
  // Ler a temperatura em Celsius (por defeito).
  float temperature = dht.readTemperature();

  // Verificar se alguma das leituras falhou e tentar novamente.
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Calcula o indice de calor em Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(temperature, humidity, false);

  // Imprime a humidade, temperatura e indice de calor.
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C ");
}