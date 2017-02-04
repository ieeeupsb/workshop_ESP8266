/*
  IoT Workshop
  github.com/Sleepy105
  02/2017
  Ex3
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Subestitui o SSID e password pelo que vai ser dado na aula.
const char* ssid = "**********";
const char* password = "**********";

// Texto que constitui a pagina web (em HTML).
String webpage = "<h1 style="text-align: center; margin-top: 200px; font-size: 12em">Hello World!<h1/>";

// Inicia na porta 80.
ESP8266WebServer server(80);

void setup(){
	// Este código corre apenas uma vez, quando a placa é inicializada.
	Serial.begin(115200);
	WiFi.begin(ssid, password);
	Serial.println("");

	// Esperar para conectar.
	while(WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.print(".");
	}

	// Imprime o endereço IP onde se encontra o ESP8266.
	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

	// Localiza esta pagina no endereço root.
	server.on("/", [](){
	  server.send(200, "text/html", webpage);
	});

	// Inicia o servidor.
	server.begin();
	Serial.println ( "HTTP server started" );
}

void loop(){
	// Esta funcao faz magia e permite ao servidor comunicar com o cliente.
	server.handleClient();
}
