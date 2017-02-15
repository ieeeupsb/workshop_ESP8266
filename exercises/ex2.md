# Displaying data in a webpage

Create a new arduino sketch. For this example we will need a few libraries.
Add these at the top of the file.

```c++
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
```

Still before the <code>void setup()</code> routine we will need to create a object of the ESP8266WebServer class.
If you don't know what classes are, don't worry. Just think of them as C structs where you can also add functions and not only variables.
We will also need a way to store our WiFi credentials.

```c++
const char* ssid = "**********";
const char* password = "**********";

ESP8266WebServer server(80);					// Create a server on port 80
```

Now fill the <code>setup()</code> routine with this code.

```c++
Serial.begin(115200);															// Initialize the serial bus with a 115200 baud rate. This will allow us to send data back to the computer through the USB cable
WiFi.begin(ssid, password);												// Connect to the WiFi network set in the code above.
Serial.println("");

while (WiFi.status() != WL_CONNECTED){						// Wait for the connection to be established.
  delay(500);
  Serial.print(".");															// Send a '.' through the serial bus while we wait.
}

Serial.println("");																// Send a '\n'
Serial.print("Connected to ");										// 
Serial.println(ssid);															// Print the network the board connected to 
Serial.print("IP address: ");											//
Serial.println(WiFi.localIP());										// and the IP address it recieved from the DHCP server

server.on("/", [](){															// Create a webpage for the server
  server.send(200, "text/plain", "hello world");	//
});																								//

server.begin();																		// Start the server
Serial.println("HTTP server started");						// Signal that to the PC
```

Let's pay a little bit more attention to the webpage creation code.

```c++
server.on("/", [](){
  server.send(200, "text/plain", "hello world");
});	
```

<code>server.on()</code> is used to create a webpage on the 'server' object.

The first argument ("/") sets the path to that page. In this case, root.

The second is a function. That means you can do stuff like this:

```c++
server.on("/coolstuff.html", serveWebpage);	
```

The only thing the function REQUIRES is a <code>server.send()</code> function call.

This functions first argument is the [HTTP response code](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes) to send when a client connects to the webpage.

The second is the type of content in the page:
 * text/plain
 * text/html
 * application/json
 * etc.

The last is a String with all the text and/or code for the webpage.

Think of this function as the <code>return</code> call in a normal function.
