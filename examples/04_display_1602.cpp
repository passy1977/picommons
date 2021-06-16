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
 * g++ -o 04_display_1602 04_display_1602.cpp  -I../include -L../build -lwiringPi -lwiringPiDev -lpthread -lpicommons
 */

#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
using namespace std;

#include <wiringPi.h>

#include <string>
using std::string;

#include <picommons/display.h>
using namespace picommons;

//USE WIRINGPI PIN NUMBERS
static constexpr const int LCD_RS = 25; //Register select pin
static constexpr const int LCD_E = 24;  //Enable Pin
static constexpr const int LCD_D4 = 23; //Data pin 4
static constexpr const int LCD_D5 = 22; //Data pin 5
static constexpr const int LCD_D6 = 21; //Data pin 6
static constexpr const int LCD_D7 = 14; //Data pin 7
static constexpr const uint8_t TICK = 200;

static constexpr const char msg[] = " Hi I'm Antonio     bye  bye";

int main(int argc, char *argv[])
{
    int lcd;
    wiringPiSetup();

    auto &&display = Display::factory(Display::Type::LCD1602, {LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7});

    for (;;)
    {
        display->print("");

        const char *p = &msg[0];
        while (*p)
        {
            display->print(*p);
            p++;

            this_thread::sleep_for(chrono::milliseconds(TICK));
        }

        this_thread::sleep_for(chrono::milliseconds(TICK));

        for (int i = 0; i < 4; i++)
        {
            display->clear();

            display->print("");

            this_thread::sleep_for(chrono::milliseconds(TICK));

            display->print(msg);

            this_thread::sleep_for(chrono::milliseconds(TICK));
        }

        display->clear();

        display->print("");
    }
}