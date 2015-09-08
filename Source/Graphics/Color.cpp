#include <Graphics/Color.h>

namespace LSEngine
{
    Color Color::Black(0, 0, 0);
    Color Color::Blue(0, 0, 255);
    Color Color::Cyan(0, 255, 0);
    Color Color::Green(0, 255, 0);
    Color Color::Magenta(255, 0, 255);
    Color Color::Red(255, 0, 0);
    Color Color::Yellow(225, 0, 255);
    Color Color::White(255, 255, 255);

    Color::Color() :
	    x_Red(255), x_Green(255), x_Blue(255), x_Alpha(255)
    {}

    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) 
    {
	    if (r > 255) x_Red = 255;
	    else if (r < 0) x_Red = 0;
	    else x_Red = r;

	    if (g > 255) x_Green = 255;
	    else if (g < 0) x_Green = 0;
	    else x_Green = g;

	    if (b > 255) x_Blue = 255;
	    else if (b < 0) x_Blue = 0;
	    else x_Blue = b;

	    if (a > 255) x_Alpha = 255;
	    else if (a < 0) x_Alpha = 0;
	    else x_Alpha = a;
    }

    Color::Color(int hex) :
	    x_Red((hex >> 16) & 0xFF),
	    x_Green((hex >> 8) & 0xFF),
	    x_Blue(hex & 0xFF),
	    x_Alpha(255)
    {}

    uint8_t Color::R()
    {
	    return x_Red;
    }

    uint8_t Color::G()
    {
	    return x_Green;
    }

    uint8_t Color::B()
    {
    	return x_Blue;
    }

    uint8_t Color::A()
    {
	    return x_Alpha;
    }

    Color::~Color() {}

    Color Color::operator+(const Color& color) const
    {
	    int tmp = 0;

	    uint8_t tmpR = 0;
	    tmp = this->x_Red + color.x_Red;
	    if (tmp > 255) tmpR = 255;
	    if (tmp < 0)   tmpR = 0;
        
	    uint8_t tmpG = 0;
	    tmp = this->x_Green + color.x_Green;
	    if (tmp > 255) tmpG = 255;
	    if (tmp < 0)   tmpG = 0;

	    uint8_t tmpB = 0;
	    tmp = this->x_Blue + color.x_Blue;
	    if (tmp > 255) tmpB = 255;
	    if (tmp < 0)   tmpB = 0;

	    uint8_t tmpA = 255;
	    if (this->x_Alpha == color.x_Alpha)
		    tmpA = this->x_Alpha;

	    Color result(tmpR, tmpG, tmpB, tmpA);
	    return result;
    }


    Color Color::operator-(const Color& color) const
    {
	    int tmp = 0;

	    uint8_t tmpR = 0;
	    tmp = this->x_Red - color.x_Red;
	    if (tmp > 255) tmpR = 255;
	    if (tmp < 0)   tmpR = 0;

	    uint8_t tmpG = 0;
	    tmp = this->x_Green - color.x_Green;
	    if (tmp > 255) tmpG = 255;
	    if (tmp < 0)   tmpG = 0;

	    uint8_t tmpB = 0;
	    tmp = this->x_Blue - color.x_Blue;
	    if (tmp > 255) tmpB = 255;
	    if (tmp < 0)   tmpB = 0;

	    uint8_t tmpA = 255;
	    if (this->x_Alpha == color.x_Alpha)
		    tmpA = this->x_Alpha;

	    Color result(tmpR, tmpG, tmpB, tmpA);
	    return result;
    }
    bool Color::operator==(const Color& color) const
    {
	    return ((this->x_Red == color.x_Red) &&
		    (this->x_Green == color.x_Green) &&
		    (this->x_Blue == color.x_Blue) &&
		    (this->x_Alpha == color.x_Alpha));
    }
    bool Color::operator!=(const Color& color) const
    {
	    return ((this->x_Red != color.x_Red) &&
		    (this->x_Green != color.x_Green) &&
		    (this->x_Blue != color.x_Blue) &&
	    	(this->x_Alpha != color.x_Alpha));
    }
}