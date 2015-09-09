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
#ifndef LSENGINE_MATH_MATH_H
#define LSENGINE_MATH_MATH_H

#include <stdlib.h>

#include <Math/Vector2.h>

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

            /**  */
            static const float E;

            /** */
            static const float Log10E;

            /** */
            static const float Log2E;

            /** */
            static const float Pi;

            /** */
            static const float MaxFloat;

            /** */
            static const float MinFloat;

            /** */
            static const int MaxInt;

            /** */
            static const int MinInt;

            /** */
            static const float Epsilon;

            /**
            *
            */
            template<typename T>
            static T Abs(T val);

            /**
            *
            */
            template<typename T>
            static T Max(T value1, T value2);

            /**
            *
            */
            template<typename T>
            static T Min(T value1, T value2);

            /**
            *
            */
            template<typename T>
            static T Distance(T value1, T value2);

            /**
            *
            */
            template<typename T>
            static T Lerp(T value1, T value2, float amount);


            /**
            *
            */
            template<typename T>
            static T SmoothStep(T value1, T value2, float amount);

            /**
            *
            */
            static int Clamp(int value, int min, int max);

            /**
            *
            */
            static float Clamp(float value, float min, float max);

            /**
            *
            */
            static double Clamp(double value, double min, double max);

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
