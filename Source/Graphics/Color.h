/*/-----------------------------------------------------------------------------------------------------------------/*/
/*/                                                                                                                 /*/
/*/                                 ______________________________________                                          /*/
/*/                        ________|                                      |_______                                  /*/
/*/                        \       |     This file is a part of the       |      /                                  /*/
/*/                         \      |    Last Stand Studio Game Engine     |     /                                   /*/
/*/                         /      |______________________________________|     \                                   /*/
/*/                        /__________)                                (_________\                                  /*/
/*/                                                                                                                 /*/
/*/                                    Copyright Last Stand Studio 2015                                             /*/
/*/                                                                                                                 /*/
/*/                                          The MIT License (MIT)                                                  /*/
/*/                                                                                                                 /*/
/*/                   Permission is hereby granted, free of charge, to any person obtaining a copy                  /*/
/*/                   of this software and associated documentation files (the "Software"), to deal                 /*/
/*/                   in the Software without restriction, including without limitation the rights                  /*/
/*/                   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                     /*/
/*/                   copies of the Software, and to permit persons to whom the Software is                         /*/
/*/                   furnished to do so, subject to the following conditions:                                      /*/
/*/                                                                                                                 /*/
/*/                   The above copyright notice and this permission notice shall be included in                    /*/
/*/                   all copies or substantial portions of the Software.                                           /*/
/*/                                                                                                                 /*/
/*/                   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                    /*/
/*/                   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                      /*/
/*/                   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE                   /*/
/*/                   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                        /*/
/*/                   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,                 /*/
/*/                   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN                     /*/
/*/                   THE SOFTWARE.                                                                                 /*/
/*/                                                                                                                 /*/
/*/                                                                                                                 /*/
/*/-----------------------------------------------------------------------------------------------------------------/*/

#pragma once
#ifndef SOMNIA_ENGINE_GRAPHICS_COLOR_H
#define SOMNIA_ENGINE_GRAPHICS_COLOR_H

#include <stdint.h>

namespace LSEngine
{

    class Color
    {
    public:
	
	    Color();
	
	    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255);
	
	    Color(int hex);
    
    	~Color();

	    static Color Black;

	    static Color Blue;

	    static Color Cyan;

	    static Color Green;

	    static Color Magenta;

	    static Color Red;

	    static Color Yellow;

	    static Color White;

	    uint8_t R();

	    uint8_t G();

	    uint8_t B();

	    uint8_t A();

	    Color operator+(const Color& color) const;

	    Color operator-(const Color& color) const;

	    bool operator==(const Color& color) const;

	    bool operator!=(const Color& color) const;

    private:
	
	    uint8_t x_Red;
	    uint8_t x_Green;
	    uint8_t x_Blue;
	    uint8_t x_Alpha;

    };
}
#endif //SOMNIA_ENGINE_GRAPHICS_COLOR_H