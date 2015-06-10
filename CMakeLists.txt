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

#Compile for C++11
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

#Set the current engine version
set ( Last_Stand_Engine_VERSION_MAJOR 0 )
set ( Last_Stand_Engine_VERSION_MINOR 0 )

#TODO Organize source code list in alpha order. (after v1 release)

# All of the source code in the project (that will be compiled)
set (LS_SOURCE_CODE

    Source/LSEngine.h

    ######### - Classes - #########
    Source/main.cpp
    Source/main.h

    Source/Audio/AudioManager.cpp
    Source/Audio/AudioManager.h

    Source/Core/Universe.cpp
    Source/Core/Universe.h

    Source/Core/Manager.cpp
    Source/Core/Manager.h

    Source/Graphics/Actors/OrthographicCamera.cpp
    Source/Graphics/Actors/OrthographicCamera.h

    Source/Graphics/Actors/PerspectiveCamera.cpp
    Source/Graphics/Actors/PerspectiveCamera.h

    Source/Graphics/Actors/Actor2D.cpp
    Source/Graphics/Actors/Actor2D.h

    Source/Graphics/Actors/Actor3D.cpp
    Source/Graphics/Actors/Actor3D.h

    Source/Input/InputManager.cpp
    Source/Input/InputManager.h

    Source/Math/Math.cpp
    Source/Math/Math.h

    Source/Math/Matrix.cpp
    Source/Math/Matrix.h

    Source/Math/Plane.cpp
    Source/Math/Plane.h

    Source/Math/Quaternion.cpp
    Source/Math/Quaternion.h

    Source/Math/Vector2.cpp
    Source/Math/Vector2.h

    Source/Math/Vector3.cpp
    Source/Math/Vector3.h

    Source/Math/Vector4.cpp
    Source/Math/Vector4.h

    Source/Networking/NetworkManager.cpp
    Source/Networking/NetworkManager.cpp

    Source/Utils/Utils.h
    Source/Utils/Utils.cpp

    Source/Files/File.cpp
    Source/Files/File.h
    ######### - Headers - #########

    Source/Utils/FileUtils.h
    Source/Utils/Log.h
    Source/Utils/StringUtils.h

    ######### - Interfaces - #########
    Source/Graphics/IRenderable3D.h
    Source/Graphics/IRenderable2D.h
    Source/Core/IManages.h
)

# What will be included in client projects
add_library ( -LastStandEngine ${LS_SOURCE_CODE} )
# Used to test build
add_executable( LastStandEngineDemo ${LS_SOURCE_CODE} )

# Includes SDL2
include ( FindPkgConfig )
pkg_search_module ( SDL2 REQUIRED sdl2 )
include_directories ( ${SDL2_INCLUDE_DIRS} )
# Includes SDL2 with the build files
target_link_libraries ( -LastStandEngine ${SDL2_LIBRARIES})
target_link_libraries ( LastStandEngineDemo -LastStandEngine)
