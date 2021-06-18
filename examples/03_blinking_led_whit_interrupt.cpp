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

/*
 * g++ -o 03_blinking_led_whit_interrupt 03_blinking_led_whit_interrupt.cpp  -lwiringPi -lwiringPiDev -lpthread
 */

#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
using namespace std;

#include <wiringPi.h>

//set WiringPi pin number
static constexpr const int PIN_RED = 1;
static constexpr const int PIN_BLUE = 16;
static constexpr const int PIN_BUTTON = 0;
static constexpr const uint16_t LED_TIME = 2000;
static constexpr const uint16_t BUTTON_TIME = 100;

static bool buttonValue = true;
static bool buttonValueCheck = false;

int main(int argc, char *argv[])
{
    static bool start = true;

    if (wiringPiSetup() == -1)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

    /* Set GPIO modes */

    //set OUTPUT for pin 16
    pinMode(PIN_BLUE, OUTPUT);

    //set OUTPUT for pin 1
    pinMode(PIN_RED, OUTPUT);

    // set input form pin 0
    pinMode(PIN_BUTTON, INPUT);

    wiringPiISR(PIN_BUTTON, INT_EDGE_BOTH, []()
                {
                    //check button status if chlicker turn on blue led
                    buttonValue = digitalRead(PIN_BUTTON);

                    digitalWrite(PIN_BLUE, buttonValue);
                });

    while (start)
    {

        digitalWrite(PIN_RED, LOW); //turn off

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));

        digitalWrite(PIN_RED, HIGH); //turn on

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));

        if (buttonValue)
        {
            if (buttonValueCheck)
            {
                buttonValue = false;
            }
            else
            {
                buttonValueCheck = true;
            }
        }
        else
        {
            buttonValueCheck = false;
        }
    }

    //before exit blink led for 4 time
    for (uint8_t i = 0; i < 4; i++)
    {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_BLUE, LOW);
        this_thread::sleep_for(chrono::milliseconds(BUTTON_TIME));
        digitalWrite(PIN_RED, HIGH);
        digitalWrite(PIN_BLUE, HIGH);
        this_thread::sleep_for(chrono::milliseconds(BUTTON_TIME));
    }

    digitalWrite(PIN_RED, LOW);
    digitalWrite(PIN_BLUE, LOW);

    cout << "bye" << endl;

    return 0;
}
