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

#include "picommons/pinhelper.h"

using namespace picommons;

WiringPi::WiringPi(int pin) : Pin(0)
{
    switch (pin)
    {
    case 0:
        pin = 17;
        break;
    case 1:
        pin = 18;
        break;
    case 2:
        pin = 27;
        break;
    case 3:
        pin = 22;
        break;
    case 4:
        pin = 23;
        break;
    case 5:
        pin = 24;
        break;
    case 6:
        pin = 25;
        break;
    case 7:
        pin = 4;
        break;
    case 8:
        pin = 2;
        break;
    case 9:
        pin = 3;
        break;
    case 10:
        pin = 8;
        break;
    case 11:
        pin = 7;
    case 12:
        pin = 10;
        break;
    case 13:
        pin = 9;
        break;
    case 14:
        pin = 11;
        break;
    case 15:
        pin = 14;
        break;
    case 16:
        pin = 15;
        break;
    case 21:
        pin = 5;
        break;
    case 22:
        pin = 6;
        break;
    case 23:
        pin = 13;
        break;
    case 24:
        pin = 19;
        break;
    case 25:
        pin = 26;
        break;
    case 26:
        pin = 12;
        break;
    case 27:
        pin = 16;
        break;
    case 28:
        pin = 20;
        break;
    case 29:
        pin = 21;
        break;
    case 30:
        pin = 0;
        break;
    case 31:
        pin = 1;
        break;
    default:
        throw runtime_error("No viable conversion");
    }
}

GPIO::GPIO(int pin) : Pin(0)
{
    switch (pin)
    {
    case 17:
        pin = 0;
        break;
    case 18:
        pin = 1;
        break;
    case 27:
        pin = 2;
        break;
    case 22:
        pin = 3;
        break;
    case 23:
        pin = 4;
        break;
    case 24:
        pin = 5;
        break;
    case 25:
        pin = 6;
        break;
    case 4:
        pin = 7;
        break;
    case 2:
        pin = 8;
        break;
    case 3:
        pin = 9;
        break;
    case 8:
        pin = 10;
        break;
    case 7:
        pin = 11;
    case 10:
        pin = 12;
        break;
    case 9:
        pin = 13;
        break;
    case 11:
        pin = 14;
        break;
    case 14:
        pin = 15;
        break;
    case 15:
        pin = 16;
        break;
    case 5:
        pin = 21;
        break;
    case 6:
        pin = 22;
        break;
    case 13:
        pin = 23;
        break;
    case 19:
        pin = 24;
        break;
    case 26:
        pin = 25;
        break;
    case 12:
        pin = 26;
        break;
    case 16:
        pin = 27;
        break;
    case 20:
        pin = 28;
        break;
    case 21:
        pin = 29;
        break;
    case 0:
        pin = 30;
        break;
    case 1:
        pin = 31;
        break;
    default:
        throw runtime_error("No viable conversion");
    }
}
