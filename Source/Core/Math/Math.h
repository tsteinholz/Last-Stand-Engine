/*/-----------------------------------------------------------------------------------------------------------------/*/
/*/                                                                                                                 /*/
/*/                                 ______________________________________                                          /*/
/*/                        ________|                                      |_______                                  /*/
/*/                        \       |     This file is a part of the       |      /                                  /*/
/*/                         \      |    Last Stand Studio Game Engine     |     /                                   /*/
/*/                         /      |______________________________________|     \                                   /*/
/*/                        /__________)                                (_________\                                  /*/
/*/                                                                                                                 /*/
/*/                                     Copyright Last Stand Studio 2015                                            /*/
/*/                                                                                                                 /*/
/*/               The Last Stand Gaming Engine is free software: you can redistribute it and/or modify              /*/
/*/               it under the terms of the GNU General Public License as published by                              /*/
/*/               the Free Software Foundation, either version 3 of the License, or                                 /*/
/*/               (at your option) any later version.                                                               /*/
/*/                                                                                                                 /*/
/*/               The Last Stand Gaming Engine is distributed in the hope that it will be useful,                   /*/
/*/               but WITHOUT ANY WARRANTY; without even the implied warranty of                                    /*/
/*/               MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                     /*/
/*/               GNU General Public License for more details.                                                      /*/
/*/                                                                                                                 /*/
/*/               You should have received a copy of the GNU General Public License                                 /*/
/*/               along with The Last Stand Gaming Engine. If not, see <http://www.gnu.org/licenses/>.              /*/
/*/                                                                                                                 /*/
/*/                                                                                                                 /*/
/*/-----------------------------------------------------------------------------------------------------------------/*/

#ifndef LAST_STAND_ENGINE_MATH_H
#define LAST_STAND_ENGINE_MATH_H

#include "Vector2.h"

/**
 * A generic Math Class to make difficult equations easy with correctness and efficiency. The following class has
 * useful functions and constants you would find in your average graphing calculator. Except a little bit more
 * centered towards video-games and the math involved in making them work.
 */
class Math
{
    /**
     *
     */
    static const float E;

    /**
     *
     */
    static const float Log10E;

    /**
     *
     */
    static const float Log2E;

    /**
     *
     */
    static const float Pi;

    /**
     *
     */
    static const float TwoPi;

    /**
     *
     */
    static const float MaxFloat;

    /**
     *
     */
    static const float MinFloat;

    /**
     *
     */
    static const int MaxInt;

    /**
     *
     */
    static const int MinInt;

    /**
     *
     */
    static const float Epsilon;

    /**
     *
     */
    template<typename T>
    static T Abs(T val )
    {
        return val >= 0 ? val : -val;
    }

    /**
     *
     */
    template<typename T>
    static T Max(T value1, T value2)
    {
        return value1 > value2 ? value1 : value2;
    }

    /**
     *
     */
    template<typename T>
    static T Min(T value1, T value2)
    {
        return value1 < value2 ? value1 : value2;
    }

    /**
     *
     */
    template<typename T>
    static T Distance(T value1, T value2)
    {
        return Abs(value1 - value2);
    }

    /**
     *
     */
    template<typename T>
    static T Lerp(T value1, T value2, float amount)
    {
        return T(value1 + ((T)(value2 - value1) * amount ));
    }

    /**
     *
     */
    template<typename T>
    static T SmoothStep(T value1, T value2, float amount)
    {
        float num = Clamp(amount, 0.0f, 1.0f);
        return Lerp(value1, value2, (num * num) * (3.0f - (2.0f * num)));
    }

    /**
     *
     */
    static int Clamp(int value, int min, int max)
    {
        return Max(min, Min(max, value));
    }

    /**
     *
     */
    static float Clamp(float value, float min, float max)
    {
        return Max(min, Min(max, value));
    }

    /**
     *
     */
    static double Clamp(double value, double min, double max)
    {
        return Max(min, Min(max, value));
    }

    /**
     *
     */
    static float ToDegrees(float radians);

    /**
     *
     */
    static float ToRadians(float degrees);

    /**
     *
     */
    static int RoundInt(double x);

    /**
     *
     */
    static int RandomInt(int maximum);

    /**
     *
     */
    static int RandomInt(int min, int max);

    /**
     *
     */
    static int RandomIntWithError(int target, int error);

    /**
     *
     */
    static float RandomFloat(float maximum=1.0f);

    /**
     *
     */
    static float RandomFloatInRange(float min, float max);

    /**
     *
     */
    static float RandomFloatWithError(float target, float error);

    /**
     *
     */
    static bool RandomBool();

    };

#endif //LAST_STAND_ENGINE_MATH_H
