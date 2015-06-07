#ifndef LAST_STAND_ENGINE_VECTOR2_H
#define LAST_STAND_ENGINE_VECTOR2_H

#include <vector>

/**
* A Coordinate Point on the screen that has two instance Variables (X & Y).
*/
class Vector2
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
    Vector2 (Vector2& copy);

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
    static Vector2 Clamp ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
     *
     * @param
     * @param
     *
     * @returns
     */
    static Vector2 Lerp ( const Vector2& vector2a, const Vector2& vector2b );

    bool operator==(const Vector2 &v) const;
    bool operator!=(const Vector2 &v) const;

    Vector2 operator-() const;
    Vector2 operator-(const Vector2 &v) const;
    Vector2 operator+(const Vector2 &v) const;
    Vector2 operator/(float divider) const;
    Vector2 operator*(float scaleFactor) const;

    Vector2& operator+=(const Vector2 &v);
    Vector2& operator-=(const Vector2 &v);
    Vector2& operator*=(float f);
    Vector2& operator/=(float f);

    typedef std::vector<Vector2> Vector2List;
};

#endif //LAST_STAND_ENGINE_VECTOR2_H