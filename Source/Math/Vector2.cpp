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

#include "Vector2.h"
#include "Math.h"

Vector2 Vector2::Zero  ( 0.0f, 0.0f );
Vector2 Vector2::One   ( 1.0f, 1.0f );
Vector2 Vector2::UnitX ( 1.0f, 0.0f );
Vector2 Vector2::UnitY ( 0.0f, 1.0f );

Vector2::Vector2 () : X(0), Y(0) {}
Vector2::Vector2 ( float x, float y ) : X(x), Y(y) {}
Vector2::Vector2 ( float val ) : X(val), Y(val) {}
Vector2::Vector2 ( const Vector2 &copy ) : X(copy.X), Y(copy.Y) {}

float Vector2::Length ()
{
    return 0;
}

float Vector2::LengthSquared ()
{
    return ( X * X ) + ( Y * Y );
}

float Vector2::Distance ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return Vector2 ( vector2a - vector2b ).Length ();
}

float Vector2::DistanceSquared ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return Vector2 ( vector2a - vector2b ).LengthSquared ();
}

float Vector2::Dot ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return ( vector2a.X * vector2b.X ) + ( vector2a.Y * vector2b.Y );
}

float Vector2::Cross ( const Vector2 &vector2a, Vector2 &vector2b )
{
    return ( vector2a.X * vector2b.Y ) - ( vector2a.Y * vector2b.X );
}

void Vector2::Normalize ()
{
    if( Length () < 1e-7f )
    {
        *this = Y > X ? UnitY : UnitX;
    }
    else
    {
        *this /= Length ();
    }
}

Vector2 Vector2::Normalize ( const Vector2 &vector2 )
{
    Vector2 temp (vector2);
    temp.Normalize();
    return temp;
}

Vector2 Vector2::Reflect ( const Vector2 &a, const Vector2 &b )
{
    return a - ( b * 2.0f * Vector2::Dot(a, b) );
}

Vector2 Vector2::Min ( const Vector2 &vector2a, const Vector2 vector2b )
{
    return Vector2 ( Math::Min ( vector2a.X, vector2b.X ), Math::Min ( vector2a.Y, vector2b.Y ) );
}

Vector2 Vector2::Max ( const Vector2 &vector2a, const Vector2 vector2b )
{
    return Vector2 ( Math::Max ( vector2a.X, vector2a.X ), Math::Max ( vector2b.Y, vector2b.Y ) );
}

Vector2 Vector2::Clamp ( const Vector2 &value, const Vector2 &max, const Vector2 &min )
{
    return Vector2 ( Math::Clamp ( value.X, min.X, max.X ), Math::Clamp ( value.Y, min.Y, max.Y ) );
}

Vector2 Vector2::Lerp ( const Vector2 &vector2a, const Vector2 &vector2b, float amount )
{
    return Vector2 ( Math::Lerp ( vector2a.X, vector2b.X, amount ), Math::Lerp ( vector2a.Y, vector2b.Y, amount ) );
}

bool Vector2::operator == ( const Vector2 &v ) const
{
    return X == v.X && Y == v.Y;
}

bool Vector2::operator != ( const Vector2 &v ) const
{
    return !(*this == v);
}

Vector2 Vector2::operator - () const
{
    return Vector2::Zero - *this;
}

Vector2 Vector2::operator - ( const Vector2 &v ) const
{
    return Vector2(X - v.X, Y - v.Y);
}

Vector2 Vector2::operator + ( const Vector2 &v ) const
{
    return Vector2(X + v.X, Y + v.Y);
}

Vector2 Vector2::operator / ( float f) const
{
    return Vector2(X / f, Y / f);
}

Vector2 Vector2::operator * ( float f) const
{
    return Vector2 ( X * f, Y * f);
}

Vector2& Vector2::operator += (const Vector2 &v)
{
    X += v.X;
    Y += v.Y;
    return *this;
}

Vector2& Vector2::operator -= ( const Vector2 &v )
{
    X -= v.X;
    Y -= v.Y;
    return *this;
}

Vector2& Vector2::operator *= ( float f )
{
    X *= f;
    Y *= f;
    return *this;
}

Vector2& Vector2::operator /= ( float f )
{
    X /= f;
    Y /= f;
    return *this;
}
