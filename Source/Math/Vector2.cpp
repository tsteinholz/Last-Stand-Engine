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

#include <Math/Vector2.h>
#include <Math/Math.h>

namespace LSEngine
{

    namespace Math
    {
        Vector2 Vector2::Zero(0.0f, 0.0f);
        Vector2 Vector2::One(1.0f, 1.0f);
        Vector2 Vector2::UnitX(1.0f, 0.0f);
        Vector2 Vector2::UnitY(0.0f, 1.0f);

        Vector2::Vector2() : X(0), Y(0) { }

        Vector2::Vector2(float x, float y) : X(x), Y(y) { }

        Vector2::Vector2(float val) : X(val), Y(val) { }

        Vector2::Vector2(const Vector2 &copy) : X(copy.X), Y(copy.Y) { }

        float Vector2::Length()
        {
            return 0;
        }

        float Vector2::LengthSquared()
        {
            return (X * X) + (Y * Y);
        }

        float Vector2::Distance(const Vector2 &vector2a, const Vector2 &vector2b)
        {
            return Vector2(vector2a - vector2b).Length();
        }

        float Vector2::DistanceSquared(const Vector2 &vector2a, const Vector2 &vector2b)
        {
            return Vector2(vector2a - vector2b).LengthSquared();
        }

        float Vector2::Dot(const Vector2 &vector2a, const Vector2 &vector2b)
        {
            return (vector2a.X * vector2b.X) + (vector2a.Y * vector2b.Y);
        }

        float Vector2::Cross(const Vector2 &vector2a, Vector2 &vector2b)
        {
            return (vector2a.X * vector2b.Y) - (vector2a.Y * vector2b.X);
        }

        void Vector2::Normalize()
        {
            if (Length() < 1e-7f)
            {
                *this = Y > X ? UnitY : UnitX;
            }
            else
            {
                *this /= Length();
            }
        }

        Vector2 Vector2::Normalize(const Vector2 &vector2)
        {
            Vector2 temp(vector2);
            temp.Normalize();
            return temp;
        }

        Vector2 Vector2::Reflect(const Vector2 &a, const Vector2 &b)
        {
            return a - (b * 2.0f * Vector2::Dot(a, b));
        }

        Vector2 Vector2::Min(const Vector2 &vector2a, const Vector2 vector2b)
        {
            return Vector2(Math::Min(vector2a.X, vector2b.X), Math::Min(vector2a.Y, vector2b.Y));
        }

        Vector2 Vector2::Max(const Vector2 &vector2a, const Vector2 vector2b)
        {
            return Vector2(Math::Max(vector2a.X, vector2a.X), Math::Max(vector2b.Y, vector2b.Y));
        }

        Vector2 Vector2::Clamp(const Vector2 &value, const Vector2 &max, const Vector2 &min)
        {
            return Vector2(Math::Clamp(value.X, min.X, max.X), Math::Clamp(value.Y, min.Y, max.Y));
        }

        Vector2 Vector2::Lerp(const Vector2 &vector2a, const Vector2 &vector2b, float amount)
        {
            return Vector2(Math::Lerp(vector2a.X, vector2b.X, amount), Math::Lerp(vector2a.Y, vector2b.Y, amount));
        }

        bool Vector2::operator==(const Vector2 &v) const
        {
            return X == v.X && Y == v.Y;
        }

        bool Vector2::operator!=(const Vector2 &v) const
        {
            return !(*this == v);
        }

        Vector2 Vector2::operator-() const
        {
            return Vector2::Zero - *this;
        }

        Vector2 Vector2::operator-(const Vector2 &v) const
        {
            return Vector2(X - v.X, Y - v.Y);
        }

        Vector2 Vector2::operator+(const Vector2 &v) const
        {
            return Vector2(X + v.X, Y + v.Y);
        }

        Vector2 Vector2::operator/(float f) const
        {
            return Vector2(X / f, Y / f);
        }

        Vector2 Vector2::operator*(float f) const
        {
            return Vector2(X * f, Y * f);
        }

        Vector2 &Vector2::operator+=(const Vector2 &v)
        {
            X += v.X;
            Y += v.Y;
            return *this;
        }

        Vector2 &Vector2::operator-=(const Vector2 &v)
        {
            X -= v.X;
            Y -= v.Y;
            return *this;
        }

        Vector2 &Vector2::operator*=(float f)
        {
            X *= f;
            Y *= f;
            return *this;
        }

        Vector2 &Vector2::operator/=(float f)
        {
            X /= f;
            Y /= f;
            return *this;
        }
    }
}