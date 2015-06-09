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

#include "Vector4.h"

namespace LastStandEngine {
    namespace Maths {

        Vector4::Vector4(const float &x, const float &y, const float &z, const float &w) {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        Vector4 &Vector4::add(const Vector4 &other) {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;

            return *this;
        }

        Vector4 &Vector4::subtract(const Vector4 &other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;

            return *this;
        }

        Vector4 &Vector4::multiply(const Vector4 &other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            w *= other.w;

            return *this;
        }

        Vector4 &Vector4::divide(const Vector4 &other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            w /= other.w;

            return *this;
        }

        Vector4 operator+(Vector4 left, const Vector4 &right) {
            return left.add(right);
        }

        Vector4 operator-(Vector4 left, const Vector4 &right) {
            return left.subtract(right);
        }

        Vector4 operator*(Vector4 left, const Vector4 &right) {
            return left.multiply(right);
        }

        Vector4 operator/(Vector4 left, const Vector4 &right) {
            return left.divide(right);
        }

        Vector4 &Vector4::operator+=(const Vector4 &other) {
            return add(other);
        }

        Vector4 &Vector4::operator-=(const Vector4 &other) {
            return subtract(other);
        }

        Vector4 &Vector4::operator*=(const Vector4 &other) {
            return multiply(other);
        }

        Vector4 &Vector4::operator/=(const Vector4 &other) {
            return divide(other);
        }

        bool Vector4::operator==(const Vector4 &other) {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }

        bool Vector4::operator!=(const Vector4 &other) {
            return !(*this == other);
        }

        std::ostream &operator<<(std::ostream &stream, const Vector4 &vector) {
            stream << "Vector4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
            return stream;
        }

    }
}