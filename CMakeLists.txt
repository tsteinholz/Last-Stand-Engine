#/*/-----------------------------------------------------------------------------------------------------------------/*/
#/*/                                                                                                                 /*/
#/*/                                 ______________________________________                                          /*/
#/*/                        ________|                                      |_______                                  /*/
#/*/                        \       |     This file is a part of the       |      /                                  /*/
#/*/                         \      |    Last Stand Studio Game Engine     |     /                                   /*/
#/*/                         /      |______________________________________|     \                                   /*/
#/*/                        /__________)                                (_________\                                  /*/
#/*/                                                                                                                 /*/
#/*/                                     Copyright Last Stand Studio 2015                                            /*/
#/*/                                                                                                                 /*/
#/*/               The Last Stand Gaming Engine is free software: you can redistribute it and/or modify              /*/
#/*/               it under the terms of the GNU General Public License as published by                              /*/
#/*/               the Free Software Foundation, either version 3 of the License, or                                 /*/
#/*/               (at your option) any later version.                                                               /*/
#/*/                                                                                                                 /*/
#/*/               The Last Stand Gaming Engine is distributed in the hope that it will be useful,                   /*/
#/*/               but WITHOUT ANY WARRANTY; without even the implied warranty of                                    /*/
#/*/               MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                     /*/
#/*/               GNU General Public License for more details.                                                      /*/
#/*/                                                                                                                 /*/
#/*/               You should have received a copy of the GNU General Public License                                 /*/
#/*/               along with The Last Stand Gaming Engine. If not, see <http://www.gnu.org/licenses/>.              /*/
#/*/                                                                                                                 /*/
#/*/                                                                                                                 /*/
#/*/-----------------------------------------------------------------------------------------------------------------/*/

cmake_minimum_required ( VERSION 3.0 )
project ( Last_Stand_Engine )

set ( Last_Stand_Engine_VERSION_MAJOR 0 )
set ( Last_Stand_Engine_VERSION_MINOR 0 )

set ( SOURCE
    ${SOURCE}

    Source/main.cpp
    Source/Core/Audio/SoundManager.cpp
    Source/Core/Math/Math.cpp
    Source/Core/Math/Matrix.cpp
    Source/Core/Math/Plane.cpp
    Source/Core/Math/Quaternion.cpp
    Source/Core/Math/Vector2.cpp
    Source/Core/Math/Vector3.cpp
    Source/Core/Math/Vector4.cpp
    Source/Core/Graphics/Actors/OrthographicCamera.cpp
    Source/Core/Graphics/Actors/PerspectiveCamera.cpp
    Source/Core/Graphics/Actors/Actor2D.cpp
    Source/Core/Graphics/Actors/Actor3D.cpp
    Source/Core/Universe.cpp
    Source/Utils/Utils.cpp
)

set ( HEADERS
    ${HEADERS}

    Source/main.h
    Source/LSEngine.h
    Source/Core/Audio/SoundManager.h
    Source/Core/Math/Math.h
    Source/Core/Math/Matrix.h
    Source/Core/Math/Plane.h
    Source/Core/Math/Quaternion.h
    Source/Core/Math/Vector2.h
    Source/Core/Math/Vector3.h
    Source/Core/Math/Vector4.h
    Source/Core/Graphics/Actors/OrthographicCamera.h
    Source/Core/Graphics/Actors/PerspectiveCamera.h
    Source/Core/Graphics/Actors/Actor2D.h
    Source/Core/Graphics/Actors/Actor3D.h
    Source/Core/Graphics/Renderable2D.h
    Source/Core/Graphics/Renderable3D.h
    Source/Core/Universe.h
    Source/Utils/FileUtils.h
    Source/Utils/Log.h
    Source/Utils/StringUtils.h
    Source/Utils/Utils.h
)

add_library ( -LastStandEngine ${SOURCE} ${HEADERS} )
add_executable( LastStandEngineDemo ${SOURCE} ${HEADERS} )

include ( FindPkgConfig )
pkg_search_module ( SDL2 REQUIRED sdl2 )
include_directories ( ${SDL2_INCLUDE_DIRS} )
target_link_libraries ( -LastStandEngine ${SDL2_LIBRARIES})
target_link_libraries ( LastStandEngineDemo -LastStandEngine)
