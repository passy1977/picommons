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

#include "picommons/display.h"

#include <lcd.h>

#include <cstdarg>

using picommons::Display;

void Display::print(const string &msg) noexcept
{
    lcdPuts(handle, msg.c_str());
}

void Display::printf(const string &message, ...) noexcept
{
    va_list(args);
    va_start(args, message);
    lcdPrintf(handle, message.c_str(), args);
}

void Display::print(const uint8_t c) noexcept
{
    lcdPutchar(handle, c);
}

void Display::home() noexcept
{
    lcdHome(handle);
}

void Display::clear() noexcept
{
    lcdClear(handle);
}

void Display::position(int x, int y) noexcept
{
    lcdPosition(handle, x, y);
}

void Display::display(int state) noexcept
{
    lcdDisplay(handle, state);
}

void Display::cursor(int state) noexcept
{
    lcdCursor(handle, state);
}

void Display::cursorBlink(int state) noexcept
{
    lcdCursorBlink(handle, state);
}

void Display::lcdSendCommand(uint8_t command) noexcept
{
    lcdCursorBlink(handle, command);
}
void Display::charDef(int index, uint8_t data[8]) noexcept
{
    lcdCharDef(handle, index, data);
}