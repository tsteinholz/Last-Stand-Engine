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

#ifndef LAST_STAND_ENGINE_VECTOR2_H
#define LAST_STAND_ENGINE_VECTOR2_H

#include <vector>

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
    Vector2 ();

    /**
    * Complete Constructor for a Vector2
    *
    * @param x : X value of the Vector2.
    * @param y : Y value of the Vector2.
    */
    Vector2 ( float x, float y );

    /**
    * Sets the x and y values to the same value.
    *
    * @param val : value going into both x and y.
    */
    Vector2 ( float val );

    /**
    * Copies a Vector2.
    *
    * @param copy : an exciting Vector2 with desired values.
    */
    Vector2 ( const Vector2& copy );

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
    float Length ();

    /**
     *
     *
     * @returns
     */
    float LengthSquared ();

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static float Distance ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static float DistanceSquared ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static float Dot ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static float Cross ( const Vector2& vector2a, Vector2& vector2b );

    /**
     *
     *
     *  @returns
     */
    void Normalize ();

    /**
     *
     *
     * @param
     *
     * @returns
     */
    static Vector2 Normalize ( const Vector2& vector2 );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static Vector2 Reflect ( const Vector2&a, const Vector2&b );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static Vector2 Min ( const Vector2& vector2a, const Vector2 vector2b );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static Vector2 Max ( const Vector2& vector2a, const Vector2 vector2b );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static Vector2 Clamp ( const Vector2& value, const Vector2& max, const Vector2& min );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static Vector2 Lerp ( const Vector2& vector2a, const Vector2& vector2b, float amount );

    bool operator == ( const Vector2 &v ) const;
    bool operator != ( const Vector2 &v ) const;

    Vector2 operator - () const;
    Vector2 operator - ( const Vector2 &v ) const;
    Vector2 operator + ( const Vector2 &v ) const;
    Vector2 operator / ( float f ) const;
    Vector2 operator * ( float f ) const;

    Vector2& operator += ( const Vector2 &v );
    Vector2& operator -= ( const Vector2 &v );
    Vector2& operator *= ( float f );
    Vector2& operator /= ( float f );

    typedef std::vector<Vector2> Vector2List;
};

#endif //LAST_STAND_ENGINE_VECTOR2_H