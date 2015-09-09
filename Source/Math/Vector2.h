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

#ifndef SOMNIA_MATH_VECTOR2_H
#define SOMNIA_MATH_VECTOR2_H

#include <vector>

namespace LSEngine
{
    namespace Math
    {
        /**
        * A Coordinate Point on the screen that has two instance Variables (X & Y).
        */
        struct Vector2
        {
        public:

            /**
            * The X value value of the Vector2.
            */
            float X;

            /**
            * The Y value of the Vector2.
            */
            float Y;

            /**
            * Basic Constructor for a Vector2 object, sets values to 0,0.
            */
            Vector2();

            /**
            * Complete Constructor for a Vector2
            *
            * @param x : X value of the Vector2.
            * @param y : Y value of the Vector2.
            */
            Vector2(float x, float y);

            /**
            * Sets the x and y values to the same value.
            *
            * @param val : value going into both x and y.
            */
            Vector2(float val);

            /**
            * Copies a Vector2.
            *
            * @param copy : an exciting Vector2 with desired values.
            */
            Vector2(const Vector2 &copy);

            /**
            * Vector2 with the values (0,0).
            */
            static Vector2 Zero;

            /**
            * Vector2 with the values (1,1).
            */
            static Vector2 One;

            /**
            * Vector2 with the values (1,0).
            */
            static Vector2 UnitX;

            /**
            * Vector2 with the values (0,1).
            */
            static Vector2 UnitY;

            /**
            *
            *
            * @returns :
            */
            float Length();

            /**
            *
            *
            * @returns
            */
            float LengthSquared();

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static float Distance(const Vector2 &vector2a, const Vector2 &vector2b);

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static float DistanceSquared(const Vector2 &vector2a, const Vector2 &vector2b);

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static float Dot(const Vector2 &vector2a, const Vector2 &vector2b);

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static float Cross(const Vector2 &vector2a, Vector2 &vector2b);

            /**
            *
            *
            *  @returns
            */
            void Normalize();

            /**
            *
            *
            * @param
            *
            * @returns
            */
            static Vector2 Normalize(const Vector2 &vector2);

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static Vector2 Reflect(const Vector2 &a, const Vector2 &b);

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static Vector2 Min(const Vector2 &vector2a, const Vector2 vector2b);

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static Vector2 Max(const Vector2 &vector2a, const Vector2 vector2b);

            /**
            *
            *
            * @param
            * @param
            *
            * @returns
            */
            static Vector2 Clamp(const Vector2 &value, const Vector2 &max, const Vector2 &min);

            /**
            *
            *
            * @param
             * @param
             *
             * @returns
             */
            static Vector2 Lerp(const Vector2 &vector2a, const Vector2 &vector2b, float amount);

            bool operator==(const Vector2 &v) const;

            bool operator!=(const Vector2 &v) const;

            Vector2 operator-() const;

            Vector2 operator-(const Vector2 &v) const;

            Vector2 operator+(const Vector2 &v) const;

            Vector2 operator/(float f) const;

            Vector2 operator*(float f) const;

            Vector2 &operator+=(const Vector2 &v);

            Vector2 &operator-=(const Vector2 &v);

            Vector2 &operator*=(float f);

            Vector2 &operator/=(float f);

            typedef std::vector<Vector2> Vector2List;
        };
    }
}
#endif //SOMNIA_MATH_VECTOR2_H