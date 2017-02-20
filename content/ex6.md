# Quality of Life - AP mode and Captive Portals

You know those open WiFi networks that you connect to and regardless of the page you are trying to access, it manages to always serve you the exact same login page.
That's page is called a Captive Portal because, well it's a webportal that keeps you 'captive' until you do whatever it wants you to do.

The ESP has the ability to create Captive Portals. Simple ones and ones that you would need a whole PhD just to understand how they work.

Let's get to it.

### Creating an AP

The code below is the base from which we will build our Captive Portal. It creates a AP. There are few differences from the code used to connect to a AP.

> Side note: The ESP can create an AP and connect to another AP at the same time, but due to limitions of the chip, the created AP will be in the same WiFi channel of the one it connects to.
> Mesh networks anyone? ;) (A little tip: There is a example sketch showing how to do it, but that is a thing for you to try later on)

```c++
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to the desired Access Point credentials. */
const char *ssid = "**********";
const char *password = "**********"; // AT LEAST 8 characters.

ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
```

If you want your AP to be open, a little change to the code is required. Use <code>WiFi.softAP(ssid);</code> or <code>WiFi.softAP(ssid, empty_password_string);</code>

This code is fine if you live on a area where WiFi networks are scarce. The problem is that the function used always creates the AP in channel 1
(If you do not know what WiFi channels are, just know that if you have multiple networks on the same channel they cause interfetrence with each other).

To select the channel of the AP, use: <code>WiFi.softAP(ssid, pass, channelNbr);</code>

> If you are doing this in the workshop ask for the channel to use so you don't get a interference.

### Adding a Captive Portal

Add this library: <code>DNSServer.h</code>

Add at the global scope:
```c++
#define DNS_PORT 53
DNSServer dnsServer;
```

Rest of the needed code:

```c++
void setup(){
  ...
  dnsServer.start(DNS_PORT, "*", myIP); //Redirects traffic going to "*" ('*' means everything) to the IP of your device ('myIP' in the AP example code).
}

void loop(){
  ...
  dnsServer.processNextRequest();
  ...
}
```

That should do the trick.

[Main Menu](../readme.md) | [Next](./ex7.md)