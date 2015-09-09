##/-----------------------------------------------------------------------------------------------------------------/##
##/                                                                                                                 /##
##/                                 ______________________________________                                          /##
##/                        ________|                                      |_______                                  /##
##/                        \       |     This file is a part of the       |      /                                  /##
##/                         \      |    Last Stand Studio Game Engine     |     /                                   /##
##/                         /      |______________________________________|     \                                   /##
##/                        /__________)                                (_________\                                  /##
##/                                                                                                                 /##
##/                                    Copyright Last Stand Studio 2015                                             /##
##/                                                                                                                 /##
##/                                          The MIT License (MIT)                                                  /##
##/                                                                                                                 /##
##/                   Permission is hereby granted, free of charge, to any person obtaining a copy                  /##
##/                   of this software and associated documentation files (the "Software"), to deal                 /##
##/                   in the Software without restriction, including without limitation the rights                  /##
##/                   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                     /##
##/                   copies of the Software, and to permit persons to whom the Software is                         /##
##/                   furnished to do so, subject to the following conditions:                                      /##
##/                                                                                                                 /##
##/                   The above copyright notice and this permission notice shall be included in                    /##
##/                   all copies or substantial portions of the Software.                                           /##
##/                                                                                                                 /##
##/                   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                    /##
##/                   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                      /##
##/                   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE                   /##
##/                   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                        /##
##/                   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,                 /##
##/                   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN                     /##
##/                   THE SOFTWARE.                                                                                 /##
##/                                                                                                                 /##
##/                                                                                                                 /##
##/-----------------------------------------------------------------------------------------------------------------/##

# -m32 for x86 bit compile

cmake_minimum_required(VERSION 3.3)
project(LSEngine)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(SOURCE_FILES

        LSEngine.h
        Engine.cpp
        Engine.h

        Core/Component.h
        Core/Entity.h

        Graphics/Color.h
        Graphics/Color.cpp
        Graphics/Window.h
        Graphics/Window.cpp

        Math/Math.h
        Math/Math.cpp
        Math/Vector2.h
        Math/Vector2.cpp
        Math/Vector3.h
        Math/Vector3.cpp

        Networking/Packets/Packet.h
        Networking/Packets/Packet.cpp
        Networking/Server.h
        Networking/Server.cpp
)

add_library(LSEngine ${SOURCE_FILES})

include_directories(${CMAKE_SOURCE_DIR} ../Include)

########################################################################################################################
# Link Libraries                                                                                                       #
########################################################################################################################

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2NET REQUIRED SDL2_net>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

#find_package(FFMPEG)
find_package(Lua)
#find_package(Steamworks)

target_link_libraries(LSEngine
#        ${FFMPEG_LIBRARIES}
        ${LUA_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${SDL2IMAGE_LIBRARIES}
        ${SDL2NET_LIBRARIES}
        ${SDL2MIXER_LIBRARIES}
        ${SDL2TTF_LIBRARIES}
#        ${STEAMWORKS_LIBRARY}
)

if (WIN32) # Windows

elseif(UNIX AND NOT APPLE) # Linux

elseif(APPLE) # OSX

endif ()