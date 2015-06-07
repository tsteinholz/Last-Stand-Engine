# Build File for Last Stand Engine

cmake_minimum_required ( VERSION 3.0 )
project ( Last_Stand_Engine )

set ( Last_Stand_Engine_VERSION_MAJOR 0 )
set ( Last_Stand_Engine_VERSION_MINOR 0 )

set ( SOURCE
    ${SOURCE}

    Source/main.cpp
    Source/Core/Math/Vector2.cpp
    Source/Core/Math/Vector3.cpp
    Source/Core/Math/Vector4.cpp
    Source/Core/Camera/OrthographicCamera.cpp
    Source/Core/Camera/PerspectiveCamera.cpp
    Source/Core/Actor.cpp
    Source/Core/Universe.cpp
    Source/Utils/Utils.cpp
)

set ( HEADERS
    ${HEADERS}

    Source/main.h
    Source/LSEngine.h
    Source/Core/Math/Vector2.h
    Source/Core/Math/Vector3.h
    Source/Core/Math/Vector4.h
    Source/Core/Camera/OrthographicCamera.h
    Source/Core/Camera/PerspectiveCamera.h
    Source/Core/Actor.h
    Source/Core/Universe.h
    Source/Utils/FileUtils.h
    Source/Utils/StringUtils.h
    Source/Utils/Timer.h
    Source/Utils/Utils.h
)

add_library ( -LastStandEngine ${SOURCE} ${HEADERS} )
add_executable( LastStandEngineDemo ${SOURCE} ${HEADERS} )

include ( FindPkgConfig )
pkg_search_module ( SDL2 REQUIRED sdl2 )
include_directories ( ${SDL2_INCLUDE_DIRS} )
target_link_libraries ( -LastStandEngine ${SDL2_LIBRARIES})
target_link_libraries ( LastStandEngineDemo -LastStandEngine)
