/*
  IoT Workshop
  github.com/Sleepy105
  02/2017
  Ex3
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "**********";
const char* password = "**********";

String webpage = "<h1>Hello World<h1/>";

ESP8266WebServer server(80);

void setup(){
	Serial.begin(115200);
	WiFi.begin(ssid, password);
	Serial.println("");

	// Wait for connection
	while(WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

	server.on("/", [](){
	  server.send(200, "text/html", webpage);
	});

	server.begin();
	Serial.println ( "HTTP server started" );
}

void loop(){
	server.handleClient();
}
