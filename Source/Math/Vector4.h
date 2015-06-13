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

#ifndef LAST_STAND_ENGINE_VECTOR4_H
#define LAST_STAND_ENGINE_VECTOR4_H

#include <iostream>

namespace LastStandEngine {
    namespace Maths {

        struct Vector4 {
            float x, y, z, w;

            Vector4() = default;

            Vector4(const float &x, const float &y, const float &z, const float &w);

            Vector4 &add(const Vector4 &other);

            Vector4 &subtract(const Vector4 &other);

            Vector4 &multiply(const Vector4 &other);

            Vector4 &divide(const Vector4 &other);

            friend Vector4 operator+(Vector4 left, const Vector4 &right);

            friend Vector4 operator-(Vector4 left, const Vector4 &right);

            friend Vector4 operator*(Vector4 left, const Vector4 &right);

            friend Vector4 operator/(Vector4 left, const Vector4 &right);

            bool operator==(const Vector4 &other);

            bool operator!=(const Vector4 &other);

            Vector4 &operator+=(const Vector4 &other);

            Vector4 &operator-=(const Vector4 &other);

            Vector4 &operator*=(const Vector4 &other);

            Vector4 &operator/=(const Vector4 &other);

            friend std::ostream &operator<<(std::ostream &stream, const Vector4 &vector);
        };
    }
}

#endif