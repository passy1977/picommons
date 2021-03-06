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

#include "display.h"

namespace picommons
{
    inline namespace v1
    {
        /**
         * \brief LCD 16x02 implementation 4bit configuration
         */
        class LCD1602 final : public Display
        {
            void init(const vector<int> &) override;

            explicit LCD1602(const vector<int> &);
            explicit LCD1602(const vector<int> &&pins) : LCD1602(pins) {}

            //remove copy constructor
            LCD1602(const LCD1602 &) = delete;
            LCD1602 &operator=(const LCD1602 &) = delete;
            LCD1602(Display &&) = delete;
            LCD1602 &operator=(LCD1602 &&) = delete;

            friend Display::Ptr Display::factory(const Display::Type &&type, const vector<int> &&);
        };
    }
}