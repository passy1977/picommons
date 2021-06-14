/*
    MIT License

    Copyright (c) 2021 Antonio Salsi

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

/**
 * g++ -o 01_blinking_led 01_blinking_led.cpp  -lwiringPi -lwiringPiDev -lpthread
 */

#include <iostream>
using namespace std;

#include <pigpio.h>

constexpr const int PIN_BLUE = 27;
constexpr const int PIN_RED = 22;
constexpr const uint16_t LED_TIME = 2000;

auto callback = [](int gpio, int level, uint32_t tick)
{ cout << (gpio == PIN_RED ? "Pin red " : "Pin blue ") << to_string(gpio) << " (" << to_string(level) << ")" << endl; };

int main(int argc, char *argv[])
{

    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

    /* Set GPIO modes */

    //set OUTPUT for pin 22
    gpioSetMode(PIN_BLUE, PI_OUTPUT);
    gpioSetAlertFunc(PIN_BLUE, callback);

    //set OUTPUT for pin 27
    gpioSetMode(PIN_RED, PI_OUTPUT);
    gpioSetAlertFunc(PIN_RED, callback);
    for (;;)
    {

        gpioWrite(PIN_BLUE, 1);
        gpioWrite(PIN_RED, 0);

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));

        gpioWrite(PIN_BLUE, 0);
        gpioWrite(PIN_RED, 1);

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));
    }

    /* Stop DMA, release resources */
    gpioTerminate();

    return 0;
}