# Basics - Recieving commands through HTTP GET and HTTP POST

Displaying data in webpages is cool but we want more, we want automation! You can do this by passing some information in the page request.

Let's grasp some concepts first!

## HTTP GET Request

HTTP is an internet protocol to exchange information, and GET is a type of request that follows that protocol. Giberish? For example, when you write in your browser (Google Chrome for example) *www.google.com* you are making a GET request to Google's Server asking for the webpage.

### Arguments

What if you not only wanted to make a request but also wanted to attach some information to it? Like asking for a pizza and pass the information that you are vegetarian. You can do this by passing arguments in GET Requests, actually in any type of HTTP Web Request, like POST requests and so on, that we'll analyse later on.

In this case we are not ordering any pizzas (ohhhh...) instead we will send a value from 0-255 to specify the rate of a PWM signal.


## Functions that you can use:

```Arduino
server.method()                  // Returns HTTP_GET or HTTP_POST
int server.args()                // Returns the number of arguments in the request
String server.argName(int i)     // Returns the "name" of the argument number i.
String server.arg(String name)   // Returns the value of the 'name' argument
```

Example code:

```Arduino
server.on("/setpos", [](){
  // Check if there is only one argument and if that argument is called "rate"
  if(server.args()==1 && server.argName(0) == "rate"){

    // Save the value in a String
    String rate_s = server.arg("rate");

    // Convert it into a Integer
    int rate_i = rate_s.toInt();

    // Check if the value passed is between 0-255
    // Check if the String didn't cointain any more than the number
    // And the conversion from String to integer was successfull
    if(rate_i >= 0 && rate_i <= 255 && String(rate_i) == rate_s){

      // If so write that value to the pin
      analogWrite(pin, rate_i);

      // Send a response to the client, in this case, your PC
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

```Arduino
server.on("/setpos", HTTP_POST, [](){});
```

[Main Menu](../readme.md) | [Next](./ex4.md)