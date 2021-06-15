# picommons

C++ convenience library for Raspberry PI programming, based on [unofficial WiringPi project](https://github.com/WiringPi)

## Install WiringPi

```
sudo apt update
sudo apt install cmake git
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi/
./build
```

check if the configuration is ready

```
gpio -v
```

In my case return the follov informations:

```
gpio version: 2.60
Copyright (c) 2012-2018 Gordon Henderson
This is free software with ABSOLUTELY NO WARRANTY.
For details type: gpio -warranty

Raspberry Pi Details:
  Type: Pi Zero-W, Revision: 01, Memory: 512MB, Maker: Sony
  * Device tree is enabled.
  *--> Raspberry Pi Zero W Rev 1.1
  * This Raspberry Pi supports user-level GPIO access.
```

## Examples

All the examples are combined with the relative Fritzing file containing the wiring diagram:

- 01_blinking_led  
  building: g++ -o blinking_led_whit_button blinking_led_whit_button.cpp -lwiringPi -lwiringPiDev -lpthread
- 02_blinking_led_whit_button  
  building: g++ -o 02_blinking_led_whit_button 02_blinking_led_whit_button.cpp -lwiringPi -lwiringPiDev -lpthread

## Build lib

```
mkdir -p build
cd build
cmake ..
make
```
