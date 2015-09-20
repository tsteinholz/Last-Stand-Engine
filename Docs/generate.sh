set CXX_FLAGS -fPIC  -std=c++11 -g  -shared -Wl,-soname,libLSEngine.so -o libLSEngine.so

set CLDOC_FLAGS --output out --basedir ../Source --merge . --report 

set PROJ_SRC Public/LSEngine.h /
	../Source/Public/Engine.h /
	../Source/Public/Core/Component.h /
	../Source/Public/Core/Entity.h /
	../Source/Public/Graphics/Color.h /
	../Source/Public/Graphics/Window.h /
	../Source/Public/Networking/Packets/Packet.h /
	../Source/Public/Networking/Server.h /
	../Source/Public/Utils/Settings.h /
	../Source/Private/Engine.cpp /
	../Source/Private/Graphics/Color.cpp /
	../Source/Private/Graphics/Window.cpp /
	../Source/Private/Networking/Packets/Packet.cpp /
	../Source/Private/Networking/Server.cpp /
	../Source/Private/Utils/Settings.cpp

cldoc generate CXX_FLAGS -- CLDOC_FLAGS PROJ_SRC


