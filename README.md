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

In my case return the follow informations:

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
- 03_blinking_led_whit_interrupt  
  building: g++ -o 03_blinking_led_whit_interrupt 03_blinking_led_whit_interrupt.cpp -lwiringPi -lwiringPiDev -lpthread
- 04_display_1602  
  building: g++ -o 04_display_1602 04_display_1602.cpp -I../include -L../build -lwiringPi -lwiringPiDev -lpthread -lpicommons

## Build lib

```
mkdir -p build
cd build
cmake ..
make
```

## How to cross compile on Linux (Ubuntu 20.10)
form [https://stackoverflow.com/questions/19162072/how-to-install-the-raspberry-pi-cross-compiler-on-my-linux-host-machine](https://stackoverflow.com/questions/19162072/how-to-install-the-raspberry-pi-cross-compiler-on-my-linux-host-machine). 
(Thank to [Stefan Profanter](https://stackoverflow.com/users/869402/stefan-profanter))  
  
This tutorial is based on @Stenyg answer. In addition to many other solutions in the internet, this tutorial also supports older Rasperry Pi (A, B, B+, Zero) based on the ARMv6 CPU. See also: GCC 8 Cross Compiler outputs ARMv7 executable instead of ARMv6. 

### Set up the toolchain 
There is no official git repository containing an updated toolchain (See [https://github.com/raspberrypi/tools/issues/102](https://github.com/raspberrypi/tools/issues/102)).
  
I created a new github repository which includes building and precompiled toolchains for ARMv6 based on GCC8 and newer:  
[https://github.com/Pro/raspi-toolchain](https://github.com/Pro/raspi-toolchain)
  
As mentioned in the project's readme, these are the steps to get the toolchain. You can also build it yourself (see the README for further details). 
  
Download the toolchain:  
```
wget https://github.com/Pro/raspi-toolchain/releases/latest/download/raspi-toolchain.tar.gz
```
Extract it. Note: The toolchain has to be in /opt/cross-pi-gcc since it's not location independent.
```
sudo tar xfz raspi-toolchain.tar.gz --strip-components=1 -C /opt
```
You are done! The toolchain is now in /opt/cross-pi-gcc. 
  
Optional, add the toolchain to your path, by adding:
```
export PATH=$PATH:/opt/cross-pi-gcc/bin
```
to the end of the file named ~/.bashrc. 
  
Now you can either log out and log back in (i.e. restart your terminal session), or run . ~/.bashrc in your terminal to pick up the PATH addition in your current terminal session.  
### Get the libraries from the Raspberry PI
To cross-compile for your own Raspberry Pi, which may have some custom libraries installed, you need to get these libraries onto your host.
  
Create a folder $HOME/raspberrypi. In your raspberrypi folder, make a folder called rootfs.
  
Now you need to copy the entire /lib and /usr directory to this newly created folder. I usually bring the rpi image up and copy it via rsync:
```
rsync -vR --progress -rl --delete-after --safe-links pi@192.168.1.PI:/{lib,usr,opt/vc/lib} $HOME/raspberrypi/rootfs
```
where 192.168.1.PI is replaced by the IP of your Raspberry Pi.
  
### Use CMake to compile your project
To tell CMake to take your own toolchain, you need to have a toolchain file which initializes the compiler settings.
  
Get this toolchain file from here: [https://github.com/Pro/raspi-toolchain/blob/master/Toolchain-rpi.cmake](https://github.com/Pro/raspi-toolchain/blob/master/Toolchain-rpi.cmake). 
  
Now you should be able to compile your cmake programs simply by adding this extra flag: -D CMAKE_TOOLCHAIN_FILE=$HOME/raspberrypi/pi.cmake and setting the correct environment variables:
```
export RASPBIAN_ROOTFS=$HOME/raspberry/rootfs
export PATH=/opt/cross-pi-gcc/bin:$PATH
export RASPBERRY_VERSION=1
cmake -DCMAKE_TOOLCHAIN_FILE=$HOME/raspberry/Toolchain-rpi.cmake ..
```
An example hello world is shown here: [https://github.com/Pro/raspi-toolchain/blob/master/build_hello_world.sh](https://github.com/Pro/raspi-toolchain/blob/master/build_hello_world.sh)



