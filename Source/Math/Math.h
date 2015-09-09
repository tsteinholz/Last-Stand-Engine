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

#ifndef LSENGINE_MATH_MATH_H
#define LSENGINE_MATH_MATH_H

#include "Vector2.h"

namespace LSEngine
{
    namespace Math
    {

        /**
        * A generic Math Class to make difficult equations easy with correctness and efficiency. The following class has
        * useful functions and constants you would find in your average graphing calculator. Except a little bit more
        * centered towards video-games and the math involved in making them work.
        */
        class Math
        {

        public:

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
            static T Abs(T val)
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
                return T(value1 + ((T) (value2 - value1) * amount));
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
            static int RandomInt(int maximum = 1);

            /**
             *
            */
            static int RandomInt(int min, int max);

            /**
             *
             */
            static float RandomFloat(float maximum = 1.0f);

            /**
            *
            */
            static float RandomFloat(float min, float max);

            /**
             *
            */
            static bool RandomBool();

        };
    }
}
#endif //LSENGINE_MATH_MATH_H
