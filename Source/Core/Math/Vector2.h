#ifndef LAST_STAND_ENGINE_VECTOR2_H
#define LAST_STAND_ENGINE_VECTOR2_H

#include <bits/stl_bvector.h>

/**
 *
 */
class Vector2
{
public:

    /**
     *
     */
    Vector2 ();

    /**
     *
     */
    Vector2 ( float x, float y );

    /**
     *
     */
    Vector2 ( float val );

    /**
     *
     */
    Vector2 (Vector2& copy);

    /**
     *
     */
    float X;

    /**
     *
     */
    float Y;

    /**
     *
     */
    static Vector2 Zero;

    /**
     *
     */
    static Vector2 One;

    /**
     *
     */
    static Vector2 UnitX;

    /**
     *
     */
    static Vector2 UnitY;

    /**
     *
     */
    float Length ();

    /**
     *
     */
    float LengthSquared ();

    /**
     *
     */
    static float Distance ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
     */
    static float DistanceSquared ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
     */
    static float Dot ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
     */
    static float Cross ( const Vector2& vector2a, Vector2& vector2b );

    /**
     *
     */
    void Normalize ();

    /**
     *
     */
    static Vector2 Normalize ( const Vector2& vector2 );

    /**
     *
     */
    static Vector2 Reflect ( const Vector2&a, const Vector2&b );

    /**
     *
     */
    static Vector2 Min ( const Vector2& vector2a, const Vector2 vector2b );

    /**
     *
     */
    static Vector2 Max ( const Vector2& vector2a, const Vector2 vector2b );

    /**
     *
     */
    static Vector2 Clamp ( const Vector2& vector2a, const Vector2& vector2b );

    /**
     *
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