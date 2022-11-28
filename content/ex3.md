# Basics - Receiving commands through HTTP GET and HTTP POST

Displaying data in webpages is cool but we want more, we want automation! You can do this by passing some information in the page request.

Let's grasp some concepts first!

## HTTP GET Request

HTTP is an internet protocol to exchange information, and GET is a type of request that follows that protocol. Giberish? For example, when you write in your browser (Google Chrome for example) *www.google.com* you are making a GET request to Google's Server asking for the webpage.

### Arguments

What if you not only wanted to make a request but also wanted to attach some information to it? Like asking for a pizza and passing the ID of the pizza you want. You can do this by passing arguments in GET Requests (Actually you can use POST as well, as you'll see).

In this case you're not going to order any pizzas. Instead we will send a value from 0-255 to specify the rate of a PWM (Pulse Width Modulation) signal.

Examples of passing arguments with GET requests:
```
website.com/webpage?arg1=value1
website.com/webpage?arg1=value1&arg2=value2
```


## Functions that you can use:

```Arduino
server.method()                  // Returns HTTP_GET or HTTP_POST
int server.args()                // Returns the number of arguments in the request
String server.argName(int i)     // Returns the "name" of the argument number i.
String server.arg(String name)   // Returns the value of the 'name' argument
```

To force a page to only recieve requests of a certain type use:

```Arduino
server.on("/setpos", HTTP_GET, [](){});
```
or
```Arduino
server.on("/setpos", HTTP_POST, [](){});
```

## Controlling at a distance

Now that you can display simple pages, and send commands to your ESP through HTTP GET or POST, can you make a page that does all of this at once? Let's control different LEDs in a single page with some buttons using **HTTP POST**...
</br>As you will notice, commands sent by POST will not show up in the URL as the GET arguments do.

### Introducing HTML

To send commands through a webpage in a simple and visually appealing way, you don't want to keep changing a value in a URL manually...
</br>How can you make a simple button?

```HTML
<button>Click me!</button>
```
This is the HTML code that shows a simple button in a webpage. But keep in mind that this outputs a very simple (and ugly) button. We'll fix this (the button size, shape, color, and position) using it's **style** property. Without getting to much into webdevelopment, in the end the code for your button will probably look like this:

```HTML
<button type="submit" name="BUILTIN" value="true" style="font-size: 30px; border: none; border-radius: 15px; padding: 15px 32px; color: white; background-color: rgb(23, 57, 86); box-shadow: 5px 5px 5px rgb(43, 131, 183);">Switch built-in led</button>
```
>To keep it simple, we won't use CSS. In fact, to simplify even more, we'll put the HTML code for the whole page in a single line. **It is not be recommended**, and it is definitely not easy to understand, but for now it's good enough.

We want a simple page that looks a little something like this:
```HTML
<html>
	<body style="background: rgb(57, 181, 255); text-align: center;">
		<div style="margin-top: 100px;position: relative;">
		<form action="/switch" method="POST">
			<button type="submit" name="BUILTIN" value="true" style="font-size: 30px; border: none; border-radius: 15px; padding: 15px 32px; color: white; background-color: rgb(23, 57, 86); box-shadow: 5px 5px 5px rgb(43, 131, 183);">Switch built-in led</button>
			</br><button type="submit" name="OUTSIDE" value="true" style="font-size: 30px; border: none; border-radius: 15px; padding: 15px 32px; color: white; background-color: rgb(23, 57, 86); box-shadow: 5px 5px 5px rgb(43, 131, 183); margin-top: 30px;">Switch outside led</button>
		</form>
		</div>
		<div style="margin-top: 100px; position: relative;">
			<button style="font-size: 40px;border: none;border-radius: 20px;padding: 15px 32px;color: white;background-color: rgb(23, 57, 86);">BUILT-IN ON</button>
			</br><button style="margin-top: 20px;font-size: 40px;border: none;border-radius: 20px;padding: 15px 32px;color: white;background-color: rgb(23, 57, 86);">OUTSIDE ON</button>
		</div>
	</body>
</html>
```
This page has two buttons, one to **switch the built-in LED** and another one to **switch an outside LED**, that we'll be connecting to **D1**.
</br>When you push any of those buttons, it will send a **POST request** to **192.168.XXX.XXX/switch**, with an argument called ```BUILTIN``` or ```OUTSIDE``` deppending on the LED you're trying to switch. Remember, you won't see this argument anywhere besides the code.

Now we need to actually switch the LEDs on or off... This is how we'll do it:
```Arduino
if(server.args()==2 && server.argName(0) == "BUILTIN"){
      built_value=!built_value;
      digitalWrite(LED_BUILTIN,!built_value);
    } else if(server.args()==2 && server.argName(0) == "OUTSIDE"){
      outside_value=!outside_value;
      digitalWrite(LED_OUTSIDE,outside_value);
    }
```
> The exclamation mark (**!**) means "**not**" or "**negative**" when programming. So we're just turning the LED to the opposite state it is currently in. 

Now we want some indicators, that change color according to the state of the LED (red for OFF, green for ON):
```Arduino
if(built_value){
        BIState = "ON"; // Active high
        BIColor = "#2a7c0c";
      }else{        
        BIState = "OFF"; // Active high
        BIColor = "#cc2a18";
      }

      if(outside_value){
        OSState = "ON"; // Active high
        OSColor = "#2a7c0c";
      }else{        
        OSState = "OFF"; // Active high
        OSColor = "#cc2a18";
      }
```
>For now this might be hard to understand, particularly if never used HTML, but there is a lot of documentation online for you to get started. Just look for "HTML buttons", "HTML color", "HTML forms", ...

### Final code

This is our "final code" for this example. Try uploading it to your ESP8266, and test the webpage :wink:

```Arduino
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define LED_OUTSIDE 15

//Credentials of the WiFi you're connecting to
#define WIFI_NAME "************"
#define WIFI_PASSWORD "**********"

ESP8266WebServer server(80);    //Open server on port 80 - HTTP port
bool built_value=false;
bool outside_value=false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_OUTSIDE, OUTPUT);

  Serial.begin(115200);              // Initialize the serial bus with a 115200 baud rate. This will allow us to send data back to the computer through the USB cable
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);                       // Connect to the WiFi network set in the code above.
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED){            // Wait for the connection to be established.
    delay(500);
    Serial.print(".");                              // Send a '.' through the serial bus while we wait.
  }

  Serial.println("");                               // Send a '\n'
  Serial.print("Connected to ");                    // 
  Serial.println(WIFI_NAME);                             // Print the network the board connected to 
  Serial.print("IP address: ");                     //
  Serial.println(WiFi.localIP());                   // and the IP address it recieved from the DHCP server

//server.method()                  // Returns HTTP_GET or HTTP_POST
//int server.args()                // Returns the number of arguments in the request
//String server.argName(int i)     // Returns the "name" of the argument number i.
//String server.arg(String name)   // Returns the value of the 'name' argument

//Method seems to be always POST
 server.on("/switch", [](){
  String BIState;
  String BIColor;
  String OSState;
  String OSColor;
  Serial.print("Server args and name: ");
  Serial.print(server.args());
  Serial.println(server.argName(0));
  Serial.println(server.argName(1));

    if(server.args()==2 && server.argName(0) == "BUILTIN"){
      Serial.println("inside BUILTIN /switch");
      built_value=!built_value;
      digitalWrite(LED_BUILTIN,!built_value);
    } else if(server.args()==2 && server.argName(0) == "OUTSIDE"){
      Serial.println("inside OUTSIDE /switch");
      outside_value=!outside_value;
      digitalWrite(LED_OUTSIDE,outside_value);
    }
    
    /*
      Serial.println("inside /switch html define");
      if(server.method()==HTTP_GET){
        Serial.println("GET REQUEST"); 
      }else if(server.method()==HTTP_POST){
        Serial.println("POST REQUEST"); 
      }else {Serial.println("Something other than POST or GET");}
       */
      if(built_value){
        BIState = "ON"; // Active high
        BIColor = "#2a7c0c";
      }else{        
        BIState = "OFF"; // Active high
        BIColor = "#cc2a18";
      }

      if(outside_value){
        OSState = "ON"; // Active high
        OSColor = "#2a7c0c";
      }else{        
        OSState = "OFF"; // Active high
        OSColor = "#cc2a18";
      }
      server.send(200, "text/html", "<html> <body style=\"background: rgb(57, 181, 255); text-align: center;\"> <div style=\"margin-top: 100px;position: relative;\"> <form action=\"/switch\" method=\"POST\"> <button type=\"submit\" name=\"BUILTIN\" value=\"true\" style=\"font-size: 30px; border: none; border-radius: 15px; padding: 15px 32px; color: white; background-color: rgb(23, 57, 86); box-shadow: 5px 5px 5px rgb(43, 131, 183);\">Switch built-in led</button> </br><button type=\"submit\" name=\"OUTSIDE\" value=\"true\" style=\"font-size: 30px; border: none; border-radius: 15px; padding: 15px 32px; color: white; background-color: rgb(23, 57, 86); box-shadow: 5px 5px 5px rgb(43, 131, 183); margin-top: 30px;\">Switch outside led</button> </form> </div> <div style=\"margin-top: 100px; position: relative;\"> <button style=\"font-size: 40px;border: none;border-radius: 20px;padding: 15px 32px;color: white;background-color: " + BIColor + ";\">BUILT-IN " + BIState + "</button> </br><button style=\"margin-top: 20px;font-size: 40px;border: none;border-radius: 20px;padding: 15px 32px;color: white;background-color:"+ OSColor +";\">OUTSIDE "+ OSState +"</button> </div> </body> </html>");
  });

  server.on("/", [](){
    String BIState = digitalRead(LED_BUILTIN)?"ON":"OFF"; // Active high
    String BIColor = digitalRead(LED_BUILTIN)?"#cc2a18":"#2a7c0c";
    String OSState = digitalRead(LED_OUTSIDE)?"ON":"OFF";
    String OSColor = digitalRead(LED_OUTSIDE)?"#2a7c0c":"#cc2a18"; 
    server.send(200, "text/html", "<html> <body style=\"background: rgb(57, 181, 255); text-align: center;\"> <div style=\"margin-top: 100px;position: relative;\"> <form action=\"/switch\" method=\"POST\"> <button type=\"submit\" name=\"BUILTIN\" value=\"true\" style=\"font-size: 30px; border: none; border-radius: 15px; padding: 15px 32px; color: white; background-color: rgb(23, 57, 86); box-shadow: 5px 5px 5px rgb(43, 131, 183);\">Switch built-in led</button> </br><button type=\"submit\" name=\"OUTSIDE\" value=\"true\" style=\"font-size: 30px; border: none; border-radius: 15px; padding: 15px 32px; color: white; background-color: rgb(23, 57, 86); box-shadow: 5px 5px 5px rgb(43, 131, 183); margin-top: 30px;\">Switch outside led</button> </form> </div> <div style=\"margin-top: 100px; position: relative;\"> <button style=\"font-size: 40px;border: none;border-radius: 20px;padding: 15px 32px;color: white;background-color: " + BIColor + ";\">BUILT-IN " + BIState + "</button> </br><button style=\"margin-top: 20px;font-size: 40px;border: none;border-radius: 20px;padding: 15px 32px;color: white;background-color:"+ OSColor +";\">OUTSIDE "+ OSState +"</button> </div> </body> </html>");
  });
  
  server.begin();                                   // Start the server
  Serial.println("HTTP server started");            // Signal that to the PC
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop(){
  server.handleClient();
  delay(100);
}
```

[Main Menu](../readme.md) | [Next](./ex10.md)
