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

#include <pigpio.h>

constexpr const uint8_t PIN_BLUE = 27;
constexpr const uint8_t PIN_RED = 22;
constexpr const uint8_t PIN_BUTTON = 2;
constexpr const uint16_t LED_TIME = 2000;
constexpr const uint16_t BUTTON_TIME = 100;

int main(int argc, char *argv[])
{
    volatile bool start = true;

    auto callback = [](int gpio, int level, uint32_t tick)
    {
        cout << (gpio == PIN_RED ? "Pin red " : "Pin blue ") << to_string(gpio) << " (" << to_string(level) << ")" << endl;
    };

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

    // set input form pin 2
    gpioSetMode(PIN_BUTTON, PI_INPUT);

    /* start new thread for retrive button action */
    thread t([&start]()
             {
                 uint8_t count = 0;
                 while (start)
                 {
                     //check button status if chlicker turn on blue led
                     this_thread::sleep_for(chrono::milliseconds(BUTTON_TIME));
                     int buttonValue = !gpioRead(PIN_BUTTON);
                     gpioWrite(PIN_BLUE, buttonValue);
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

        gpioWrite(PIN_RED, 0); //turn off

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));

        gpioWrite(PIN_RED, 1); //turn on

        this_thread::sleep_for(chrono::milliseconds(LED_TIME));
    }

    //before exit blink led for 4 time
    for (uint8_t i = 0; i < 4; i++)
    {
        gpioWrite(PIN_RED, 0);
        gpioWrite(PIN_BLUE, 0);
        this_thread::sleep_for(chrono::milliseconds(BUTTON_TIME));
        gpioWrite(PIN_RED, 1);
        gpioWrite(PIN_BLUE, 1);
        this_thread::sleep_for(chrono::milliseconds(BUTTON_TIME));
    }

    gpioWrite(PIN_RED, 0);
    gpioWrite(PIN_BLUE, 0);

    /* Stop DMA, release resources */
    gpioTerminate();

    cout << "bye" << endl;

    return 0;
}