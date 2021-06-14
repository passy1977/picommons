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

#pragma once

#include <string>
#include <vector>

namespace picommons
{

    using std::string;
    using std::vector;

    class Display
    {

    protected:
        int handle;

        uint16_t rows;
        uint16_t colls;

        inline Display(uint16_t rows, uint16_t colls) noexcept : rows(rows), colls(colls) {}

        virtual void init(const vector<int> &) = 0;

    public:
        inline virtual void print(const string &&str) noexcept
        {
            print(str);
        }

        virtual void print(const string &) noexcept;
        virtual void printf(const string &, ...) noexcept;
        virtual void print(const uint8_t) noexcept;
        virtual void home() noexcept;
        virtual void clear() noexcept;
        virtual void position(int x, int y) noexcept;
        virtual void display(int state) noexcept;
        virtual void cursor(int state) noexcept;
        virtual void cursorBlink(int state) noexcept;
        virtual void lcdSendCommand(uint8_t command) noexcept;
        virtual void charDef(int index, uint8_t data[8]) noexcept;
    };

}