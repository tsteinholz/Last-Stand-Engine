#*/-----------------------------------------------------------------------------------------------------------------/*#
#*/                                                                                                                 /*#
#*/                                 ______________________________________                                          /*#
#*/                        ________|                                      |_______                                  /*#
#*/                        \       |     This file is a part of the       |      /                                  /*#
#*/                         \      |    Last Stand Studio Game Engine     |     /                                   /*#
#*/                         /      |______________________________________|     \                                   /*#
#*/                        /__________)                                (_________\                                  /*#
#*/                                                                                                                 /*#
#*/                                     Copyright Last Stand Studio 2015                                            /*#
#*/                                                                                                                 /*#
#*/               The Last Stand Gaming Engine is free software: you can redistribute it and/or modify              /*#
#*/               it under the terms of the GNU General Public License as published by                              /*#
#*/               the Free Software Foundation, either version 3 of the License, or                                 /*#
#*/               (at your option) any later version.                                                               /*#
#*/                                                                                                                 /*#
#*/               The Last Stand Gaming Engine is distributed in the hope that it will be useful,                   /*#
#*/               but WITHOUT ANY WARRANTY; without even the implied warranty of                                    /*#
#*/               MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                     /*#
#*/               GNU General Public License for more details.                                                      /*#
#*/                                                                                                                 /*#
#*/               You should have received a copy of the GNU General Public License                                 /*#
#*/               along with The Last Stand Gaming Engine. If not, see <http://www.gnu.org/licenses/>.              /*#
#*/                                                                                                                 /*#
#*/                                                                                                                 /*#
#*/-----------------------------------------------------------------------------------------------------------------/*#

cmake_minimum_required ( VERSION 3.0 )
project ( Last_Stand_Engine )

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

set ( Last_Stand_Engine_VERSION_MAJOR 0 )
set ( Last_Stand_Engine_VERSION_MINOR 0 )

set ( SOURCE
    ${SOURCE}

    Source/main.cpp
    Source/Audio/AudioManager.cpp
    Source/DataStructures/AssetManager.cpp
    Source/Core/Universe.cpp
    Source/Core/Manager.cpp
    Source/Graphics/Actors/OrthographicCamera.cpp
    Source/Graphics/Actors/PerspectiveCamera.cpp
    Source/Graphics/Actors/Actor2D.cpp
    Source/Graphics/Actors/Actor3D.cpp
    Source/Input/InputManager.cpp
    Source/Math/Math.cpp
    Source/Math/Matrix.cpp
    Source/Math/Plane.cpp
    Source/Math/Quaternion.cpp
    Source/Math/Vector2.cpp
    Source/Math/Vector3.cpp
    Source/Math/Vector4.cpp
    Source/Networking/NetworkManager.cpp
    Source/Utils/Utils.cpp
)

set ( HEADERS
    ${HEADERS}

    Source/main.h
    Source/LSEngine.h
    Source/Audio/AudioManager.h
    Source/DataStructures/AssetManager.h
    Source/Core/Universe.h
    Source/Core/Manager.h
    Source/Graphics/Actors/OrthographicCamera.h
    Source/Graphics/Actors/PerspectiveCamera.h
    Source/Graphics/Actors/Actor2D.h
    Source/Graphics/Actors/Actor3D.h
    Source/Graphics/Renderable2D.h
    Source/Graphics/Renderable3D.h
    Source/Input/InputManager.cpp
    Source/Math/Math.h
    Source/Math/Matrix.h
    Source/Math/Plane.h
    Source/Math/Quaternion.h
    Source/Math/Vector2.h
    Source/Math/Vector3.h
    Source/Math/Vector4.h
    Source/Networking/NetworkManager.cpp

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
