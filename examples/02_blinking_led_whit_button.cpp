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
 * g++ -o 02_blinking_led_whit_button 02_blinking_led_whit_button.cpp  -lwiringPi -lwiringPiDev -lpthread
 */

#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
using namespace std;

#include <wiringPi.h>

constexpr const int PIN_RED = 1;
constexpr const int PIN_BLUE = 16;
constexpr const int PIN_BUTTON = 0;
constexpr const uint16_t LED_TIME = 2000;
constexpr const uint16_t BUTTON_TIME = 100;

int main(int argc, char *argv[])
{
    volatile bool start = true;

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

    // set input form pin 8
    pinMode(PIN_BUTTON, INPUT);

    /* start new thread for retrive button action */
    thread t([&start]()
             {
                 uint8_t count = 0;
                 while (start)
                 {
                     //check button status if chlicker turn on blue led
                     this_thread::sleep_for(chrono::milliseconds(BUTTON_TIME));
                     int buttonValue = digitalRead(PIN_BUTTON);
                     digitalWrite(PIN_BLUE, buttonValue);
                     if (buttonValue)
                     {
                         count++;
                     }

                     //if click for 2 second the button exit from app
                     if (count == 20)
                     {
                         start = false;
                     }
                 }
             });
    t.detach();

    while (start)
    {

        digitalWrite(PIN_RED, LOW); //turn off

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));

        digitalWrite(PIN_RED, HIGH); //turn on

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));

        cout << digitalRead(PIN_BUTTON) << endl;
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