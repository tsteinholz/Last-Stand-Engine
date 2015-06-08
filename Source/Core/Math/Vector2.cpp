/** This file is part of the Last Stand Gaming Engine.
 *
 *   The Last Stand Gaming Engine is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   The Last Stand Gaming Engine is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with The Last Stand Gaming Engine.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "Vector2.h"

Vector2::Vector2() : X(0), Y(0)
{}

Vector2::Vector2 ( float x, float y ) : X(x), Y(y)
{}

Vector2::Vector2 ( float val ) : X(val), Y(val)
{}

Vector2::Vector2 ( Vector2 &copy ) : X(copy.X), Y(copy.Y)
{}

float Vector2::Length ()
{
    return 0;
}

float Vector2::LengthSquared ()
{
    return 0;
}

float Vector2::Distance ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return 0;
}

float Vector2::DistanceSquared ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return 0;
}

float Vector2::Dot ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return 0;
}

float Vector2::Cross ( const Vector2 &vector2a, Vector2 &vector2b )
{
    return 0;
}

void Vector2::Normalize ()
{

}

Vector2 Vector2::Normalize ( const Vector2 &vector2 )
{
    return Vector2();
}

Vector2 Vector2::Reflect ( const Vector2 &a, const Vector2 &b )
{
    return Vector2();
}

Vector2 Vector2::Min ( const Vector2 &vector2a, const Vector2 vector2b )
{
    return Vector2();
}

Vector2 Vector2::Max ( const Vector2 &vector2a, const Vector2 vector2b )
{
    return Vector2();
}

Vector2 Vector2::Clamp ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return Vector2();
}

Vector2 Vector2::Lerp ( const Vector2 &vector2a, const Vector2 &vector2b )
{
    return Vector2();
}

bool Vector2::operator == ( const Vector2 &v ) const
{
    return false;
}

bool Vector2::operator != ( const Vector2 &v ) const
{
    return false;
}

Vector2 Vector2::operator - () const
{
    return Vector2();
}

Vector2 Vector2::operator - ( const Vector2 &v ) const
{
    return Vector2();
}

Vector2 Vector2::operator + ( const Vector2 &v ) const
{
    return Vector2();
}

Vector2 Vector2::operator / ( float divider ) const
{
    return Vector2();
}

Vector2 Vector2::operator * ( float scaleFactor ) const
{
    return Vector2();
}

Vector2 &Vector2::operator += (const Vector2 &v)
{
    return <#initializer#>;
}

Vector2 &Vector2::operator -= ( const Vector2 &v )
{
    return <#initializer#>;
}

Vector2 &Vector2::operator *= ( float f )
{
    return <#initializer#>;
}

Vector2 &Vector2::operator /= ( float f )
{
    return <#initializer#>;
}
