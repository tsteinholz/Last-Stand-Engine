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

#include <Math/Math.h>

namespace LSEngine
{
    namespace Math
    {
        const float Math::E = 2.718282f;

        const float Math::Log10E = 0.4342945f;

        const float Math::Log2E = 1.442695f;

        const float Math::Pi = 3.141593f;

        const float Math::MaxFloat = 3.402823E+38f;

        const float Math::MinFloat = -3.402823E+38f;

        const int   Math::MaxInt = 2147483647;

        const int   Math::MinInt = -2147483647;

        const float Math::Epsilon = 0.000001f;

        template<typename T>
        T Math::Abs(T val)
        {
            return val >= 0 ? val : -val;
        }

        template<typename T>
        T Math::Max(T value1, T value2)
        {
            return value1 > value2 ? value1 : value2;
        }

        template<typename T>
        T Math::Min(T value1, T value2)
        {
            return value1 < value2 ? value1 : value2;
        }

        template<typename T>
        T Math::Distance(T value1, T value2)
        {
            return Abs(value1 - value2);
        }

        template<typename T>
        T Math::Lerp(T value1, T value2, float amount)
        {
            return T(value1 + ((T) (value2 - value1) * amount));
        }

        template<typename T>
        T Math::SmoothStep(T value1, T value2, float amount)
        {
            float num = Clamp(amount, 0.0f, 1.0f);
            return Lerp(value1, value2, (num * num) * (3.0f - (2.0f * num)));
        }

        int Math::Clamp(int value, int min, int max)
        {
            return Max(min, Min(max, value));
        }

        float Math::Clamp(float value, float min, float max)
        {
            return Max(min, Min(max, value));
        }

        double Math::Clamp(double value, double min, double max)
        {
            return Max(min, Min(max, value));
        }

        // TODO : Function Implementation
        float Math::ToDegrees(float radians)
        {
            return 0;
        }

        // TODO : Function Implementation
        float Math::ToRadians(float degrees)
        {
            return 0;
        }

        // TODO : Function Implementation
        int Math::RoundInt(double x)
        {
            return 0;
        }

        // TODO : Function Implementation
        int Math::RandomInt(int maximum)
        {
            return rand() % maximum;
        }

        // TODO : Function Implementation
        int Math::RandomInt(int min, int max)
        {
            return rand() % (max-min) + min;
        }

        // TODO : Function Implementation
        float Math::RandomFloat(float maximum)
        {
            return 0;
        }

        // TODO : Function Implementation
        float Math::RandomFloat(float min, float max)
        {
            return 0;
        }

        // TODO : Function Implementation
        bool Math::RandomBool()
        {
            return (bool)(rand() % 2);
        }
    }
}