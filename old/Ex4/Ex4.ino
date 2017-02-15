/*
  IoT Workshop
  github.com/Sleepy105
  02/2017
  Ex4
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define BUILT_IN_LED 2

const char* ssid = "**********";
const char* password = "**********";

String webpage = "<!DOCTYPE html> <html> <body> <button onclick=\"window.location.href='/on'\">ON</button> <button onclick=\"window.location.href='/off'\">OFF</button> </body> </html>";

ESP8266WebServer server(80);

void setup(){
	Serial.begin(115200);
	WiFi.begin(ssid, password);
	Serial.println("");

  pinMode(BUILT_IN_LED, OUTPUT);

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
  server.on("/on", [](){
    digitalWrite(BUILT_IN_LED, LOW);
    server.send(200, "text/html", webpage);
  });
  server.on("/off", [](){
    digitalWrite(BUILT_IN_LED, HIGH);
    server.send(200, "text/html", webpage);
  });

	server.begin();
	Serial.println ( "HTTP server started" );
}

void loop(){
	server.handleClient();
}
