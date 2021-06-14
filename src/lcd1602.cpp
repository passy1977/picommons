/*
Copyright (c) 2021 Antonio Salsi

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include "picommons/lcd1602.h"

#include <wiringPi.h>
#include <lcd.h>

#include <stdexcept>
using std::runtime_error;

using picommons::LCD1602;

LCD1602::LCD1602(const vector<int> &&pins) : Display(2, 16)
{
    init(pins);
}

void LCD1602::init(const vector<int> &pins)
{
    if (pins.empty() || pins.size() < 4)
    {
        throw runtime_error("No set minimum pin id = 6");
    }

    handle = lcdInit(rows,
                     colls,
                     4,       //bits
                     pins[0], //LCD_RS
                     pins[1], //LCD_E
                     pins[2], //LCD_04
                     pins[3], //LCD_05
                     pins[4], //LCD_06
                     pins[5], //LCD_07
                     0, 0, 0, 0);

    if (handle == -1)
    {
        throw runtime_error("Init error");
    }
}