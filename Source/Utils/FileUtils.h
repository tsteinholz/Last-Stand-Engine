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

//TODO change to ifndef
#pragma once

#include <string>
#include <fstream>

namespace LastStandEngine {
    namespace Utils {

        static std::string readFile(const char *filepath) {
            FILE *file = fopen(filepath, "rt");
            fseek(file, 0, SEEK_END);
            unsigned long len = ftell(file);
            char *data = new char[len + 1];
            memset(data, 0, len + 1);
            fseek(file, 0, SEEK_SET);
            fread(data, 1, len, file);
            fclose(file);


            std::string result(data);
            delete[] data;

            return result;
        }
    }
}