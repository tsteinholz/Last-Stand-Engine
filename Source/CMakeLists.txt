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

cmake_minimum_required(VERSION 3.2)
project(LSEngine)

include(CPack)
include(FindPkgConfig)
include(GenerateExportHeader)
include(InstallRequiredSystemLibraries)

set(LSEngine_MAJOR_VERSION 0)
set(LSEngine_MINOR_VERSION 0)
set(LSEngine_PATCH_VERSION 3)
set(LSEngine_VERSION ${LSEngine_MAJOR_VERSION}.${LSEngine_MINOR_VERSION}.${LSEngine_PATCH_VERSION})

set(CMAKE_VERBOSE_MAKEFILE 0)

if (MINGW AND WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x600")
endif (MINGW AND WIN32)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # TODO : Change Build Server to C++14
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(SOURCE_FILES

# Public Source Files
        Public/LSEngine.h
        Public/Engine.h

        Public/Core/Component.h
        Public/Core/Entity.h

        Public/Graphics/Color.h
        Public/Graphics/Window.h

        Public/Networking/Packets/Packet.h
        Public/Networking/Server.h

#Private Source Files
        Private/Engine.cpp

        Private/Graphics/Color.cpp
        Private/Graphics/Window.cpp

        Private/Networking/Packets/Packet.cpp
        Private/Networking/Server.cpp

        Private/Utils/Settings.cpp
)

add_library(LSEngine SHARED ${SOURCE_FILES})
generate_export_header(LSEngine
        BASE_NAME LSEngine
        EXPORT_MACRO_NAME LSEngine_EXPORT
        EXPORT_FILE_NAME LSEngine_Export.h
)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/../LSEngineLicense.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${LSEngine_MAJOR_VERSION}")
set(CPACK_PACKAGE_VERSION_MINOR "${LSEngine_MINOR_VERSION}")

pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2NET REQUIRED SDL2_net>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

find_package(FFMPEG)
if (FFMPEG_FOUND)
    set(LSENGINE_LIBRARIES ${LSENGINE_LIBRARIES} ${FFMPEG_LIBRARIES})
    set(LSENGINE_INCLUDE_DIR ${LSENGINE_INCLUDE_DIR} ${FFMPEG_INCLUDE_DIR})
endif (FFMPEG_FOUND)

find_package(Lua)
if (LUA_FOUND)
    set(LSENGINE_LIBRARIES ${LSENGINE_LIBRARIES} ${LUA_LIBRARIES})
    set(LSENGINE_INCLUDE_DIR ${LSENGINE_INCLUDE_DIR} ${LUA_INCLUDE_DIR})
endif (LUA_FOUND)

find_package(Steamworks)
if (STEAMWORKS_FOUND)
    set(LSENGINE_LIBRARIES ${LSENGINE_LIBRARIES} ${STEAMWORKS_LIBRARY})
    set(LSENGINE_INCLUDE_DIR ${LSENGINE_INCLUDE_DIR} ${STEAMWORKS_INCLUDE_DIR})
endif (STEAMWORKS_FOUND)

set(LSENGINE_INCLUDE_DIR
        Public
        Public/Utils/spdlog
        ${SDL2_INCLUDE_DIR}
        ${SDL2IMAGE_INCLUDE_DIR}
        ${SDL2NET_INCLUDE_DIR}
        ${SDL2MIXER_INCLUDE_DIR}
        ${SDL2TTF_INCLUDE_DIR}
)

set(LSENGINE_LIBRARIES
        ${SDL2_LIBRARIES}
        ${SDL2IMAGE_LIBRARIES}
        ${SDL2NET_LIBRARIES}
        ${SDL2MIXER_LIBRARIES}
        ${SDL2TTF_LIBRARIES}
)

include_directories(${LSENGINE_INCLUDE_DIR})
target_link_libraries(LSEngine ${LSENGINE_LIBRARIES})
