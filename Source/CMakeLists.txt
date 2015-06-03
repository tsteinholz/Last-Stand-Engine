cmake_minimum_required ( VERSION 3.2.3 )
project ( Last_Stand_Engine )

set ( Last_Stand_Engine_VERSION_MAJOR 0 )
set ( Last_Stand_Engine_VERSION_MINOR 0 )

set ( CMAKE_CURRENT_SOURCE_DIR ../Source )

set(SOURCE
   ${SOURCE}

   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Actor.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Camera.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Universe.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Vector2.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Vector3.cpp

   #PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}

   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Actor.h
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Camera.h
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Universe.h
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Vector2.h
   ${CMAKE_CURRENT_SOURCE_DIR}/Core/Vector3.h

   ${CMAKE_CURRENT_SOURCE_DIR}/Utils/EngineState.h

   #PARENT_SCOPE
)

add_library ( Last_Stand_Engine ${SOURCE} ${HEADERS} )
