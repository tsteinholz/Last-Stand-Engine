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