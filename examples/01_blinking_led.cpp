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
#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
using namespace std;

#include <wiringPi.h>

constexpr const int PIN_RED = 1;
constexpr const int PIN_BLUE = 16;
constexpr const uint16_t LED_TIME = 2000;

int main(int argc, char *argv[])
{

    if (wiringPiSetup() == -1)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

    /* Set WiringPi modes */

    //set OUTPUT for pin 1
    pinMode(PIN_RED, OUTPUT);

    //set OUTPUT for pin 16
    pinMode(PIN_BLUE, OUTPUT);

    for (;;)
    {

        digitalWrite(PIN_BLUE, HIGH);
        digitalWrite(PIN_RED, LOW);
        cout << "BLUE" << endl;

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));

        digitalWrite(PIN_BLUE, LOW);
        digitalWrite(PIN_RED, HIGH);
        cout << "RED" << endl;

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));
    }

    /* Stop DMA, release resources */

    return 0;
}