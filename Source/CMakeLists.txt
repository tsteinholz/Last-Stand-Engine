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

set(LSEngine)

set(LSEngine_MAJOR_VERSION 0)
set(LSEngine_MINOR_VERSION 0)
set(LSEngine_PATCH_VERSION 2)
set(LSEngine_VERSION ${LSEngine_MAJOR_VERSION}.${LSEngine_MINOR_VERSION}.${LSEngine_PATCH_VERSION})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(LSEngine_Build_Dir ${CMAKE_SOURCE_DIR}../Build/)

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("64 bit compiler detected!")
    set(EX_PLATFORM 64)
    set(EX_PLATFORM_NAME "x64")
else (CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("32 bit compiler detected!")
    set(EX_PLATFORM 32)
    set(EX_PLATFORM_NAME "x86")
endif (CMAKE_SIZEOF_VOID_P EQUAL 8)

set(SOURCE_FILES

        # Public Source Files
        Public/LSEngine.h
        Public/Engine.h

        Public/Core/Component.h
        Public/Core/Entity.h

        Public/Graphics/Color.h
        Public/Graphics/Window.h

        Public/Math/Math.h
        Public/Math/Vector2.h
        Public/Math/Vector3.h

        Public/Networking/Packets/Packet.h
        Public/Networking/Server.h


        #Private Source Files
        Private/Engine.cpp

        Private/Graphics/Color.cpp
        Private/Graphics/Window.cpp

        Private/Math/Math.cpp
        Private/Math/Vector2.cpp
        Private/Math/Vector3.cpp

        Private/Networking/Packets/Packet.cpp
        Private/Networking/Server.cpp
)

if (EX_PLATFORM EQUAL 64)
    message ("Outputting to lib64 and bin64")

    set (CMAKE_LIBRARY_OUTPUT_DIRECTORY
            ${LSEngine_Build_Dir}/lib64
            CACHE PATH
            "Single Directory for all Libraries"
    )

    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY
            ${LSEngine_Build_Dir}/bin64
            CACHE PATH
            "Single Directory for all Executables."
    )

    set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
            ${LSEngine_Build_Dir}/lib64
            CACHE PATH
            "Single Directory for all static libraries."
    )
else (EX_PLATFORM EQUAL 64)

    set (CMAKE_LIBRARY_OUTPUT_DIRECTORY
            ${LSEngine_Build_Dir}/lib
            CACHE PATH
            "Single Directory for all Libraries"
    )

    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY
            ${LSEngine_Build_Dir}/bin
            CACHE PATH
            "Single Directory for all Executables."
    )

    set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
            ${LSEngine_Build_Dir}/lib
            CACHE PATH
            "Single Directory for all static libraries."
    )
endif (EX_PLATFORM EQUAL 64)

add_library(LSEngine ${SOURCE_FILES})

include_directories(Public)

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
