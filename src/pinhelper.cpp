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

FromWiringPi::FromWiringPi(uint8_t wiringPiPin) : Pin(0)
{
    switch (wiringPiPin)
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
    case 17:
        pin = 15;
        break;

        //da finire
    default:
        throw runtime_error("No viable conversion");
    }
}
