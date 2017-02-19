# Basics - Recieving commands through HTTP GET and HTTP POST

Displaying data in webpages is cool but we want more, we want automation and having a different address for every command is just unthinkable.
What if you want to send a value from 0-100?

Thats when HTTP GET and HTTP POST come in.

Functions:

```c++
if(server.method() == HTTP_GET)
    //HTTP_GET == HTTP_GET
else
    //HTTP_POST

int server.args()                // Returns the number of arguments in the request
String server.argName(int i)     // Returns the "name" of the argument number i.
String server.arg(String name)   // Returns the value of the 'name' argument
```

Example code:

```c++
server.on("/setpos", [](){
  if(server.args()==1 && server.argName(0) == "rate"){
    String rate_s = server.arg("rate");
    int rate_i = rate_s.toInt();
    if(rate_i >= 0 && rate_i <= 255 && String(rate_i) == rate_s){   // This insures that the conversion went well, because when it fails it returns 0, which is a valid input.
      analogWrite(pin, rate_i);  // Outputs PWM to 'pin' with value 'rate_i' which has to be between 0 and 255.
      server.send(200, "text/html", "<p>Rate set to " + rate_s + "</p>");
    }
    else
      server.send(200, "text/html", "<p>Error with arg value</p>");
  }
  else
    server.send(200, "text/html", "<p>Invalid request</p>");
});
```

To force a page to only recieve requests of a certain type use:

<code>server.on("/setpos", HTTP_POST, [](){});</code>

[Back](https://github.com/nuieee/ESP8266-Workshop-Exercises)