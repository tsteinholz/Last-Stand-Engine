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

#ifndef LAST_STAND_ENGINE_LOG_H
#define LAST_STAND_ENGINE_LOG_H

#include <iostream>

class Log {
public:
    Log(const std::string &fName) {
        std::cout << fName << ": ";
    }

    template<class T>
    Log &operator<<(const T &a) {
        std::cout << a;
        return *this;
    }

    ~Log() {
        std::cout << " [eom]" << std::endl;
    }
};

#define EngineLog Log(__FUNCTION__)

#endif //LAST_STAND_ENGINE_LOG_H