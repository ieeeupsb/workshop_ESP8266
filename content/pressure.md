# Basics - Measure Pressure

Let's apply some pressure now. For that lets grab our BMP180, a sensor to measure **atmosferic pressure** (yes, don't smash it just yet).

## Getting the tools

For this sensor there is a nice library that can help you keeping things simple. The library name has a different name from the sensor, but it is compatible also. You'll come across this kind of things very often.

Go ahead and grab the **Adafruit BMP085** library from the library manager, going into *Sketch -> Include Library -> Manage Libraries* and searching for *Adafruit BMP085*.
Now that you've downloaded the library, you can use it freely.

## Before getting your hands dirty

Before you get mesurements from a sensor it is **very common** to be required to initialize the sensor in *void setup()* specially I2C sensors like this one.

So all you have to do is create an instance of *Adafruit_BMP085* and make it global by writing this outside any function:

```Arduino
Adafruit_BMP085 bmp;
```

It is crucial to make it global so you can acess it no matter what function you're on, like *void setup()* or *void loop()* or any other.

## Initialize the sensor

All you need to do is call the following function on *void setup()*

```Arduino
bmp.begin()
```
## Taking Mesurements

Now you're ready to work!

These are the functions you can use along with the variable type they return. Their names are self explanatory:

```Arduino
float readTemperature(void);
int32_t readPressure(void);
int32_t readSealevelPressure(float altitude_meters = 0);
float readAltitude(float sealevelPressure = 101325); // std atmosphere
uint16_t readRawTemperature(void);
uint32_t readRawPressure(void);
```

Go ahead and make it print those values onto the **Serial Monitor** and later on in webpages... You'll get there!

Ready? Let's move!

[Main Menu](../readme.md) | [Next](./movement.md)