# Advanced-ish - Interpreting the bits

## Life's short, no time for compiling
  In embedded systems programming, specially in the makers ecosystem, it's frequent to make small changes in the program, as you experiment new things and correct old bugs. Every time we change a piece of code, the compiling process takes some time. Whilst not much, deploying and having your code run right after it, as it's ( and dis)advantages. The ESP8266 supports multiple interpreters, such as BASIC, the language that got Microsoft rolling and that was part of the computer revolution.
  
### The grandfather
   There's not much to say about BASIC, it's one of the most widespread languages and if you know a programmer with more than 40 years old, chances are it was his first programming language.
   If you want to know more, check [ESP8266 BASIC](https://www.esp8266basic.com/) , they have a nice tutorial of how to flash the chip. Also, check **mmiscool** [tutorial](http://www.instructables.com/id/Easiest-ESP8266-Learning-IR-Remote-Control-Via-WIF/?ALLSTEPS) on how to do a remote using Basic,
   
   
   <code> print "Basic is not old, it's vintage"</code> .


### This python is not gonna strangle you
  One of the most loved programming languages, it has seen an increasing use in embedded systems programming. It's easy to write, full of documentation and libraries. Almost everyone loves it, so it had to be ported into our beloved chip. Micropython was born. The [documentation](https://docs.micropython.org/en/latest/esp8266/esp8266/tutorial/index.html) is very good. Warning: the memory of the ESP8266 may be scarse. You will probably need the version with more flash memory in fancy projects.

### What do you get when a python and assembly mate?
  I could be here defining the Forth language, but [Elliot Williams](http://hackaday.com/2017/01/27/forth-the-hackers-language/) already did it in a way that would be almost impossible to trump. It's definitely a good read even if you have no interest in actually using the language. For the ESP8266, we have [Punyforth](https://github.com/zeroflag/punyforth). It's pretty much like Forth, with some differences that are documented in the official repo. It's certainly worth a try.
### Not quite like C, not quite like python
  Lua is a great language. There's more to it than just programming the TI-Nspire to make the math exercises for you. It's simple, yet powerfull. The [NodeMCU](https://github.com/nodemcu/nodemcu-firmware) repo has great documentation, from flashing the chip to actually experimenting with the firmware. Also, the already mentioned **Elliot Williams** did a great tutorial covering [how to use the firmware with MQTT](http://hackaday.com/2016/05/17/minimal-mqtt-networked-nodes/). You will learn a lot from it.
### Somebody said Javascript?
  There is room for Javascript in the IoT world. [Espruino](http://www.espruino.com/) is a JavaScript Interpreter for microcontrollers. They also make boards with JavaScript right away, but binaries for the ESP8266 exist. A [flashing guide](http://www.espruino.com/ESP8266_Flashing) is available, as well as some [examples](http://www.espruino.com/simple_data_logger). Check their [GitHub](https://github.com/espruino/Espruino) as well, for more documentation. 
  
## Bottom line
  While some of these projects are not yet free of bugs, some just exist for the sake of it, it's nice to break from the cycle of coding, compiling, flashing, and so on typical of micro systems programming. For small projects, something like MicroPython is utterly enjoyable. Experiment, there are plenty of things to work with and if you are a software developer or just trying to do some hacks, not having to go under the hood with something like C or Assembly can be definitely be a painkiller. 


[Main Menu](../readme.md)
