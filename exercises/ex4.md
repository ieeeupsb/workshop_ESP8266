# Quality of Life - Static IP and mDNS

If you want to deploy your ESP inside walls or other difficult-to-access places, it's not very practical to have to plug in a cable to it every time it boots, just to see it's IP address.

To this problem, you have 2 solutions:
 * Static IP address (Not recomended. Can create conflicts with other devices)
 * mDNS

## Static IP address

If you want your ESP to have a static IP address, the only thing you need to add are these lines of code before you call <code>WiFi.begin()</code>:

```c++
IPAddress ip(192, 168, 1, xx);      // where xx is the desired IP Address
IPAddress gateway(192, 168, 1, 1);  // set gateway to match your network
IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your network

WiFi.config(ip, gateway, subnet);
```

That should do the trick, but I recomend avoiding this, which leaves us with mDNS.

## mDNS

### Requirements

- ESP8266WiFi library
- MDNS support in your operating system/client machines:
  - For Mac OSX support is built in through Bonjour already.
  - For Linux, install [Avahi](http://avahi.org/).
  - For Windows, install [Bonjour](http://www.apple.com/support/bonjour/).

### Usage

```c++
#include <ESP8266mDNS.h>

const char* Hostname = "myVeryOwnESP8266";    // 'hostname' is a variable in a library, so we use 'Hostname' here.
...

void setup(){
  ...

  if (MDNS.begin(Hostname)) {
    Serial.println("MDNS responder started");
  }

  ...
}
```

To then access your board, you just have to type <code>myVeryOwnESP8266.local</code> in your browser's address bar.

If you want to learn more about this, like how to find all the ESPs on the network, look at the library documentation [here](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266mDNS).

[Return to Exercises](./)